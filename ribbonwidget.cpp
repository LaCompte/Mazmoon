#include "ribbonwidget.h"

RibbonWidget::RibbonWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void RibbonWidget::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    tabWidget = new QTabWidget(this);
    tabWidget->setMaximumHeight(110); // Force compact height

    // Create Home Tab with proper layout
    QWidget *homeTab = new QWidget();
    QHBoxLayout *homeLayout = new QHBoxLayout(homeTab);
    homeLayout->setContentsMargins(10, 5, 10, 5);
    homeLayout->setSpacing(15);

    // Clipboard group
    QWidget *clipboardGroup = createGroup("Clipboard");
    QVBoxLayout *clipboardLayout = new QVBoxLayout(clipboardGroup);
    clipboardLayout->setSpacing(2);

    QPushButton *pasteBtn = createButton("Paste");
    pasteBtn->setMinimumSize(50, 35);
    clipboardLayout->addWidget(pasteBtn);

    QHBoxLayout *cutCopyLayout = new QHBoxLayout();
    cutCopyLayout->addWidget(createButton("Cut"));
    cutCopyLayout->addWidget(createButton("Copy"));
    clipboardLayout->addLayout(cutCopyLayout);

    // Font group
    QWidget *fontGroup = createGroup("Font");
    QVBoxLayout *fontLayout = new QVBoxLayout(fontGroup);

    QHBoxLayout *fontControlsLayout = new QHBoxLayout();
    fontCombo = new QFontComboBox();
    fontCombo->setMaximumWidth(120);
    fontCombo->setMaximumHeight(22);

    fontSizeSpinBox = new QSpinBox();
    fontSizeSpinBox->setRange(6, 72);
    fontSizeSpinBox->setValue(12);
    fontSizeSpinBox->setMaximumWidth(50);
    fontSizeSpinBox->setMaximumHeight(22);

    fontControlsLayout->addWidget(fontCombo);
    fontControlsLayout->addWidget(fontSizeSpinBox);
    fontLayout->addLayout(fontControlsLayout);

    QHBoxLayout *fontButtonsLayout = new QHBoxLayout();
    fontButtonsLayout->addWidget(createButton("B"));
    fontButtonsLayout->addWidget(createButton("I"));
    fontButtonsLayout->addWidget(createButton("U"));
    fontLayout->addLayout(fontButtonsLayout);

    // Add groups to ribbon
    homeLayout->addWidget(clipboardGroup);
    homeLayout->addWidget(createSeparator());
    homeLayout->addWidget(fontGroup);
    homeLayout->addWidget(createSeparator());
    homeLayout->addStretch();

    tabWidget->addTab(homeTab, "Home");
    tabWidget->addTab(new QWidget(), "Insert");
    tabWidget->addTab(new QWidget(), "Layout");
    tabWidget->addTab(new QWidget(), "Review");

    mainLayout->addWidget(tabWidget);

    // Connect signals
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &RibbonWidget::onFontChanged);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RibbonWidget::onFontSizeChanged);
}

QWidget* RibbonWidget::createGroup(const QString &title)
{
    QWidget *group = new QWidget();
    group->setStyleSheet(
        "QWidget {"
        "    border: 1px solid #d0d0d0;"
        "    border-radius: 3px;"
        "    background-color: #f8f8f8;"
        "    margin: 2px;"
        "    padding: 5px;"
        "}"
    );
    group->setMaximumHeight(90);
    return group;
}

QWidget* RibbonWidget::createSeparator()
{
    QFrame *separator = new QFrame();
    separator->setFrameShape(QFrame::VLine);
    separator->setFrameShadow(QFrame::Sunken);
    separator->setMaximumWidth(1);
    separator->setMaximumHeight(80);
    return separator;
}

QPushButton* RibbonWidget::createButton(const QString &text)
{
    QPushButton *button = new QPushButton(text);
    button->setMinimumSize(25, 25);
    button->setMaximumSize(25, 25);
    connect(button, &QPushButton::clicked, this, &RibbonWidget::onButtonClicked);
    return button;
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
