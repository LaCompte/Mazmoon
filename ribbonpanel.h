#ifndef RIBBONWIDGET_H
#define RIBBONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QTabBar>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QComboBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QButtonGroup>

class RibbonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RibbonWidget(QWidget *parent = nullptr);

    void setupHomeTab();
    void setupInsertTab();
    void setupLayoutTab();
    void setupReviewTab();

signals:
    void actionTriggered(const QString &action);

private slots:
    void onButtonClicked();
    void onFontChanged(const QFont &font);
    void onFontSizeChanged(int size);

private:
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;

    // Home tab widgets
    QWidget *homeTab;
    QFontComboBox *fontCombo;
    QSpinBox *fontSizeSpinBox;
    QPushButton *boldButton;
    QPushButton *italicButton;
    QPushButton *underlineButton;

    void createHomeTab();
    void createInsertTab();
    void createLayoutTab();
    void createReviewTab();
    void styleRibbon();
    QWidget* createVerticalSeparator();  // This was missing - causing the error
    QPushButton* createButton(const QString &text, const QString &iconName = QString(), bool large = false);
};

#endif // RIBBONWIDGET_H
