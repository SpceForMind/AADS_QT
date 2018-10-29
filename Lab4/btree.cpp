#include "btree.h"
#include <cstring>
#include <QDebug>
#include <cctype>
#include <QChar>

BTree::BTree()
{
    right = left = nullptr;
    item = nullptr;
}

BTree::~BTree()
{
    delete left;
    delete right;
    delete item;
}

//call with level = 0, right = false
void print_tree(BTree *root, QString &str, int level, bool right)
{
    if(root)
    {
        if(!right)
        {
            if(level!= 0)
                str += "\t";
            str += root->item;
        }
        else
        {
            str += "\n";
            for(int i = 0; i < level; ++i)
                str += "\t";
            str += root->item;
        }
        print_tree(root->left, str, level + 1, false);
        print_tree(root->right, str, level + 1, true);
    }
}
/*
void append(BTree **root, QString const &new_item)
{
    BTree *new_tree = new BTree;
    new_tree->item = new QString(new_item);
    //empty binary tree
    if(*root == nullptr)
    {
        *root = new_tree;
    }
    //root is't empty
    else
    {
        BTree *cur_tree = *root;
        while(cur_tree)
        {
            int cmp = strcmp(cur_tree->item->toStdString().c_str(), new_item.toStdString().c_str());
            //new item < current item
            if(cmp > 0)
            {
                if(!cur_tree->left)
                {
                    cur_tree->left = new_tree;
                    return;
                }
                else
                    cur_tree = cur_tree->left;
            }
            else if(cmp < 0)
            {
                if(!cur_tree->right)
                {
                    cur_tree->right = new_tree;
                    return;
                }
                else
                    cur_tree = cur_tree->right;
            }
            else
                qDebug() << "Item " << new_item << " already exists!";
        }
    }
}
*/

/*
 * index is current position in str
 * call function with ind = 0
*/
void btree_by_string(BTree **root, QString const &str, int &ind)
{
    if(ind >= str.length())
        return;
    //root is empty
    if(ind < str.length() && isalpha(str[ind].toLatin1()))
    {
        QString item;
        while(ind < str.length() && isalpha(str[ind].toLatin1()))
        {
            item += str[ind].toLatin1();
            ++ind;
        }
        *root = new BTree;
        (*root)->right = nullptr;
        (*root)->left = nullptr;
        (*root)->item = new QString(item);
    }
    if(ind < str.length() && str[ind].toLatin1() == '#')
    {
        (*root)->left = new BTree;
        (*root)->left->item = new QString('#');
        ++ind;
    }
    if(ind < str.length() && str[ind].toLatin1() == '(')
    {
        //empty tree
        if(*root == nullptr)
        {
            ++ind;
            btree_by_string(root, str, ind);
        }
        if(*root!= nullptr && (*root)->left == nullptr)
        {
            ++ind;
            btree_by_string(&(*root)->left, str, ind);
        }
        //only left tree
        if(ind < str.length() && str[ind] == ')')
        {
            ++ind;
            return;
        }
        ++ind;
        if(*root!= nullptr)
            btree_by_string(&(*root)->right, str, ind);
    }
    if(ind < str.length() && str[ind].toLatin1() == ')')
    {
        ++ind;
        return;
    }
}


//call with arguments cur_height = 0, max_height = -1
void height_of_three(BTree *root, int &cur_height, int &max_height)
{
    if(root)
    {
        ++cur_height;
        max_height = std::max(cur_height, max_height);
        height_of_three(root->left, cur_height, max_height);
        height_of_three(root->right, cur_height, max_height);
        --cur_height;
    }
}
