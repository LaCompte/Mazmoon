# Contributing to La Compte Arabic Script Editor

Thank you for your interest in contributing to the La Compte Arabic Script Editor! This document provides guidelines and information for contributors.

## Project Vision

We're building a modern, Unicode-based office suite that serves Arabic script language users with professional-grade tools while maintaining familiar workflows. Our goal is to create the fastest, most intuitive Arabic text editor that works seamlessly across platforms.

## Ways to Contribute

### 1. Code Development
- **Core Engine**: Text processing, RTL algorithms, Unicode handling
- **User Interface**: Qt-based UI components, theming, accessibility
- **Font Management**: OpenType integration, font analysis tools
- **Export/Import**: Document format compatibility (DOCX, PDF, HTML)
- **Performance**: Optimization, memory management, startup speed

### 2. Documentation
- **User Documentation**: Tutorials, feature guides, troubleshooting
- **Technical Documentation**: API documentation, architecture guides
- **Localization**: Translation to Arabic, Urdu, Farsi, and other languages
- **Examples**: Code samples, usage demonstrations

### 3. Testing & Quality Assurance
- **Cross-Platform Testing**: Linux, Windows, macOS compatibility
- **Arabic Script Validation**: Text rendering accuracy, RTL behavior
- **Performance Testing**: Benchmarking, stress testing, optimization
- **User Experience Testing**: Workflow validation, usability studies

### 4. Design & User Experience
- **UI/UX Design**: Interface improvements, icon design
- **Typography Research**: Arabic script best practices
- **Accessibility**: Screen reader support, keyboard navigation
- **User Research**: Workflow analysis, feature requirements

## Getting Started

### Development Environment Setup

1. **Clone the Repository**
   ```bash
   git clone https://github.com/lacompte/arabic-script-editor.git
   cd arabic-script-editor
   ```

2. **Install Dependencies**
   ```bash
   # Python dependencies
   pip install -r requirements.txt
   pip install -r requirements-dev.txt
   
   # System dependencies (Ubuntu/Debian)
   sudo apt install libharfbuzz-dev libicu-dev qt5-default
   ```

3. **Run Tests**
   ```bash
   python -m pytest tests/ -v
   ```

4. **Start Development**
   ```bash
   python src/main.py --debug
   ```

### Development Workflow

1. **Fork** the repository on GitHub
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

## Coding Standards

### Python Code Style
- Follow **PEP 8** style guidelines
- Use **type hints** for function parameters and return values
- Write **docstrings** for all public functions and classes
- Maximum line length: **88 characters** (Black formatter)
- Use **meaningful variable names** and **descriptive comments**

### Code Quality Requirements
- **Test Coverage**: Minimum 90% for new code
- **Documentation**: All public APIs must be documented
- **Performance**: No regressions in startup time or memory usage
- **Cross-Platform**: Code must work on Linux, Windows, and macOS

### Example Code Style
```python
def process_arabic_text(text: str, font_name: str) -> ProcessedText:
    """
    Process Arabic text using HarfBuzz shaping engine.
    
    Args:
        text: Unicode Arabic text to process
        font_name: Name of the Arabic font to use
        
    Returns:
        ProcessedText object with shaped glyphs and positioning
        
    Raises:
        FontError: If the specified font is not available
        TextProcessingError: If text shaping fails
    """
    # Implementation here
    pass
```

## Testing Guidelines

### Test Categories
1. **Unit Tests**: Individual function and class testing
2. **Integration Tests**: Component interaction testing  
3. **UI Tests**: User interface and workflow testing
4. **Performance Tests**: Speed and memory benchmarks
5. **Arabic Script Tests**: Text rendering and RTL behavior validation

### Running Tests
```bash
# Run all tests
python -m pytest tests/

# Run specific test category
python -m pytest tests/unit/ -v
python -m pytest tests/integration/ -v
python -m pytest tests/performance/ -v

# Run with coverage
python -m pytest tests/ --cov=src --cov-report=html
```

### Writing Tests
- **Test file naming**: `test_<module_name>.py`
- **Test function naming**: `test_<functionality>_<expected_behavior>()`
- **Arabic text testing**: Use Unicode test strings, validate RTL behavior
- **Performance testing**: Use `pytest-benchmark` for timing tests

## 📚 Documentation Standards

### Documentation Structure
- **User-facing**: Clear, step-by-step instructions with examples
- **Developer-facing**: Technical details, API references, architecture
- **Code comments**: Explain complex algorithms, especially RTL processing
- **Docstrings**: Follow Google or NumPy docstring conventions

### Documentation Tools
- **Markdown**: For general documentation
- **Sphinx**: For API documentation generation
- **Screenshots**: Include UI screenshots for user guides
- **Diagrams**: Use Mermaid for architecture diagrams

## Localization Guidelines

### Supported Languages
- **English** (primary)
- **Arabic** (العربية)
- **Urdu** (اردو)
- **Farsi** (فارسی)
- **Additional languages welcome**

### Translation Process
1. Use **gettext** for string internationalization
2. Maintain **context** for translators
3. Test **RTL layout** for Arabic script languages
4. Consider **text expansion** in UI design

## Bug Reports

### Before Submitting
- **Search existing issues** to avoid duplicates
- **Update to latest version** and test again
- **Gather system information** (OS, Python version, Qt version)

### Bug Report Template
```markdown
**Bug Description**
A clear description of the bug.

**Steps to Reproduce**
1. Step one
2. Step two
3. See error

**Expected Behavior**
What should have happened?

**Actual Behavior**
What actually happened?

**System Information**
- OS: [Ubuntu 22.04, Windows 10, etc.]
- Python Version: [3.9.7]
- Qt Version: [5.15.2]
- Application Version: [0.1.0-alpha]

**Arabic Text Sample**
If applicable, include the Arabic text that caused the issue.
```

## Feature Requests

### Feature Request Template
```markdown
**Feature Description**
Clear description of the requested feature.

**Use Case**
Why is this feature needed? What problem does it solve?

**Proposed Implementation**
Any ideas on how this could be implemented?

**Additional Context**
Screenshots, mockups, or examples if applicable.
```

## 🏆 Recognition

Contributors will be recognized in:
- **Contributors section** of README.md
- **About dialog** in the application
- **Release notes** for significant contributions
- **Special recognition** for outstanding contributions

## 📞 Communication

### Primary Channels
- **GitHub Issues**: Bug reports, feature requests, discussions
- **GitHub Discussions**: General questions, ideas, community chat
- **Pull Request Reviews**: Code review and feedback

### Communication Guidelines
- **Be respectful** and inclusive
- **Use English** for primary communication
- **Provide context** for technical discussions
- **Ask questions** if anything is unclear

## Code of Conduct

### Our Standards
- **Respectful communication** with all community members
- **Constructive feedback** in code reviews and discussions
- **Inclusive environment** welcoming contributors of all backgrounds
- **Focus on collaboration** and learning

### Unacceptable Behavior
- Harassment, discrimination, or offensive language
- Personal attacks or trolling
- Spam or irrelevant content
- Violation of others' privacy

## Getting Help

### Resources
- **Documentation**: Check docs/ directory for guides
- **Examples**: See examples/ directory for usage samples
- **Tests**: Review tests/ directory for implementation examples
- **Issues**: Search existing issues for solutions

### Contact
If you need help getting started or have questions:
1. **Check documentation** first
2. **Search existing issues** for similar questions
3. **Open a new issue** with the "question" label
4. **Join GitHub Discussions** for community help

---

Thank you for contributing to La Compte Arabic Script Editor! Your contributions help make Arabic text editing better for everyone. 🌟
