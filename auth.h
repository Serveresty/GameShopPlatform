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
    void on_enterButton_clicked();
    void onReplyFinished();

private :
    void saveToken(const QString& token);
private:
    Ui::Auth *ui;
    QNetworkAccessManager *networkManager;
};

#endif // AUTH_H
