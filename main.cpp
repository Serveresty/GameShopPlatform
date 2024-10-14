#include "mainwindow.h"
#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!Auth::isAuthorized()) {
        Auth au;
        au.show();
        return a.exec();
    } else {
        MainWindow w;
        w.show();
        return a.exec();
    }
    return 0;
}
