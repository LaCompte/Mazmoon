# La Compte Arabic Script Editor

## Project Overview
An ultra-lightweight office suite specialized for Arabic script languages (Arabic, Urdu, Farsi, Malayalam).

## Quick Start

### 1. Analyze InPage Fonts
```bash
cd tools
python3 font_analyzer.py ../assets/fonts/inpage/
```

### 2. Map Keyboard Layout  
```bash
python3 keyboard_mapper.py
```

### 3. Build Proof of Concept
```bash
cd src/rtl-poc
qmake && make
./urdu-renderer
```

## Directory Structure
- `assets/fonts/` - Font files for analysis
- `analysis/` - Analysis results and reports
- `src/` - Source code
- `tools/` - Analysis and development tools
- `docs/` - Documentation

## Next Steps
1. Copy InPage 2014 font files to `assets/fonts/inpage/`
2. Copy screenshots to `analysis/screenshots/`
3. Run font analysis
4. Document keyboard mapping
5. Build and test the RTL proof of concept
