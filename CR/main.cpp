#include "mainwindow.h"
#include <QApplication>
#include "avltree.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    AvlTree *root = nullptr;
    insert(&root, "abc");
    insert(&root, "bhj");
    insert(&root, "jhre");
    qDebug() << root;
    qDebug() << root->left;
    qDebug() << root->right;
    */
    MainWindow w;
    w.show();

    return a.exec();
}
