#ifndef AUTH_H
#define AUTH_H

#include <QDialog>
#include <QNetworkAccessManager>

namespace Ui {
class Auth;
}

class Auth : public QDialog
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    static bool isAuthorized();
    static QString loadToken();
    ~Auth();

private slots:
    void switchToRegisterForm();
    void switchToLoginForm();

private :
    void saveToken(const QString& token);
    void on_enterButton_clicked();
    void onReplyFinished();
    void on_enterRegButton_clicked();
    void onReplyFinished2();
    bool isPasssEqual(QString pass, QString confpass);
private:
    Ui::Auth *ui;
    QNetworkAccessManager *networkManager;
};

#endif // AUTH_H
