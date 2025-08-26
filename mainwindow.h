#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>  // Change from urdutextedit.h to QTextEdit
#include "ribbonwidget.h"
// Remove: #include "urdutextedit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRibbonAction(const QString &action);

private:
    RibbonWidget *ribbon;
    QTextEdit *textEditor;  // Change from UrduTextEdit* to QTextEdit*
    QLabel *statusLabel;

    void setupUI();
    void setupStatusBar();
};

#endif // MAINWINDOW_H
