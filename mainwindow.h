#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include "urdutextedit.h"
#include <QMenuBar>
#include <QToolBar>
#include <QFontComboBox>
#include <QSpinBox>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newDocument();
    void openDocument();
    void saveDocument();
    void zoomIn();
    void zoomOut();
    void toggleBold();
    void toggleItalic();
    void toggleUnderline();
    void onFontChanged(const QFont &font);
    void onFontSizeChanged(int size);

private:
    UrduTextEdit *textEditor;
    QLabel *statusLabel;
    QFontComboBox *fontCombo;
    QSpinBox *fontSizeSpinBox;

    void setupUI();
    void setupStatusBar();
    void createMenus();
    void createToolbar();
};

#endif // MAINWINDOW_H
