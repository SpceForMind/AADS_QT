#include "mainwindow.h"
#include <QApplication>
#include "btree.h"
#include <QDebug>
#include"stack.h"
#include <string>
using namespace std;

string removeSpaces(string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
