#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Auth au;
    au.show();
    return a.exec();
}
