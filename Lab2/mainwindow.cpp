#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dilog.h"
#include <QDebug>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hlist = nullptr;
    create_form();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_form()
{
        Dilog *dilog = new Dilog();
        setCentralWidget(dilog);
}

void MainWindow::ok_btn_action()
{
    Dilog *d = qobject_cast<Dilog *>(centralWidget());
    bool first_bracket = true;
    size_t i = 0;
    //freeing memory for create new or like this hierarchical list
    delete_hlist(hlist);
    hlist = nullptr;
    std::string str = d->hlist->text().toUtf8().constData();
    filling_list(&this->hlist, &first_bracket, str, i);
    replace(hlist, d->target->text().toUtf8().constData()[0], d->replacement->text().toUtf8().constData()[0]);
    QString qstr;
    shell_print(hlist, qstr);
    d->result->setText(qstr);
}
