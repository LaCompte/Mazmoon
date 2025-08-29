#ifndef RIBBONWIDGET_H
#define RIBBONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QFrame>
#include <QFontComboBox>
#include <QSpinBox>

class RibbonWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RibbonWidget(QWidget *parent = nullptr);

signals:
    void actionTriggered(const QString &action);

private slots:
    void onButtonClicked();
    void onFontChanged(const QFont &font);
    void onFontSizeChanged(int size);

private:
    QWidget* createColumn(const QString &title, int width, int height);
    QPushButton* createSmallButton(const QString &text);
    QVBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QFontComboBox *fontCombo;
    QSpinBox *fontSizeSpinBox;

    void setupUI();
    QPushButton* createButton(const QString &text);
    QWidget* createGroup(const QString &title);    // Add this
    QWidget* createSeparator();                    // Add this
};

#endif // RIBBONWIDGET_H
