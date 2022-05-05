#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
const int TIMEOUT = 1000;

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
private:
    HttpClient m_;

signals:

public slots:
    void connected();
    void readyRead();
};

#endif // HTTPCLIENT_H
