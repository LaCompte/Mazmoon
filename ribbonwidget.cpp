#include "ribbonwidget.h"
#include <QSpacerItem>

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
    tabWidget->setMaximumHeight(75);  // Slightly increase to accommodate bigger buttons
    tabWidget->setMinimumWidth(800);
    tabWidget->setStyleSheet(
        "QTabWidget::pane { border: 1px solid #01411C; background-color: #f5f5f5; padding: 2px; }"
        "QTabBar::tab { background-color: #e0e0e0; border: 1px solid #01411C; padding: 4px 12px; }"
        "QTabBar::tab:selected { background-color: #f5f5f5; }"
        );


    // Create Home Tab with column structure
    QWidget *homeTab = new QWidget();
    QHBoxLayout *homeLayout = new QHBoxLayout(homeTab);
    homeLayout->setContentsMargins(4, 4, 4, 4);  // Reduce from 8,8,8,8
    homeLayout->setSpacing(6);  // Reduce from 8
    // Column 1: Font Controls - Full Height
    QWidget *fontColumn = createColumn("Font", 120, 65);
    QVBoxLayout *fontLayout = new QVBoxLayout(fontColumn);
    fontLayout->setContentsMargins(3, 3, 3, 3);
    fontLayout->setSpacing(4);

    fontCombo = new QFontComboBox();
    fontCombo->setMaximumWidth(115);
    fontCombo->setMinimumHeight(28);
    fontCombo->setMaximumHeight(28);
    fontLayout->addWidget(fontCombo);

    fontSizeSpinBox = new QSpinBox();
    fontSizeSpinBox->setRange(6, 72);
    fontSizeSpinBox->setValue(12);
    fontSizeSpinBox->setMaximumWidth(115);
    fontSizeSpinBox->setMinimumHeight(28);
    fontSizeSpinBox->setMaximumHeight(28);
    fontLayout->addWidget(fontSizeSpinBox);

    // Column 2: Basic Font Options - Full Height
    QWidget *basicFontColumn = createColumn("Format", 150, 65);
    QVBoxLayout *basicFontLayout = new QVBoxLayout(basicFontColumn);
    basicFontLayout->setContentsMargins(3, 3, 3, 3);
    basicFontLayout->setSpacing(2);

    QHBoxLayout *topButtonRow = new QHBoxLayout();
    topButtonRow->setSpacing(2);
    QPushButton *boldBtn = createSmallButton("B");
    QPushButton *italicBtn = createSmallButton("I");
    QPushButton *underlineBtn = createSmallButton("U");
    boldBtn->setMinimumHeight(26);
    italicBtn->setMinimumHeight(26);
    underlineBtn->setMinimumHeight(26);
    topButtonRow->addWidget(boldBtn);
    topButtonRow->addWidget(italicBtn);
    topButtonRow->addWidget(underlineBtn);

    QHBoxLayout *bottomButtonRow = new QHBoxLayout();
    bottomButtonRow->setSpacing(2);
    QPushButton *strikeBtn = createSmallButton("S");
    QPushButton *caseBtn = createSmallButton("Aa");
    strikeBtn->setMinimumHeight(26);
    caseBtn->setMinimumHeight(26);
    bottomButtonRow->addWidget(strikeBtn);
    bottomButtonRow->addWidget(caseBtn);

    basicFontLayout->addLayout(topButtonRow);
    basicFontLayout->addLayout(bottomButtonRow);

    // Column 3: Paragraph Options - Full Height
    QWidget *paragraphColumn = createColumn("Paragraph", 150, 65);
    QVBoxLayout *paragraphLayout = new QVBoxLayout(paragraphColumn);
    paragraphLayout->setContentsMargins(3, 3, 3, 3);
    paragraphLayout->setSpacing(2);

    QHBoxLayout *alignRow = new QHBoxLayout();
    alignRow->setSpacing(2);
    QPushButton *leftBtn = createSmallButton("⌐");
    QPushButton *centerBtn = createSmallButton("═");
    QPushButton *rightBtn = createSmallButton("¬");
    leftBtn->setMinimumHeight(26);
    centerBtn->setMinimumHeight(26);
    rightBtn->setMinimumHeight(26);
    alignRow->addWidget(leftBtn);
    alignRow->addWidget(centerBtn);
    alignRow->addWidget(rightBtn);

    QHBoxLayout *formatRow = new QHBoxLayout();
    formatRow->setSpacing(2);
    QPushButton *justifyBtn = createSmallButton("≡");
    QPushButton *spacingBtn = createSmallButton("↕");
    justifyBtn->setMinimumHeight(26);
    spacingBtn->setMinimumHeight(26);
    formatRow->addWidget(justifyBtn);
    formatRow->addWidget(spacingBtn);

    paragraphLayout->addLayout(alignRow);
    paragraphLayout->addLayout(formatRow);

    // Column 4: Styles - Full Height
    QWidget *stylesColumn = createColumn("Styles", 100, 65);
    QVBoxLayout *stylesLayout = new QVBoxLayout(stylesColumn);
    stylesLayout->setContentsMargins(3, 3, 3, 3);
    stylesLayout->setSpacing(8);

    QComboBox *styleCombo = new QComboBox();
    styleCombo->addItems({"Normal", "Heading 1", "Heading 2", "Heading 3", "Heading 4", "Title", "Subtitle", "Caption"});
    styleCombo->setMinimumHeight(50);
    stylesLayout->addWidget(styleCombo);

    // Column 5: Quick Buttons - Full Height
    QWidget *quickColumn = createColumn("Quick Buttons", 150, 65);
    QVBoxLayout *quickLayout = new QVBoxLayout(quickColumn);
    quickLayout->setContentsMargins(3, 3, 3, 3);
    quickLayout->setSpacing(2);

    QHBoxLayout *quickTopRow = new QHBoxLayout();
    quickTopRow->setSpacing(2);
    QPushButton *cutBtn = createSmallButton("Cut");
    QPushButton *copyBtn = createSmallButton("Copy");
    QPushButton *pasteBtn = createSmallButton("Paste");
    cutBtn->setMinimumHeight(26);
    copyBtn->setMinimumHeight(26);
    pasteBtn->setMinimumHeight(26);
    quickTopRow->addWidget(cutBtn);
    quickTopRow->addWidget(copyBtn);
    quickTopRow->addWidget(pasteBtn);

    QHBoxLayout *quickBottomRow = new QHBoxLayout();
    quickBottomRow->setSpacing(2);
    QPushButton *saveBtn = createSmallButton("Save");
    QPushButton *openBtn = createSmallButton("Open");
    QPushButton *formatBtn = createSmallButton("Format");
    saveBtn->setMinimumHeight(26);
    openBtn->setMinimumHeight(26);
    formatBtn->setMinimumHeight(26);
    quickBottomRow->addWidget(saveBtn);
    quickBottomRow->addWidget(openBtn);
    quickBottomRow->addWidget(formatBtn);

    quickLayout->addLayout(quickTopRow);
    quickLayout->addLayout(quickBottomRow);
    // Add columns to home tab - MODIFIED VERSION
        homeLayout->addWidget(fontColumn);
        homeLayout->addWidget(createSeparator());
        homeLayout->addWidget(basicFontColumn);
        homeLayout->addWidget(createSeparator());
        homeLayout->addWidget(paragraphColumn);
        homeLayout->addWidget(createSeparator());
        homeLayout->addWidget(stylesColumn);
        homeLayout->addWidget(createSeparator());
        homeLayout->addWidget(quickColumn);

        // Replace the QSpacerItem lines with this:
        //QWidget *flexibleSpacer = new QWidget();
        //flexibleSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        //homeLayout->addWidget(flexibleSpacer);

    tabWidget->addTab(homeTab, "Home");
    tabWidget->addTab(new QWidget(), "Insert");
    tabWidget->addTab(new QWidget(), "Layout");
    tabWidget->addTab(new QWidget(), "Review");

    mainLayout->addWidget(tabWidget);

    // Connect signals
    connect(fontCombo, &QFontComboBox::currentFontChanged, this, &RibbonWidget::onFontChanged);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &RibbonWidget::onFontSizeChanged);
}

QWidget* RibbonWidget::createColumn(const QString &title, int width, int height)
{
    Q_UNUSED(title);

    QWidget *column = new QWidget();
    column->setMinimumSize(width, height);
    column->setMaximumHeight(height);
    column->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    column->setStyleSheet(
        "QWidget {"
        "    border: 1px solid #01411C;"
        "    border-radius: 3px;"
        "    background-color: white;"
        "    margin: 1px;"  // Reduce from 2px
        "}"
    );
    return column;
}

QPushButton* RibbonWidget::createSmallButton(const QString &text)
{
    QPushButton *button = new QPushButton(text);
    button->setFixedSize(30, 25);
    button->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid #01411C;"
        "    border-radius: 2px;"
        "    background-color: white;"
        "    font-size: 9px;"
        "}"
        "QPushButton:hover { background-color: #e0f0e0; }"
        "QPushButton:pressed { background-color: #c0e0c0; }"
        "QPushButton:checked { background-color: #01411C; color: white; }"
    );
    connect(button, &QPushButton::clicked, this, &RibbonWidget::onButtonClicked);
    return button;
}

QWidget* RibbonWidget::createSeparator()
{
    QFrame *separator = new QFrame();
    separator->setFrameShape(QFrame::VLine);
    separator->setFrameShadow(QFrame::Sunken);
    separator->setMaximumWidth(2);
    separator->setStyleSheet("color: #01411C;");
    return separator;
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
