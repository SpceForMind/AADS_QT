#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "avltree.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    AvlTree *root;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_select_file_clicked();

    void on_delete_node_b_clicked();

    void on_add_node_b_clicked();

    void on_actionhelp_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
