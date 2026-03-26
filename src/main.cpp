/**
 * @file main.cpp
 * @brief SmithTool application entry point
 */

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include "ui/mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    // Set application information
    QApplication::setApplicationName("SmithTool");
    QApplication::setApplicationVersion("0.1.0");
    QApplication::setOrganizationName("SmithTool");

    // Load preferred UI language.
    QSettings settings;
    const QString languageCode = settings.value("ui/language", "en").toString();
    QTranslator translator;
    if (languageCode.startsWith("zh", Qt::CaseInsensitive)) {
        if (translator.load(":/i18n/smithtool_zh_CN.qm")) {
            app.installTranslator(&translator);
        }
    }
    
    // Create and show main window
    SmithTool::MainWindow mainWindow;
    mainWindow.show();
    
    return app.exec();
}
