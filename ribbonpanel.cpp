#include "ribbonwidget.h"
#include <QGridLayout>
#include <QGroupBox>

RibbonWidget::RibbonWidget(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    tabWidget = new QTabWidget(this);
    tabWidget->setTabPosition(QTabWidget::North);

    setupHomeTab();
    setupInsertTab();
    setupLayoutTab();
    setupReviewTab();

    mainLayout->addWidget(tabWidget);

    styleRibbon();
}

void RibbonWidget::setupHomeTab()
{
    createHomeTab();
}

void RibbonWidget::setupInsertTab()
{
    createInsertTab();
}

void RibbonWidget::setupLayoutTab()
{
    createLayoutTab();
}

void RibbonWidget::setupReviewTab()
{
    createReviewTab();
}

void RibbonWidget::createHomeTab()
{
    homeTab = new QWidget();
    QHBoxLayout *homeLayout = new QHBoxLayout(homeTab);
    homeLayout->setContentsMargins(10, 10, 10, 10);

    // Clipboard Panel
    QWidget *clipboardPanel = new QWidget();
    QVBoxLayout *clipboardLayout = new QVBoxLayout(clipboardPanel);
    clipboardLayout->addWidget(new QLabel("Clipboard"));

    QPushButton *pasteBtn = createButton("Paste", QString(), true);
    QHBoxLayout *cutCopyLayout = new QHBoxLayout();
    cutCopyLayout->addWidget(createButton("Cut"));
    cutCopyLayout->addWidget(createButton("Copy"));

    clipboardLayout->addWidget(pasteBtn);
    clipboardLayout->addLayout(cutCopyLayout);
    clipboardLayout->addStretch();

    // Font Panel
    QWidget *fontPanel = new QWidget();
    QVBoxLayout *fontLayout = new QVBoxLayout(fontPanel);
    fontLayout->addWidget(new QLabel("Font"));

    QHBoxLayout *fontControlsLayout = new QHBoxLayout();
    fontCombo = new QFontComboBox();
    fontSizeSpinBox = new QSpinBox();
    fontSizeSpinBox->setRange(6, 72);
    fontSizeSpinBox->setValue(12);

    fontControlsLayout->addWidget(fontCombo);
    fontControlsLayout->addWidget(fontSizeSpinBox);

    QHBoxLayout *fontButtonsLayout = new QHBoxLayout();
    boldButton = createButton("B");
    italicButton = createButton("I");
    underlineButton = createButton("U");

    boldButton->setCheckable(true);
    italicButton->setCheckable(true);
    underlineButton->setCheckable(true);

    fontButtonsLayout->addWidget(boldButton);
    fontButtonsLayout->addWidget(italicButton);
    fontButtonsLayout->addWidget(underlineButton);

    fontLayout->addLayout(fontControlsLayout);
    fontLayout->addLayout(fontButtonsLayout);
    fontLayout->addStretch();

    // Paragraph Panel
    QWidget *paragraphPanel = new QWidget();
    QVBoxLayout *paragraphLayout = new QVBoxLayout(paragraphPanel);
    paragraphLayout->addWidget(new QLabel("Paragraph"));

    QHBoxLayout *alignLayout = new QHBoxLayout();
    alignLayout->addWidget(createButton("←"));
    alignLayout->addWidget(createButton("↔"));
    alignLayout->addWidget(createButton("→"));
    alignLayout->addWidget(createButton("⟷"));

    paragraphLayout->addLayout(alignLayout);
    paragraphLayout->addStretch();

    // Add panels to home tab
    homeLayout->addWidget(clipboardPanel);
    homeLayout->addWidget(createVerticalSeparator());
    homeLayout->addWidget(fontPanel);
    homeLayout->addWidget(createVerticalSeparator());
    homeLayout->addWidget(paragraphPanel);
    homeLayout->addStretch();

    tabWidget->addTab(homeTab, "Home");

    // Connect signals
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &RibbonWidget::onFontChanged);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RibbonWidget::onFontSizeChanged);
}

void RibbonWidget::createInsertTab()
{
    QWidget *insertTab = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(insertTab);
    layout->addWidget(new QLabel("Insert Tab - Coming Soon"));
    tabWidget->addTab(insertTab, "Insert");
}

void RibbonWidget::createLayoutTab()
{
    QWidget *layoutTab = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(layoutTab);
    layout->addWidget(new QLabel("Layout Tab - Coming Soon"));
    tabWidget->addTab(layoutTab, "Layout");
}

void RibbonWidget::createReviewTab()
{
    QWidget *reviewTab = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(reviewTab);
    layout->addWidget(new QLabel("Review Tab - Coming Soon"));
    tabWidget->addTab(reviewTab, "Review");
}

QPushButton* RibbonWidget::createButton(const QString &text, const QString &iconName, bool large)
{
    QPushButton *button = new QPushButton(text);

    if (large) {
        button->setMinimumSize(60, 60);
        button->setMaximumSize(60, 60);
    } else {
        button->setMinimumSize(30, 30);
        button->setMaximumSize(30, 30);
    }

    connect(button, &QPushButton::clicked, this, &RibbonWidget::onButtonClicked);
    return button;
}

QWidget* RibbonWidget::createVerticalSeparator()
{
    QFrame *separator = new QFrame();
    separator->setFrameShape(QFrame::VLine);
    separator->setFrameShadow(QFrame::Sunken);
    separator->setMaximumWidth(1);
    return separator;
}

void RibbonWidget::styleRibbon()
{
    setStyleSheet(
        "QTabWidget::pane {"
        "    border: 1px solid #c1c1c1;"
        "    background-color: #f1f1f1;"
        "    min-height: 120px;"
        "}"
        "QTabBar::tab {"
        "    background-color: #e1e1e1;"
        "    border: 1px solid #c1c1c1;"
        "    padding: 8px 20px;"
        "    margin-right: 2px;"
        "}"
        "QTabBar::tab:selected {"
        "    background-color: #f1f1f1;"
        "    border-bottom: 1px solid #f1f1f1;"
        "}"
        "QPushButton {"
        "    background-color: #f8f8f8;"
        "    border: 1px solid #d1d1d1;"
        "    border-radius: 3px;"
        "    padding: 5px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #e8e8e8;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #d8d8d8;"
        "}"
        "QPushButton:checked {"
        "    background-color: #d0d0d0;"
        "    border: 1px solid #a0a0a0;"
        "}"
        "QLabel {"
        "    font-size: 11px;"
        "    color: #666;"
        "    font-weight: 600;"
        "}"
    );
}

void RibbonWidget::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        emit actionTriggered(button->text());
    }
}

void RibbonWidget::onFontChanged(const QFont &font)
{
    emit actionTriggered("font_changed:" + font.family());
}

void RibbonWidget::onFontSizeChanged(int size)
{
    emit actionTriggered("font_size_changed:" + QString::number(size));
}
