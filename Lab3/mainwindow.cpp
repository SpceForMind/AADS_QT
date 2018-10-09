#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "stack.h"
#include "help.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exit_b, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choise_b_clicked()
{
    bool correct_str = true;
    QString file_name;
    file_name = QFileDialog::getOpenFileName(this, "", "All files (*.*)");
    check_str(file_name, correct_str);
    if(correct_str)
        ui->result->setText("Correct");
    else
        ui->result->setText("Incorrect");
}

void MainWindow::on_actionhelp_b_triggered()
{
    Help *help = new Help(":/doc/", "index.htm");
    help->resize(450, 320);
    help->show();
}

void MainWindow::on_actionabout_triggered()
{
    About *about = new About(":/doc/", "about.htm");
    about->resize(450, 320);
    about->show();
}
