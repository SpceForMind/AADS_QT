#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include "help.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    root = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_select_file_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "", "All files (*.*)");
    create_tree_by_file(&root, filename);
    QString record_tree;
    print_tree(root, record_tree, 0, false);
    ui->scrollArea->setWidget(new QLabel(record_tree));
}


void MainWindow::on_delete_node_b_clicked()
{
  QString delete_key =  ui->delete_node_l->text();
  remove_key(&root, delete_key);
  QString record_tree;
  print_tree(root, record_tree, 0, false);
  ui->scrollArea->setWidget(new QLabel(record_tree));
}

void MainWindow::on_add_node_b_clicked()
{
    QString new_key = ui->add_node_l->text();
    insert(&root, new_key);
    QString record_tree;
    print_tree(root, record_tree, 0, false);
    ui->scrollArea->setWidget(new QLabel(record_tree));
}

void MainWindow::on_actionhelp_triggered()
{
    Help *help = new Help(":/doc/", "index.htm");
    help->resize(400, 400);
    help->show();
}



void MainWindow::on_actionabout_triggered()
{
    About *about = new About(":/doc/", "about.htm");
    about->resize(400, 450);
    about->show();
}
