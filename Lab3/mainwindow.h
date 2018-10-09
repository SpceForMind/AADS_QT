#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_choise_b_clicked();

    void on_actionhelp_b_triggered();

    void on_actionabout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
