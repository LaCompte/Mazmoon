#!/usr/bin/env python3
"""
La Compte Arabic Script Editor - Local Font Analyzer
Analyzes InPage fonts for OpenType features, character coverage, and Urdu support
"""

import os
import sys
import json
from datetime import datetime
import argparse

try:
    from fontTools.ttLib import TTFont
except ImportError:
    print("❌ Error: fonttools not installed")
    print("Install with: pip3 install --user fonttools")
    print("Or: sudo apt install python3-fonttools")
    sys.exit(1)

class LaCompteFontAnalyzer:
    def __init__(self, output_dir="analysis/fonts"):
        self.output_dir = output_dir
        os.makedirs(output_dir, exist_ok=True)
        
        # Arabic Unicode ranges
        self.arabic_ranges = {
            'Arabic Basic': (0x0600, 0x06FF),
            'Arabic Supplement': (0x0750, 0x077F),
            'Arabic Extended-A': (0x08A0, 0x08FF),
            'Arabic Presentation Forms-A': (0xFB50, 0xFDFF),
            'Arabic Presentation Forms-B': (0xFE70, 0xFEFF)
        }
        
        # Essential Urdu characters
        self.urdu_essential = {
            0x0627: 'ALIF',
            0x0628: 'BEH', 
            0x067E: 'PEH',
            0x062A: 'TEH',
            0x0679: 'TTEH',
            0x062C: 'JEEM',
            0x0686: 'TCHEH',
            0x062D: 'HAH',
            0x062E: 'KHAH',
            0x062F: 'DAL',
            0x0688: 'DDAL',
            0x0631: 'REH',
            0x0691: 'RREH',
            0x0632: 'ZAIN',
            0x0698: 'JEH',
            0x0633: 'SEEN',
            0x0634: 'SHEEN',
            0x0639: 'AIN',
            0x0641: 'FEH',
            0x0642: 'QAF',
            0x06A9: 'KEHEH',
            0x06AF: 'GAF',
            0x0644: 'LAM',
            0x0645: 'MEEM',
            0x0646: 'NOON',
            0x0648: 'WAW',
            0x06C1: 'HEH GOAL',
            0x06CC: 'FARSI YEH',
            0x06D2: 'YEH BARREE'
        }
        
        # OpenType feature descriptions
        self.feature_descriptions = {
            'init': 'Initial forms (beginning of word)',
            'medi': 'Medial forms (middle of word)', 
            'fina': 'Final forms (end of word)',
            'isol': 'Isolated forms (standalone)',
            'rlig': 'Required ligatures',
            'liga': 'Standard ligatures',
            'calt': 'Contextual alternates',
            'kern': 'Kerning',
            'mark': 'Mark positioning',
            'mkmk': 'Mark-to-mark positioning',
            'curs': 'Cursive positioning'
        }

    def analyze_font(self, font_path):
        """Comprehensive analysis of a font file"""
        
        font_name = os.path.basename(font_path)
        print(f"\n{'='*80}")
        print(f"🔍 ANALYZING: {font_name}")
        print(f"{'='*80}")
        
        try:
            font = TTFont(font_path)
            
            analysis = {
                "metadata": {
                    "font_name": font_name,
                    "file_path": font_path,
                    "file_size": os.path.getsize(font_path),
                    "analysis_date": datetime.now().isoformat(),
                    "analyzer_version": "La Compte v1.0"
                },
                "tables": list(font.keys()),
                "character_coverage": {},
                "urdu_support": {},
                "opentype_features": {},
                "ligatures": {},
                "recommendations": []
            }
            
            # Basic font info
            self._print_basic_info(font, analysis)
            
            # Character coverage analysis
            self._analyze_character_coverage(font, analysis)
            
            # Urdu-specific analysis
            self._analyze_urdu_support(font, analysis)
            
            # OpenType features
            self._analyze_opentype_features(font, analysis)
            
            # Ligature analysis
            self._analyze_ligatures(font, analysis)
            
            # Generate recommendations
            self._generate_recommendations(analysis)
            
            # Save results
            self._save_analysis(analysis)
            
            return analysis
            
        except Exception as e:
            print(f"❌ ERROR analyzing {font_name}: {str(e)}")
            return None
    
    def _print_basic_info(self, font, analysis):
        """Print basic font information"""
        
        print(f"📄 Basic Information:")
        print(f"   • File size: {analysis['metadata']['file_size']:,} bytes")
        print(f"   • Tables: {len(analysis['tables'])}")
        print(f"   • Available tables: {', '.join(analysis['tables'][:10])}")
        if len(analysis['tables']) > 10:
            print(f"     ... and {len(analysis['tables']) - 10} more")
    
    def _analyze_character_coverage(self, font, analysis):
        """Analyze character coverage across Arabic ranges"""
        
        print(f"\n📝 Character Coverage Analysis:")
        
        if 'cmap' not in font:
            print("   ❌ No character map found")
            return
            
        cmap = font.getBestCmap()
        total_chars = len(cmap)
        
        coverage = {}
        for range_name, (start, end) in self.arabic_ranges.items():
            chars_in_range = [c for c in cmap.keys() if start <= c <= end]
            total_possible = end - start + 1
            percentage = (len(chars_in_range) / total_possible) * 100
            
            coverage[range_name] = {
                "count": len(chars_in_range),
                "total_possible": total_possible,
                "percentage": percentage,
                "characters": chars_in_range
            }
            
            if len(chars_in_range) > 0:
                print(f"   ✅ {range_name}: {len(chars_in_range)}/{total_possible} chars ({percentage:.1f}%)")
            else:
                print(f"   ❌ {range_name}: No characters found")
        
        analysis["character_coverage"] = {
            "total_characters": total_chars,
            "arabic_ranges": coverage
        }
        
        print(f"   📊 Total characters in font: {total_chars:,}")
    
    def _analyze_urdu_support(self, font, analysis):
        """Analyze specific Urdu character support"""
        
        print(f"\n🇵🇰 Urdu Language Support:")
        
        if 'cmap' not in font:
            return
            
        cmap = font.getBestCmap()
        urdu_support = {}
        supported_count = 0
        
        print("   Essential Urdu Characters:")
        for unicode_point, char_name in self.urdu_essential.items():
            is_supported = unicode_point in cmap
            glyph_name = cmap.get(unicode_point, "Not found")
            
            urdu_support[char_name] = {
                "unicode": f"U+{unicode_point:04X}",
                "character": chr(unicode_point),
                "supported": is_supported,
                "glyph_name": glyph_name if is_supported else None
            }
            
            status = "✅" if is_supported else "❌"
            char_display = chr(unicode_point) if is_supported else "?"
            print(f"     {status} {char_name} ({char_display}) - U+{unicode_point:04X}")
            
            if is_supported:
                supported_count += 1
        
        coverage_percentage = (supported_count / len(self.urdu_essential)) * 100
        
        print(f"\n   📊 Urdu Support Summary:")
        print(f"     • Characters supported: {supported_count}/{len(self.urdu_essential)}")
        print(f"     • Coverage percentage: {coverage_percentage:.1f}%")
        
        if coverage_percentage >= 95:
            rating = "🌟 EXCELLENT"
        elif coverage_percentage >= 80:
            rating = "👍 GOOD"
        elif coverage_percentage >= 60:
            rating = "⚠️ FAIR"
        else:
            rating = "❌ POOR"
            
        print(f"     • Urdu support rating: {rating}")
        
        analysis["urdu_support"] = {
            "coverage_percentage": coverage_percentage,
            "supported_characters": supported_count,
            "total_essential_characters": len(self.urdu_essential),
            "character_details": urdu_support,
            "rating": rating
        }
    
    def _analyze_opentype_features(self, font, analysis):
        """Analyze OpenType features for Arabic text shaping"""
        
        print(f"\n🔧 OpenType Features Analysis:")
        
        features = {}
        
        # Check GSUB (Glyph Substitution) table
        if 'GSUB' in font:
            print("   📋 GSUB Features (Character Substitution):")
            gsub = font['GSUB']
            if hasattr(gsub.table, 'FeatureList'):
                for i, feature_record in enumerate(gsub.table.FeatureList.FeatureRecord):
                    tag = feature_record.FeatureTag
                    description = self.feature_descriptions.get(tag, f"Feature {tag}")
                    
                    features[tag] = {
                        "type": "GSUB",
                        "description": description,
                        "critical": tag in ['init', 'medi', 'fina', 'rlig']
                    }
                    
                    critical_marker = "🔥" if features[tag]["critical"] else "  "
                    print(f"     {critical_marker} {tag}: {description}")
        
        # Check GPOS (Glyph Positioning) table
        if 'GPOS' in font:
            print("   📐 GPOS Features (Character Positioning):")
            gpos = font['GPOS']
            if hasattr(gpos.table, 'FeatureList'):
                for i, feature_record in enumerate(gpos.table.FeatureList.FeatureRecord):
                    tag = feature_record.FeatureTag
                    if tag not in features:  # Avoid duplicates
                        description = self.feature_descriptions.get(tag, f"Feature {tag}")
                        
                        features[tag] = {
                            "type": "GPOS",
                            "description": description,
                            "critical": tag in ['mark', 'mkmk', 'curs']
                        }
                        
                        critical_marker = "🔥" if features[tag]["critical"] else "  "
                        print(f"     {critical_marker} {tag}: {description}")
        
        # Check for critical Arabic features
        critical_features = ['init', 'medi', 'fina', 'rlig']
        missing_critical = [f for f in critical_features if f not in features]
        
        if missing_critical:
            print(f"\n   ⚠️ Missing Critical Features: {', '.join(missing_critical)}")
            print("     These features are essential for proper Arabic text rendering")
        else:
            print(f"\n   ✅ All critical Arabic features present!")
        
        analysis["opentype_features"] = {
            "features": features,
            "missing_critical": missing_critical,
            "has_all_critical": len(missing_critical) == 0
        }
    
    def _analyze_ligatures(self, font, analysis):
        """Analyze ligature support"""
        
        print(f"\n🔗 Ligature Analysis:")
        
        if 'cmap' not in font:
            return
            
        cmap = font.getBestCmap()
        
        # Check Arabic Presentation Forms ranges
        pres_a_ligatures = [c for c in cmap.keys() if 0xFB50 <= c <= 0xFDFF]
        pres_b_ligatures = [c for c in cmap.keys() if 0xFE70 <= c <= 0xFEFF]
        
        total_ligatures = len(pres_a_ligatures) + len(pres_b_ligatures)
        
        print(f"   • Presentation Forms-A: {len(pres_a_ligatures)} characters")
        print(f"   • Presentation Forms-B: {len(pres_b_ligatures)} characters")
        print(f"   • Total ligature forms: {total_ligatures}")
        
        # Check for important Urdu ligatures
        important_ligatures = {
            0xFEDF: "LAM-ALIF",
            0xFEE0: "LAM-ALIF (isolated)",
            0xFC60: "BEH-HEH"
        }
        
        found_ligatures = {}
        for unicode_point, name in important_ligatures.items():
            if unicode_point in cmap:
                found_ligatures[name] = f"U+{unicode_point:04X}"
                print(f"   ✅ {name}: {chr(unicode_point)}")
            else:
                print(f"   ❌ {name}: Not found")
        
        ligature_quality = "Good" if total_ligatures > 100 else "Basic" if total_ligatures > 50 else "Limited"
        
        analysis["ligatures"] = {
            "total_count": total_ligatures,
            "presentation_a_count": len(pres_a_ligatures),
            "presentation_b_count": len(pres_b_ligatures),
            "important_ligatures": found_ligatures,
            "quality": ligature_quality
        }
        
        print(f"   📊 Ligature support quality: {ligature_quality}")
    
    def _generate_recommendations(self, analysis):
        """Generate recommendations based on analysis"""
        
        recommendations = []
        
        # Check Urdu support
        urdu_coverage = analysis["urdu_support"]["coverage_percentage"]
        if urdu_coverage < 80:
            recommendations.append({
                "type": "critical",
                "issue": "Low Urdu character support",
                "recommendation": f"Only {urdu_coverage:.1f}% of essential Urdu characters supported. Consider using a different font or supplementing missing characters."
            })
        
        # Check OpenType features
        if not analysis["opentype_features"]["has_all_critical"]:
            missing = analysis["opentype_features"]["missing_critical"]
            recommendations.append({
                "type": "important",
                "issue": "Missing critical OpenType features",
                "recommendation": f"Missing features: {', '.join(missing)}. These are essential for proper Arabic text shaping."
            })
        
        # Check ligature support
        if analysis["ligatures"]["total_count"] < 50:
            recommendations.append({
                "type": "improvement",
                "issue": "Limited ligature support",
                "recommendation": "Consider using a font with more comprehensive ligature support for better text aesthetics."
            })
        
        analysis["recommendations"] = recommendations
        
        if recommendations:
            print(f"\n💡 Recommendations:")
            for rec in recommendations:
                icon = "🔥" if rec["type"] == "critical" else "⚠️" if rec["type"] == "important" else "💡"
                print(f"   {icon} {rec['issue']}")
                print(f"      → {rec['recommendation']}")
    
    def _save_analysis(self, analysis):
        """Save analysis results to files"""
        
        font_name = analysis["metadata"]["font_name"]
        base_name = font_name.replace('.', '_').replace(' ', '_')
        
        # Save detailed JSON
        json_path = os.path.join(self.output_dir, f"{base_name}_analysis.json")
        with open(json_path, 'w', encoding='utf-8') as f:
            json.dump(analysis, f, ensure_ascii=False, indent=2)
        
        # Save human-readable report
        report_path = os.path.join(self.output_dir, f"{base_name}_report.txt")
        with open(report_path, 'w', encoding='utf-8') as f:
            self._write_text_report(f, analysis)
        
        print(f"\n💾 Analysis saved:")
        print(f"   • Detailed JSON: {json_path}")
        print(f"   • Human report: {report_path}")
    
    def _write_text_report(self, f, analysis):
        """Write human-readable text report"""
        
        f.write(f"La Compte Font Analysis Report\n")
        f.write(f"={'=' * 50}\n\n")
        
        # Basic info
        f.write(f"Font: {analysis['metadata']['font_name']}\n")
        f.write(f"File: {analysis['metadata']['file_path']}\n")
        f.write(f"Size: {analysis['metadata']['file_size']:,} bytes\n")
        f.write(f"Analyzed: {analysis['metadata']['analysis_date']}\n\n")
        
        # Urdu support summary
        urdu = analysis['urdu_support']
        f.write(f"Urdu Language Support\n")
        f.write(f"-" * 25 + "\n")
        f.write(f"Coverage: {urdu['coverage_percentage']:.1f}%\n")
        f.write(f"Rating: {urdu['rating']}\n")
        f.write(f"Supported: {urdu['supported_characters']}/{urdu['total_essential_characters']} essential characters\n\n")
        
        # OpenType features
        f.write(f"OpenType Features\n")
        f.write(f"-" * 20 + "\n")
        for feature, info in analysis['opentype_features']['features'].items():
            f.write(f"{feature}: {info['description']} ({'Critical' if info['critical'] else 'Optional'})\n")
        f.write(f"\n")
        
        # Recommendations
        if analysis['recommendations']:
            f.write(f"Recommendations\n")
            f.write(f"-" * 15 + "\n")
            for rec in analysis['recommendations']:
                f.write(f"• {rec['issue']}\n")
                f.write(f"  → {rec['recommendation']}\n\n")


def main():
    parser = argparse.ArgumentParser(description='Analyze InPage fonts for La Compte Editor')
    parser.add_argument('path', help='Font file or directory to analyze')
    parser.add_argument('--output', '-o', default='analysis/fonts', help='Output directory for results')
    parser.add_argument('--verbose', '-v', action='store_true', help='Verbose output')
    
    args = parser.parse_args()
    
    analyzer = LaCompteFontAnalyzer(args.output)
    
    print("🔍 La Compte Font Analyzer")
    print("=" * 50)
    
    if os.path.isfile(args.path):
        # Single font file
        result = analyzer.analyze_font(args.path)
        if result:
            print(f"\n✅ Analysis complete for {os.path.basename(args.path)}")
    
    elif os.path.isdir(args.path):
        # Directory of fonts
        font_extensions = ['.ttf', '.otf', '.TTF', '.OTF']
        font_files = []
        
        for ext in font_extensions:
            font_files.extend([f for f in os.listdir(args.path) if f.endswith(ext)])
        
        if not font_files:
            print(f"❌ No font files found in {args.path}")
            return
        
        print(f"Found {len(font_files)} font files to analyze\n")
        
        results = []
        for i, font_file in enumerate(font_files, 1):
            print(f"\n[{i}/{len(font_files)}] Processing {font_file}...")
            font_path = os.path.join(args.path, font_file)
            result = analyzer.analyze_font(font_path)
            if result:
                results.append(result)
        
        # Generate summary report
        if results:
            print(f"\n{'='*80}")
            print(f"📊 ANALYSIS SUMMARY")
            print(f"{'='*80}")
            print(f"Total fonts analyzed: {len(results)}")
            
            # Urdu support summary
            excellent = sum(1 for r in results if r['urdu_support']['coverage_percentage'] >= 95)
            good = sum(1 for r in results if 80 <= r['urdu_support']['coverage_percentage'] < 95)
            fair = sum(1 for r in results if 60 <= r['urdu_support']['coverage_percentage'] < 80)
            poor = sum(1 for r in results if r['urdu_support']['coverage_percentage'] < 60)
            
            print(f"\nUrdu Support Quality:")
            print(f"  🌟 Excellent (≥95%): {excellent} fonts")
            print(f"  👍 Good (80-94%): {good} fonts")
            print(f"  ⚠️ Fair (60-79%): {fair} fonts")
            print(f"  ❌ Poor (<60%): {poor} fonts")
            
            # OpenType features
            with_all_features = sum(1 for r in results if r['opentype_features']['has_all_critical'])
            print(f"\nOpenType Features:")
            print(f"  ✅ Complete feature set: {with_all_features} fonts")
            print(f"  ⚠️ Missing features: {len(results) - with_all_features} fonts")
            
            # Best fonts for Urdu
            print(f"\n🏆 Best Fonts for Urdu:")
            best_fonts = sorted(results, key=lambda x: x['urdu_support']['coverage_percentage'], reverse=True)[:3]
            for i, font in enumerate(best_fonts, 1):
                print(f"  {i}. {font['metadata']['font_name']} ({font['urdu_support']['coverage_percentage']:.1f}%)")
    
    else:
        print(f"❌ Error: {args.path} is not a valid file or directory")


if __name__ == "__main__":
    main()
