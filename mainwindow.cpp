#include "mainwindow.h"
#include <QVBoxLayout>
#include <QStatusBar>
#include <QScrollArea>

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

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Create ribbon (now compact)
    ribbon = new RibbonWidget(this);
    mainLayout->addWidget(ribbon);

    // Create document area with page-like appearance
    QWidget *documentArea = new QWidget();
    documentArea->setStyleSheet("background-color: #e5e5e5;"); // Gray background like Word

    QHBoxLayout *docLayout = new QHBoxLayout(documentArea);
    docLayout->setContentsMargins(50, 30, 50, 30);

    // Create white "page"
    QWidget *page = new QWidget();
    page->setFixedSize(595, 842); // A4 size
    page->setStyleSheet(
        "background-color: white;"
        "border: 1px solid #ccc;"
        "border-radius: 2px;"
    );

    QVBoxLayout *pageLayout = new QVBoxLayout(page);
    pageLayout->setContentsMargins(40, 40, 40, 40);

    // Text editor within the page
    textEditor = new QTextEdit();
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
    textEditor->setPlainText("بسم اللہ الرحمٰن الرحیم\n\nیہ مضمون ایڈیٹر کا نمونہ ہے۔ یہاں آپ اردو میں لکھ سکتے ہیں۔");

    pageLayout->addWidget(textEditor);

    docLayout->addStretch();
    docLayout->addWidget(page);
    docLayout->addStretch();

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidget(documentArea);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);

    // Connect signals
    connect(ribbon, &RibbonWidget::actionTriggered, this, &MainWindow::onRibbonAction);
}

void MainWindow::setupStatusBar()
{
    statusLabel = new QLabel("Ready", this);
    statusBar()->addWidget(statusLabel);
}

void MainWindow::onRibbonAction(const QString &action)
{
    if (action.startsWith("font_changed:")) {
        QString fontFamily = action.mid(13);
        QFont font = textEditor->font();
        font.setFamily(fontFamily);
        textEditor->setFont(font);
        statusLabel->setText("Font changed to: " + fontFamily);
    }
    else if (action.startsWith("font_size_changed:")) {
        int size = action.mid(18).toInt();
        QFont font = textEditor->font();
        font.setPointSize(size);
        textEditor->setFont(font);
        statusLabel->setText("Font size changed to: " + QString::number(size));
    }
    else {
        statusLabel->setText("Action: " + action);
    }
}
