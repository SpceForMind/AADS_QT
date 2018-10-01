#include "dilog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>

Dilog::Dilog(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout());
    QHBoxLayout *input_hlist = new QHBoxLayout();
    QHBoxLayout *input_elements = new QHBoxLayout();
    QHBoxLayout *output_hlist = new QHBoxLayout();
    QHBoxLayout *buttons = new QHBoxLayout();

    hlist = new QLineEdit(this);
    target = new QLineEdit(this);
    replacement = new QLineEdit(this);
    result = new QLabel(this);
    ok_b = new QPushButton("OK", this);
    exit_b = new QPushButton("Exit", this);

    input_hlist->addWidget(new QLabel("Write hierarchical list", this));
    input_hlist->addWidget(hlist);
    input_elements->addWidget(new QLabel("Write target", this));
    input_elements->addWidget(target);
    input_elements->addWidget(new QLabel("Write replacement", this));
    input_elements->addWidget(replacement);
    output_hlist->addWidget(new QLabel("Result ", this));
    output_hlist->addWidget(result);
    buttons->addWidget(ok_b);
    buttons->addWidget(exit_b);
    \
    layout()->addItem(input_hlist);
    layout()->addItem(input_elements);
    layout()->addItem(output_hlist);
    layout()->addItem(buttons);

    connect(exit_b, SIGNAL(clicked()), this, SLOT(close()));
}
