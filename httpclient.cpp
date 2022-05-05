#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>
#include "httpclient.h"

HttpClient::HttpClient(int argc, char* argv[], QObject *parent) : QObject(parent)
{
    connect(m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);

    qDebug("Argc = %d", argc);
    for ( int i = 0; i < argc; i++)
        qDebug("argc %d = %s", i, argv[i]);

    QTcpSocket* socket = new QTcpSocket(this);

    if ( argc == 2 ) {
        QString host = argv[1];
        quint16 port;

        for ( port = 1; port < 1024; port++) {
            socket->connectToHost( host, port);

            if (!socket->waitForConnected(TIMEOUT)) {
                //qDebug("Port %d: connect failed!", port);
            } else {
                qDebug("Port %d: Connected!", port);
                socket->disconnectFromHost();
            }
        }
    }
    else {
        qDebug("Format: Portscanner <hostname>");
    }
}

void HttpClient::connected()
{

    m_socket->write(
}

void HttpClient::readyRead()
{
    m_socket->disconnectFromHost();
}
