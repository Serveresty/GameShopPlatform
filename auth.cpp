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
    connect(ui->enterRegButton, &QPushButton::clicked, this, &Auth::on_enterRegButton_clicked);
    connect(ui->switchToRegisterButton, &QPushButton::clicked, this, &Auth::switchToRegisterForm);
    connect(ui->switchToLoginButton, &QPushButton::clicked, this, &Auth::switchToLoginForm);
    networkManager = new QNetworkAccessManager(this);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::switchToRegisterForm() {
    ui->stackedWidget->setCurrentWidget(ui->registerPage);
}

void Auth::switchToLoginForm() {
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
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
        ui->enterButton->setEnabled(true);
    }
    reply->deleteLater();
}

void Auth::on_enterRegButton_clicked()
{
    ui->enterRegButton->setEnabled(false);
    QString login = ui->emailRegEdit->text();
    QString password = ui->passRegEdit->text();
    QString confPass = ui->confirmPassRegEdit->text();

    if (!isPasssEqual(password, confPass)) {
        ui->enterRegButton->setEnabled(true);
        return;
    }

    QUrl url("http://localhost:8080/auth/sign-up");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QJsonObject jsonData;
    jsonData["email"] = login;
    jsonData["password"] = password;

    QJsonDocument jsonDoc(jsonData);
    QByteArray json = jsonDoc.toJson();

    QNetworkReply *reply = networkManager->post(request, json);

    connect(reply, &QNetworkReply::finished, this, &Auth::onReplyFinished2);
}

void Auth::onReplyFinished2() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        if (jsonResponse.isObject()) {
            QJsonObject jsonObject = jsonResponse.object();
            QString msg = jsonObject["message"].toString();
            qDebug() << msg;

            ui->emailRegEdit->clear();
            ui->passRegEdit->clear();
            ui->confirmPassRegEdit->clear();

            switchToLoginForm();
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }
    ui->enterRegButton->setEnabled(true);
    reply->deleteLater();
}

bool Auth::isPasssEqual(QString pass, QString confpass) {
    if (pass == confpass) {
        return true;
    }

    return false;
}
