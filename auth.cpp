#include "auth.h"
#include "ui_auth.h"
#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>

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

void Auth::saveToken(const QString& token) {
    QSettings settings("GameShopPlatform");
    settings.setValue("Authorization", token);
}

QString Auth::loadToken() {
    QSettings settings("GameShopPlatform");
    return settings.value("Authorization", "").toString();
}

void Auth::on_enterButton_clicked()
{
    ui->enterButton->setEnabled(false);
    QString login = ui->emailEdit->text();
    QString password = ui->passEdit->text();

    QUrl url("http://localhost:8080/auth/sign-in");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QJsonObject jsonData;
    jsonData["email"] = login;
    jsonData["password"] = password;

    QJsonDocument jsonDoc(jsonData);
    QByteArray json = jsonDoc.toJson();

    QNetworkReply *reply = networkManager->post(request, json);

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

            saveToken(token);

            this->close();

            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();
}

