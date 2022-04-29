#ifndef HTTPFETCHER_H
#define HTTPFETCHER_H

#include <QObject>

class HttpFetcher : public QObject
{
    Q_OBJECT
public:
    explicit HttpFetcher(QObject *parent = nullptr);

signals:

public slots:
};

#endif // HTTPFETCHER_H