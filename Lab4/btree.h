#ifndef BTREE_H
#define BTREE_H
#include <QString>

struct BTree
{
    QString *item;
    BTree *left;
    BTree *right;
    BTree();
    ~BTree();
};

void append(BTree **root, QString const &item);
void print_tree(BTree *root, QString &str, int level, bool right);
void height_of_three(BTree *root, int &cur_height, int &max_height);
void btree_by_string(BTree **root, QString const &str, int &ind);
#endif // BTREE_H
