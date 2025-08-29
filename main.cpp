
#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set application properties
    a.setApplicationName("Mazmoon");
    a.setApplicationVersion("1.0.0");
    a.setOrganizationName("La Compte");
    a.setOrganizationDomain("lacompte.com");

    // Enable high DPI support
    a.setAttribute(Qt::AA_EnableHighDpiScaling);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    // Load custom fonts if available
    QString fontPath = QDir::currentPath() + "/resources/fonts/";
    QDir fontDir(fontPath);

    if (fontDir.exists()) {
        QStringList fontFiles = fontDir.entryList(QStringList() << "*.ttf" << "*.otf", QDir::Files);
        foreach (const QString &file, fontFiles) {
            int fontId = QFontDatabase::addApplicationFont(fontPath + file);
            if (fontId != -1) {
                QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
                qDebug() << "Loaded font:" << fontFamilies;
            }
        }
    }

    MainWindow w;
    w.show();

    return a.exec();
}
