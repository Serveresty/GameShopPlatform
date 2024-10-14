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

QT_BEGIN_NAMESPACE

class Ui_Auth
{
public:
    QPushButton *enterButton;
    QLineEdit *emailEdit;
    QLineEdit *passEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName("Auth");
        Auth->resize(700, 350);
        enterButton = new QPushButton(Auth);
        enterButton->setObjectName("enterButton");
        enterButton->setGeometry(QRect(270, 250, 160, 30));
        emailEdit = new QLineEdit(Auth);
        emailEdit->setObjectName("emailEdit");
        emailEdit->setGeometry(QRect(230, 100, 240, 24));
        passEdit = new QLineEdit(Auth);
        passEdit->setObjectName("passEdit");
        passEdit->setGeometry(QRect(230, 175, 240, 24));
        passEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(Auth);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 80, 49, 16));
        label_2 = new QLabel(Auth);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 155, 49, 16));

        retranslateUi(Auth);

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QDialog *Auth)
    {
        Auth->setWindowTitle(QCoreApplication::translate("Auth", "Dialog", nullptr));
        enterButton->setText(QCoreApplication::translate("Auth", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        passEdit->setText(QString());
        label->setText(QCoreApplication::translate("Auth", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("Auth", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
