#include "html5appviewer.h"

#include <QCoreApplication>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWebChannel>
#include <QWebEngineSettings>
#include <QFile>
#include <QMessageBox>
#include <QWebChannel>

Html5AppViewer::Html5AppViewer(QWidget *parent)
    :   QWidget(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);

    webView = new QWebEngineView;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(webView);
    layout->setMargin(0);
    setLayout(layout);

    webView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    webChannel = new QWebChannel(this);
    webView->page()->setWebChannel(webChannel);
    webChannel->registerObject(QStringLiteral("CoreApplication"), qApp);
    webChannel->registerObject(QStringLiteral("QtWindow"), this);

}

void Html5AppViewer::loadUrl(const QUrl &url) {
    webView->load(url);
}

QWebChannel* Html5AppViewer::WebChannel() {
    return webChannel;
}
