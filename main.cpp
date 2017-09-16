#include "html5appviewer.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QUrl>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QApplication a(argc, argv);

    QDesktopWidget screen;
    Html5AppViewer w;

    w.resize(500, 600);
    w.move((screen.width() - w.width()) / 2, (screen.height() - w.height()) / 2);
    w.loadUrl(QUrl("qrc:/html/index.html"));
    w.show();

    return a.exec();
}
