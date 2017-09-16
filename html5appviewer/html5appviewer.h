#ifndef Html5AppViewer_H
#define Html5AppViewer_H


class QWebEngineView;
class QWebChannel;

#include <QWidget>

class Html5AppViewer : public QWidget
{
public:
    explicit Html5AppViewer(QWidget *parent = 0);

    void loadUrl(const QUrl &url);

    QWebChannel *WebChannel();

private:
    QWebEngineView *webView;
    QWebChannel *webChannel;

};

#endif // Html5AppViewer_H
