#include "auth.h"
#include "ui_auth.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

Auth::Auth(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Auth)
{
    ui->setupUi(this);

    connect(ui->enterButton, &QPushButton::clicked, this, &Auth::on_enterButton_clicked);
    networkManager = new QNetworkAccessManager(this);
}

Auth::~Auth()
{
    delete ui;
}

bool Auth::isAuthorized() {
    return false;
}

void Auth::on_enterButton_clicked()
{
    QString login = ui->emailEdit->text();
    QString password = ui->passEdit->text();

    QUrl url("localhost:8080");
    QNetworkRequest request(url);

    QUrlQuery postData;
    postData.addQueryItem("username", login);
    postData.addQueryItem("password", password);

    QNetworkReply *reply = networkManager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, this, &Auth::onReplyFinished);
}

void Auth::onReplyFinished() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();
            QString token = jsonObject["token"].toString();
            qDebug() << "Token:" << token;
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

