#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "article.h"
#include "clientinterface.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

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


void MainWindow::on_get_1_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");

    Article event = client->GetArticle(1007);
}


void MainWindow::on_delete_2_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->DeleteArticle(20);
}


void MainWindow::on_update_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->UpdateArticle(10);
}


void MainWindow::on_create_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->CreateArticle();
}


void MainWindow::on_get_all_clicked()
{
    ClientInterface *client = ClientInterface::getInstance("http://127.0.0.1:8000/");
    client->GetArticle();
}

