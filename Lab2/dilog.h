#ifndef DILOG_H
#define DILOG_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class Dilog : public QWidget
{
    Q_OBJECT
public:
    QLineEdit *hlist;
    QLineEdit *target;
    QLineEdit *replacement;
    QLabel *result;
    QPushButton *ok_b;
    QPushButton *exit_b;
    explicit Dilog(QWidget *parent = nullptr);

signals:
public slots:
};

#endif // DILOG_H
