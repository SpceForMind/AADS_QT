#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stack.h"
#include "btree.h"
#include "help.h"
#include "about.h"
#include <QFileDialog>
#include <QLabel>
#include <string>
#include <algorithm>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choise_b_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "", "All files (*.*)");
    bool correct_data = true;
    QString record_tree;
    check_str(file_name, record_tree, correct_data);
    string s_record_tree = record_tree.toStdString();
    //delete all space from string
    s_record_tree.erase(remove(s_record_tree.begin(), s_record_tree.end(),' '), s_record_tree.end());
    record_tree = QString::fromStdString(s_record_tree);
   if(!correct_data)
   {
        ui->height_l->setText("Programm error: ");
        ui->scrollArea->setWidget(new QWidget());
        ui->result_t->setText("Incorrect data from file");
   }
   else
   {
        int ind = 0;
        BTree *root = nullptr;
        btree_by_string(&root, record_tree, ind);
        int max_height = -1;
        int cur_height = 0;
        height_of_three(root, cur_height, max_height);
        ui->height_l->setText("Height");
        ui->result_t->setText(QString::number(max_height));
        QString label_tree;
        print_tree(root, label_tree, 0, false);
        QLabel *label = new QLabel(label_tree);
        ui->scrollArea->setWidget(label);

    }
}

void MainWindow::on_actionhelp_triggered()
{
    Help *help = new Help(":/doc/", "index.htm");
    help->resize(450, 450);
    help->show();
}


void MainWindow::on_actionabout_triggered()
{
    About *about = new About(":/doc/", "about.htm");
    about->resize(450, 450);
    about->show();
}
