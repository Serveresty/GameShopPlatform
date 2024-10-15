/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Auth
{
public:
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QLineEdit *emailEdit;
    QLineEdit *passEdit;
    QLabel *emailLabel;
    QLabel *passLabel;
    QPushButton *enterButton;
    QPushButton *switchToRegisterButton;
    QLabel *loginLabel;
    QWidget *registerPage;
    QPushButton *switchToLoginButton;
    QPushButton *enterRegButton;
    QLineEdit *passRegEdit;
    QLabel *passRegLabel;
    QLabel *emailRegLabel;
    QLineEdit *emailRegEdit;
    QLabel *regLabel;
    QLineEdit *confirmPassRegEdit;
    QLabel *passRegLabel_2;

    void setupUi(QDialog *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName("Auth");
        Auth->resize(700, 350);
        stackedWidget = new QStackedWidget(Auth);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 700, 350));
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        emailEdit = new QLineEdit(loginPage);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(230, 100, 240, 24));
        passEdit = new QLineEdit(loginPage);
        passEdit->setObjectName("passEdit");
        passEdit->setGeometry(QRect(230, 175, 240, 24));
        passEdit->setEchoMode(QLineEdit::EchoMode::Password);
        emailLabel = new QLabel(loginPage);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(230, 80, 49, 16));
        passLabel = new QLabel(loginPage);
        passLabel->setObjectName("passLabel");
        passLabel->setGeometry(QRect(230, 155, 49, 16));
        enterButton = new QPushButton(loginPage);
        enterButton->setObjectName("enterButton");
        enterButton->setGeometry(QRect(270, 250, 160, 30));
        switchToRegisterButton = new QPushButton(loginPage);
        switchToRegisterButton->setObjectName("switchToRegisterButton");
        switchToRegisterButton->setGeometry(QRect(600, 310, 80, 24));
        loginLabel = new QLabel(loginPage);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(235, 20, 230, 40));
        QFont font;
        font.setPointSize(25);
        loginLabel->setFont(font);
        loginLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        loginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(loginPage);
        registerPage = new QWidget();
        registerPage->setObjectName("registerPage");
        switchToLoginButton = new QPushButton(registerPage);
        switchToLoginButton->setObjectName("switchToLoginButton");
        switchToLoginButton->setGeometry(QRect(600, 310, 80, 24));
        enterRegButton = new QPushButton(registerPage);
        enterRegButton->setObjectName("enterRegButton");
        enterRegButton->setGeometry(QRect(270, 250, 160, 30));
        passRegEdit = new QLineEdit(registerPage);
        passRegEdit->setObjectName("passRegEdit");
        passRegEdit->setGeometry(QRect(230, 160, 240, 24));
        passRegEdit->setEchoMode(QLineEdit::EchoMode::Password);
        passRegLabel = new QLabel(registerPage);
        passRegLabel->setObjectName("passRegLabel");
        passRegLabel->setGeometry(QRect(230, 140, 49, 16));
        emailRegLabel = new QLabel(registerPage);
        emailRegLabel->setObjectName("emailRegLabel");
        emailRegLabel->setGeometry(QRect(230, 80, 49, 16));
        emailRegEdit = new QLineEdit(registerPage);
        emailRegEdit->setObjectName("emailRegEdit");
        emailRegEdit->setGeometry(QRect(230, 100, 240, 24));
        regLabel = new QLabel(registerPage);
        regLabel->setObjectName("regLabel");
        regLabel->setGeometry(QRect(235, 20, 230, 40));
        regLabel->setFont(font);
        regLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        regLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        confirmPassRegEdit = new QLineEdit(registerPage);
        confirmPassRegEdit->setObjectName("confirmPassRegEdit");
        confirmPassRegEdit->setGeometry(QRect(230, 210, 240, 24));
        confirmPassRegEdit->setEchoMode(QLineEdit::EchoMode::Password);
        passRegLabel_2 = new QLabel(registerPage);
        passRegLabel_2->setObjectName("passRegLabel_2");
        passRegLabel_2->setGeometry(QRect(230, 190, 101, 16));
        stackedWidget->addWidget(registerPage);

        retranslateUi(Auth);

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QDialog *Auth)
    {
        Auth->setWindowTitle(QCoreApplication::translate("Auth", "Dialog", nullptr));
        passEdit->setText(QString());
        emailLabel->setText(QCoreApplication::translate("Auth", "Email", nullptr));
        passLabel->setText(QCoreApplication::translate("Auth", "Password", nullptr));
        enterButton->setText(QCoreApplication::translate("Auth", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        switchToRegisterButton->setText(QCoreApplication::translate("Auth", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginLabel->setText(QCoreApplication::translate("Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        switchToLoginButton->setText(QCoreApplication::translate("Auth", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        enterRegButton->setText(QCoreApplication::translate("Auth", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        passRegEdit->setText(QString());
        passRegLabel->setText(QCoreApplication::translate("Auth", "Password", nullptr));
        emailRegLabel->setText(QCoreApplication::translate("Auth", "Email", nullptr));
        regLabel->setText(QCoreApplication::translate("Auth", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        confirmPassRegEdit->setText(QString());
        passRegLabel_2->setText(QCoreApplication::translate("Auth", "Confirm Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
