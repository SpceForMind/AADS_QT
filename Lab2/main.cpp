#include "mainwindow.h"
#include "dilog.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QDebug>

using namespace std;

#define OPEN_BRACKET "("
#define CLOSED_BRACKET ")"


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Dilog *d = qobject_cast<Dilog *>(w.centralWidget());
    QObject::connect(d->ok_b, SIGNAL(clicked()), &w, SLOT(ok_btn_action()));

    return a.exec();
}

