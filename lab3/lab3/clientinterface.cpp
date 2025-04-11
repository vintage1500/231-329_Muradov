#include "clientinterface.h"
#include <QObject>

ClientInterface* ClientInterface::existing_object = nullptr;

Article ClientInterface::GetArticle(const unsigned int id)
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://127.0.0.1:8000/article/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->get(request);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(); // Ждём завершения запроса

    QByteArray responseData = reply->readAll(); // Читаем ответ

    // Парсим JSON
    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    QList<Article> events; // Список событий

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        for (const QJsonValue &value : jsonArray) {
            if (value.isObject()) {
                events.append(Article::fromJson(value.toObject()));
            }
        }
    } else if (jsonDoc.isObject()) {
        events.append(Article::fromJson(jsonDoc.object()));
    } else {
        qDebug() << "Ошибка: Ожидался JSON-объект или массив!";
    }

    // Выводим данные для проверки
    qDebug() << "Получено событий:" << events.size();
    for (const Article &event : events) {
        qDebug() << "Title:" << event.title << "| Category:" << event.full_text
                 << "| Start Date:" << event.date << "| End Date:" << event.author
                 << "| Is Peaceful:" << event.is_publish;
    }

    // Очистка памяти
    reply->deleteLater();

    // Возвращаем первый найденный event, либо пустой объект
    return events.isEmpty() ? Article() : events.first();
}



void ClientInterface::DeleteArticle(const unsigned int id)
{
    QUrl url("http://127.0.0.1:8000/article/" + QString::number(id));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->deleteResource(request);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно удалено. ID:" << id;
    } else {
        qDebug() << "Ошибка при удалении события:" << reply->errorString();
    }
    reply->deleteLater();
}

void ClientInterface::UpdateArticle(const unsigned int id)
{
    QJsonObject json;
    json["title"] = "Title1";
    json["full_text"] = "FullText1";
    json["date"] = "2025-02-20 18:56:00+05";
    json["author"] = "Author1";
    json["is_publish"] = true;


    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QUrl url("http://127.0.0.1:8000/article/" + QString::number(id));
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->sendCustomRequest(request, "PATCH", data);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно обновлено!";
        qDebug() << "Ответ сервера:" << reply->readAll();
    } else {
        qDebug() << "Ошибка при создании события:" << reply->errorString();
    }

    reply->deleteLater();
}


void ClientInterface::CreateArticle()
{
    QJsonObject json;
    json["title"] = "Title1";
    json["full_text"] = "FullText1";
    json["date"] = "2025-02-20 18:56:00+05";
    json["author"] = "Author1";
    json["is_publish"] = true;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QUrl url("http://127.0.0.1:8000/article");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_client->post(request, data);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Событие успешно создано!";
        qDebug() << "Ответ сервера:" << reply->readAll();
    } else {
        qDebug() << "Ошибка при создании события:" << reply->errorString();
    }

    reply->deleteLater();
}

void ClientInterface::GetArticle()
{
    QNetworkRequest request; ;
    request.setUrl(QUrl("http://127.0.0.1:8000/article"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = m_client->get(request);


    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();

    QByteArray responseData = reply->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);

    QList<Article> events;

    if (jsonDoc.isArray()) {
        QJsonArray jsonArray = jsonDoc.array();
        for (const QJsonValue &value : jsonArray) {
            if (value.isObject()) {
                events.append(Article::fromJson(value.toObject()));
            }
        }
    } else if (jsonDoc.isObject()) {
        events.append(Article::fromJson(jsonDoc.object()));
    } else {
        qDebug() << "Ошибка: Ожидался JSON-объект или массив!";
    }
    qDebug() << "Получено событий:" << events.size();
    for (const Article &event : events) {
        qDebug() << "Title:" << event.title << "| Category:" << event.full_text
                 << "| Start Date:" << event.date << "| End Date:" << event.author
                 << "| Is Peaceful:" << event.is_publish;
    }
    reply->deleteLater();
}
