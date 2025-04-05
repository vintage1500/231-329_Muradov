#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QNetworkAccessManager * nam = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://127.0.0.1:8000/article"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply * reply = nam->get(request);

    QEventLoop evtLoop;
    connect(reply, &QNetworkReply::readyRead,
            &evtLoop, &QEventLoop::quit);
    connect(reply, &QNetworkReply::errorOccurred,
            &evtLoop, &QEventLoop::quit);
    connect(reply, &QNetworkReply::sslErrors,
            &evtLoop, &QEventLoop::quit);
    evtLoop.exec();
    qDebug()
        << "*** RESPONSE:"
        << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute)
        << reply->errorString()
        << reply->readAll();

}

