# Contributing to Mazmoon

Thank you for your interest in contributing to Mazmoon! This document provides guidelines for contributing to the project.

## Getting Started

### Prerequisites
- Ubuntu 18.04+ or Debian 10+
- Qt 5.15+ development environment
- Basic knowledge of C++ and Qt framework
- Understanding of Urdu text processing challenges

### Setting Up Development Environment

1. Clone the repository
```bash
git clone https://github.com/LaCompte/Mazmoon.git
cd Mazmoon
```

2. Install dependencies
```bash
sudo apt install qtbase5-dev qttools5-dev qt5-qmake
sudo apt install libharfbuzz-dev libicu-dev libfreetype6-dev
sudo apt install cmake build-essential git
```

3. Build the project
```bash
mkdir build && cd build
cmake ..
make
```

## How to Contribute

### Reporting Issues
- Use GitHub Issues to report bugs or request features
- Include detailed steps to reproduce bugs
- Provide system information (OS, Qt version, etc.)
- Include sample Urdu text that causes issues

### Code Contributions

#### Areas Needing Help

1. **Core Text Processing**
   - RTL text handling improvements
   - Cursor navigation in mixed text
   - Text selection behavior

2. **Language Support**
   - Urdu dictionary expansion
   - Spell checking algorithm improvements
   - Grammar checking implementation

3. **User Interface**
   - Ribbon interface components
   - RTL-optimized layouts
   - Accessibility improvements

4. **Documentation**
   - Code documentation
   - User guides in Urdu
   - Tutorial creation

5. **Testing**
   - Unit test development
   - Cross-platform testing
   - Font compatibility testing

#### Contribution Process

1. Fork the repository
2. Create a feature branch
```bash
git checkout -b feature/amazing-feature
```
3. Make your changes
4. Follow coding standards (see below)
5. Add tests for new functionality
6. Commit your changes
```bash
git commit -m 'Add amazing feature'
```
7. Push to the branch
```bash
git push origin feature/amazing-feature
```
8. Open a Pull Request

## Coding Standards

### General Guidelines
- Follow Qt coding conventions
- Use meaningful variable and function names
- Add comments for complex algorithms
- Write self-documenting code

### C++ Style Guidelines

```cpp
// Class names: PascalCase
class UrduTextProcessor {
    
// Function names: camelCase
public:
    void processUrduText();
    
// Member variables: camelCase with m_ prefix
private:
    QString m_currentText;
    bool m_isRTLMode;
};

// Constants: ALL_CAPS
const int MAX_BUFFER_SIZE = 1024;
```

### File Organization
- Header files (.h) in `include/` directory
- Source files (.cpp) in `src/` directory
- Test files in `tests/` directory
- Documentation in `docs/` directory

### Commit Message Format

```
type(scope): brief description

Detailed explanation of changes made.

- List specific changes
- Include any breaking changes
- Reference issue numbers if applicable
```

Types: feat, fix, docs, style, refactor, test, chore

### Testing Requirements
- All new features must include unit tests
- Test with actual Urdu text samples
- Verify RTL behavior works correctly
- Test on target platforms (Ubuntu/Debian)

### Documentation Requirements
- Document all public APIs
- Include code examples for complex functions
- Update user documentation for new features
- Add inline comments for algorithms

## Language-Specific Contributions

### Urdu Language Expertise
If you have expertise in Urdu language or typography:
- Help improve dictionary entries
- Suggest better spell checking rules
- Provide feedback on text rendering quality
- Contribute to language-specific documentation

### Arabic Script Languages
Contributions for other Arabic script languages welcome:
- Arabic language support
- Farsi/Persian language features
- Pashto language integration
- Sindhi language support

## Community Guidelines

### Code of Conduct
- Be respectful and inclusive
- Focus on constructive feedback
- Help newcomers to the project
- Maintain professional communication

### Communication Channels
- GitHub Issues for bug reports and feature requests
- GitHub Discussions for general questions
- Pull Request comments for code review
- Project README for announcements

## Recognition

### Contributors
All contributors will be recognized in:
- Project README contributors section
- Release notes for their contributions
- Special recognition for major contributions

### Types of Contributions Valued
- Code contributions
- Documentation improvements
- Bug reports and testing
- Translation work
- Community support
- Feature suggestions and design input

## Getting Help

### For New Contributors
- Check existing issues labeled "good first issue"
- Read through existing code to understand architecture
- Ask questions in GitHub Discussions
- Review this contributing guide thoroughly

### For Complex Issues
- Create detailed issue descriptions
- Provide code examples and error messages
- Include system configuration details
- Test with minimal reproducible examples

## Development Workflow

### Branching Strategy
- `main` branch: stable, production-ready code
- `develop` branch: integration branch for features
- `feature/*` branches: individual feature development
- `hotfix/*` branches: urgent bug fixes

### Release Process
1. Feature development in feature branches
2. Integration testing in develop branch
3. Release preparation and testing
4. Merge to main branch
5. Tag release and publish

## Legal Considerations

### License Agreement
By contributing, you agree that your contributions will be licensed under the GNU General Public License v3.0.

### Copyright
- Retain your copyright on contributed code
- License your contributions under GPL v3.0
- Ensure you have rights to contribute third-party code

### Attribution
- Add yourself to contributors list in appropriate files
- Include copyright notices in new files
- Reference any third-party code or algorithms used

---

Thank you for contributing to Mazmoon and helping improve Urdu language support in digital applications!