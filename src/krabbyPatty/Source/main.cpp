#include "Headers/widget.h"

#include <QApplication>
#include<QFile>
#include <QFontDatabase>
#include <QSplashScreen>
#include <QTimer>

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    a.setWindowIcon(QIcon(":/images/icon1.png"));

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png"));
    splash->show();

    QTimer::singleShot(5000,splash,SLOT(close()));
    QTimer::singleShot(5000,&w,SLOT(show()));

    delete splash;
    return a.exec();
}
