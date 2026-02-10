#include <QApplication>
#include <QStyleFactory>
#include <QDir>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTranslator>
#include <QLocale>

#include "drive_manager_ui.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Set application properties
    app.setApplicationName("YouTube Media Storage");
    app.setApplicationDisplayName("Drive Manager");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("Media Storage");
    app.setOrganizationDomain("brandonli.me");
    
    // Set application icon (if available)
    // app.setWindowIcon(QIcon(":/icons/app_icon.png"));
    
    // Enable high DPI scaling (deprecated in Qt6, but kept for compatibility)
    // app.setAttribute(Qt::AA_EnableHighDpiScaling);
    // app.setAttribute(Qt::AA_UseHighDpiPixmaps);
    
    // Set style to a modern look if available
    if (QStyleFactory::keys().contains("Fusion")) {
        app.setStyle("Fusion");
    }
    
    // Create and show the main window
    DriveManagerUI window;
    window.show();
    
    return app.exec();
}
