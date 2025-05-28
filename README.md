# Mazmoon - La Compte Arabic and Urdu Script Editor and Office Suite

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Python 3.8+](https://img.shields.io/badge/python-3.8+-blue.svg)](https://www.python.org/downloads/)
[![Qt5](https://img.shields.io/badge/Qt-5.12+-green.svg)](https://qt.io/)
[![Build Status](https://img.shields.io/badge/build-in%20progress-yellow.svg)]()

A modern, Unicode-based office suite specialized for Arabic script languages (Arabic, Urdu, Farsi, Malayalam). Built with performance, usability, and cross-platform compatibility in mind.

## Features

### Core Capabilities
- **Native RTL Support** - Proper right-to-left text flow and cursor behavior
- **Unicode Compliance** - Standard UTF-8 text storage for universal compatibility
- **Cross-Platform** - Runs on Linux, Windows 7+
- **Lightning Fast** - Sub-2-second startup, 60fps text rendering
- **Professional UI** - MS Office-inspired ribbon interface

### Text Processing
- **Advanced Typography** - HarfBuzz text shaping for beautiful Arabic rendering
- **Smart Keyboards** - Phonetic input methods familiar to Arabic script users
- **Intelligent Cursor** - Context-aware navigation in bidirectional text
- **Font Management** - Support for system Arabic fonts with OpenType features

### Document Features
- **Modern File Format** - JSON-based documents with Unicode text storage
- **Export Compatibility** - DOCX, PDF, and HTML export capabilities
- **Template System** - Pre-designed layouts for common document types
- **Find & Replace** - Arabic script-aware search functionality

## Quick Start

### Prerequisites
- Python 3.8 or higher
- Qt 5.12 or higher
- HarfBuzz library for text shaping

### Installation

```bash
# Clone the repository
git clone https://github.com/lacompte/arabic-script-editor.git
cd arabic-script-editor

# Install dependencies
pip install -r requirements.txt

# Run the application
python src/main.py
```

### For Development
```bash
# Install development dependencies
pip install -r requirements-dev.txt

# Run tests
python -m pytest tests/

# Run with debug mode
python src/main.py --debug
```

## Project Goals

### Primary Objectives
1. **Modernize Arabic Text Editing** - Replace legacy proprietary solutions with open standards
2. **Unicode-First Architecture** - Ensure cross-platform text compatibility
3. **Performance Excellence** - Deliver professional-grade speed and responsiveness
4. **User Experience** - Maintain familiarity while adding modern features

### Innovation Focus
- **Research-Driven Development** - Based on comprehensive Arabic script analysis
- **Standards Compliance** - Full Unicode and OpenType specification adherence
- **Community Building** - Open source collaboration for Arabic typography

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                    User Interface Layer                     │
│  (Qt-based Ribbon UI, RTL-optimized layout)                │
└─────────────────────┬───────────────────────────────────────┘
┌─────────────────────▼───────────────────────────────────────┐
│                 Text Processing Engine                      │
│  (Unicode handling, RTL algorithms, keyboard mapping)      │
└─────────────────────┬───────────────────────────────────────┘
┌─────────────────────▼───────────────────────────────────────┐
│                 Rendering Pipeline                          │
│  (HarfBuzz shaping, OpenType fonts, cross-platform)       │
└─────────────────────────────────────────────────────────────┘
```

## Performance Targets

| Metric | Target | Current Status |
|--------|---------|----------------|
| Startup Time | < 2 seconds | In Progress |
| Text Rendering | 60 FPS | In Progress |
| Memory Usage | < 100MB base | In Progress |
| Font Loading | < 500ms | In Progress |

## Research & Development

This project is built on extensive research into:
- **Arabic Script Processing** - Unicode standards and implementation best practices
- **Cross-Platform Typography** - OpenType feature utilization across different systems
- **User Workflow Analysis** - Ensuring seamless transition from existing solutions
- **Performance Optimization** - Specialized algorithms for RTL text processing

## Documentation

*Documentation conerning the project is made available on the github repository.*

## Contributing

We welcome contributions from the community! Whether you're interested in:
- **Code Development** - Core features, UI improvements, performance optimization
- **Documentation** - User guides, technical documentation, tutorials
- **Testing** - Cross-platform testing, Arabic script validation
- **Design** - UI/UX improvements, icon design, user experience research

Please read our [Contributing Guide](CONTRIBUTING.md) for details on our development process.

### Development Status
- **Alpha Development** - Core features under active development
- **Documentation** - Comprehensive documentation being written
- **Testing** - Automated test suite being developed
- **Localization** - Multi-language support planned

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## About La Compte

La Compte is a registered firm focused on web design, graphic design, database management, and organizational infrastructure solutions. We're passionate about open source development and building tools that serve underserved communities.

- **Website**: <a href="https:la-compte.com">La Compte</a>
- **GitHub**: [@lacompte](https://github.com/lacompte)
- **Contact**: [Contact Information]

## Acknowledgments

- **Unicode Consortium** - For Arabic script standardization
- **HarfBuzz Project** - For excellent text shaping capabilities
- **Qt Project** - For cross-platform UI framework
- **FontTools Community** - For font analysis and manipulation tools
- **Arabic Typography Community** - For guidance and best practices
- **Danyal Ajaz** - Assistance in the development of Mazmoon renewed logo (28 May 2025)

---

**Status**: Active Development | **Version**: 0.1.0-alpha | **Last Updated**: May 2025
