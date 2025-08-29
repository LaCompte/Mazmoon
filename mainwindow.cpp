#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QScrollArea>
#include <QMenuBar>
#include <QToolBar>
#include <QFontComboBox>
#include <QSpinBox>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupStatusBar();

    setWindowTitle("Mazmoon - مضمون");
    resize(1200, 800);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create menu bar and toolbar
    createMenus();
    createToolbar();

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Document area with Traditional Forest Green and White theme
    QWidget *documentArea = new QWidget();
    documentArea->setStyleSheet("background-color: #e5e5e5;");

    QHBoxLayout *docLayout = new QHBoxLayout(documentArea);
    docLayout->setContentsMargins(50, 30, 50, 30);

    // White page with green border
    QWidget *page = new QWidget();
    page->setFixedSize(595, 842); // A4 size
    page->setStyleSheet(
        "background-color: #FFFFFF;"
        "border: 2px solid #01411C;"
        "border-radius: 3px;"
    );

    QVBoxLayout *pageLayout = new QVBoxLayout(page);
    pageLayout->setContentsMargins(40, 40, 40, 40);

    // Text editor within the page
    textEditor = new UrduTextEdit();
    textEditor->setStyleSheet(
        "QTextEdit {"
        "    border: none;"
        "    background-color: transparent;"
        "    font-family: 'Noto Sans';"
        "    font-size: 12pt;"
        "    line-height: 1.5;"
        "}"
    );
    textEditor->setLayoutDirection(Qt::RightToLeft);
    textEditor->setPlainText("سالام بخیر مرشد۔\n"
                            "ہم شترگزار ہیں کہ آپ نے Mazmoon Office Suite کو استعمال کیا ہے۔\n"
                            "Note: We wish it to be made clear that this app, although supporting bilingual options, is by default set to RTL orientation. You can manually change the settings for this orientation using the following approach: \"Edit-Change Orientation - LTR / RTL\".\n"
                            "مزید جاننے کے لیے Help میں \"معلومات\" کا اپشن دباعیں۔ شڑیا۔");

    pageLayout->addWidget(textEditor);
    docLayout->addStretch();
    docLayout->addWidget(page);
    docLayout->addStretch();

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(documentArea);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);
}

void MainWindow::createMenus()
{
    // Apply Traditional Forest Green theme to menu bar
    menuBar()->setStyleSheet(
        "QMenuBar {"
        "    background-color: #01411C;"
        "    color: #FFFFFF;"
        "    border-bottom: 1px solid #01411C;"
        "}"
        "QMenuBar::item {"
        "    background-color: transparent;"
        "    padding: 6px 12px;"
        "}"
        "QMenuBar::item:selected {"
        "    background-color: rgba(255, 255, 255, 0.2);"
        "}"
        "QMenu {"
        "    background-color: #FFFFFF;"
        "    color: #01411C;"
        "    border: 1px solid #01411C;"
        "}"
        "QMenu::item:selected {"
        "    background-color: #01411C;"
        "    color: #FFFFFF;"
        "}"
    );

    // File Menu
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("New", this, &MainWindow::newDocument, QKeySequence::New);
    fileMenu->addAction("Open", this, &MainWindow::openDocument, QKeySequence::Open);
    fileMenu->addAction("Save", this, &MainWindow::saveDocument, QKeySequence::Save);
    fileMenu->addSeparator();
    fileMenu->addAction("Exit", this, &QWidget::close, QKeySequence::Quit);

    // Edit Menu
    QMenu *editMenu = menuBar()->addMenu("Edit");
    editMenu->addAction("Cut", textEditor, &QTextEdit::cut, QKeySequence::Cut);
    editMenu->addAction("Copy", textEditor, &QTextEdit::copy, QKeySequence::Copy);
    editMenu->addAction("Paste", textEditor, &QTextEdit::paste, QKeySequence::Paste);
    editMenu->addSeparator();
    editMenu->addAction("Select All", textEditor, &QTextEdit::selectAll, QKeySequence::SelectAll);
    editMenu->addSeparator();
    editMenu->addAction("Bold", this, &MainWindow::toggleBold, QKeySequence::Bold);
    editMenu->addAction("Italic", this, &MainWindow::toggleItalic, QKeySequence::Italic);
    editMenu->addAction("Underline", this, &MainWindow::toggleUnderline, QKeySequence::Underline);

    // View Menu
    QMenu *viewMenu = menuBar()->addMenu("View");
    viewMenu->addAction("Zoom In", this, &MainWindow::zoomIn, QKeySequence::ZoomIn);
    viewMenu->addAction("Zoom Out", this, &MainWindow::zoomOut, QKeySequence::ZoomOut);
}

void MainWindow::createToolbar()
{
    QToolBar *toolbar = addToolBar("Main");
    toolbar->setMaximumHeight(40);
    toolbar->setStyleSheet(
        "QToolBar {"
        "    background-color: #f8f8f8;"
        "    border-bottom: 1px solid #01411C;"
        "    spacing: 5px;"
        "}"
        "QToolBar QWidget {"
        "    margin: 2px;"
        "}"
    );

    // Font controls
    fontCombo = new QFontComboBox();
    fontCombo->setMaximumWidth(180);
    fontCombo->setMinimumWidth(150);
    fontCombo->setStyleSheet("border: 1px solid #01411C; padding: 2px;");
    toolbar->addWidget(fontCombo);

    fontSizeSpinBox = new QSpinBox();
    fontSizeSpinBox->setRange(6, 72);
    fontSizeSpinBox->setValue(12);
    fontSizeSpinBox->setMaximumWidth(60);
    fontSizeSpinBox->setStyleSheet("border: 1px solid #01411C; padding: 2px;");
    toolbar->addWidget(fontSizeSpinBox);

    toolbar->addSeparator();

    // Format buttons with green theme
    QAction *boldAction = toolbar->addAction("B", this, &MainWindow::toggleBold);
    boldAction->setCheckable(true);
    boldAction->setToolTip("Bold");

    QAction *italicAction = toolbar->addAction("I", this, &MainWindow::toggleItalic);
    italicAction->setCheckable(true);
    italicAction->setToolTip("Italic");

    QAction *underlineAction = toolbar->addAction("U", this, &MainWindow::toggleUnderline);
    underlineAction->setCheckable(true);
    underlineAction->setToolTip("Underline");

    // Connect font controls
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &MainWindow::onFontChanged);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onFontSizeChanged);
}

void MainWindow::setupStatusBar()
{
    statusLabel = new QLabel("Ready", this);
    statusBar()->addWidget(statusLabel);
    statusBar()->setStyleSheet(
        "QStatusBar {"
        "    background-color: #01411C;"
        "    color: #FFFFFF;"
        "}"
    );
}

// File operations
void MainWindow::newDocument()
{
    textEditor->clear();
    statusLabel->setText("New document created");
}

void MainWindow::openDocument()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Document", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            in.setCodec("UTF-8");
            textEditor->setPlainText(in.readAll());
            statusLabel->setText("Document opened: " + fileName);
        }
    }
}

void MainWindow::saveDocument()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Document", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out.setCodec("UTF-8");
            out << textEditor->toPlainText();
            statusLabel->setText("Document saved: " + fileName);
        }
    }
}

// View operations
void MainWindow::zoomIn()
{
    textEditor->zoomIn();
    statusLabel->setText("Zoomed in");
}

void MainWindow::zoomOut()
{
    textEditor->zoomOut();
    statusLabel->setText("Zoomed out");
}

// Format operations
void MainWindow::toggleBold()
{
    QFont font = textEditor->currentFont();
    font.setBold(!font.bold());
    textEditor->setCurrentFont(font);
    statusLabel->setText(font.bold() ? "Bold enabled" : "Bold disabled");
}

void MainWindow::toggleItalic()
{
    QFont font = textEditor->currentFont();
    font.setItalic(!font.italic());
    textEditor->setCurrentFont(font);
    statusLabel->setText(font.italic() ? "Italic enabled" : "Italic disabled");
}

void MainWindow::toggleUnderline()
{
    QFont font = textEditor->currentFont();
    font.setUnderline(!font.underline());
    textEditor->setCurrentFont(font);
    statusLabel->setText(font.underline() ? "Underline enabled" : "Underline disabled");
}

void MainWindow::onFontChanged(const QFont &font)
{
    textEditor->setCurrentFont(font);
    statusLabel->setText("Font changed to: " + font.family());
}

void MainWindow::onFontSizeChanged(int size)
{
    QFont font = textEditor->currentFont();
    font.setPointSize(size);
    textEditor->setCurrentFont(font);
    statusLabel->setText("Font size changed to: " + QString::number(size));
}
