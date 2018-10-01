#include "hlist.h"
#include <cctype>
#include <QDebug>
using namespace std;

#include <cctype>
using namespace std;
QTextStream Qcout(stdout);

void append_sublist(HList **cur)
{
    //allocate memory for next element which was contain head of sublist
    HList *new_node = new HList;
    new_node->sublist = new HList;
    new_node->sublist->next = nullptr;
    new_node->sublist->sublist = nullptr;
    new_node->next = nullptr;
    //add in empty head
    if(*cur == nullptr)
        *cur = new_node;
    else
    {
        HList *cur_node = *cur;
        while(cur_node->next)
            cur_node = cur_node->next;
        cur_node->next = new_node;
    }
}

void  append_atom(HList **cur, char atom)
{
    //crate new node
    HList *new_node = new HList;
    new_node->next = nullptr;
    new_node->atom = atom;
    new_node->sublist = nullptr;
    //add new node in empty head
    if(*cur == nullptr)
        *cur = new_node;
    else
    {
        HList *cur_node = *cur;
        while(cur_node->next)
            cur_node = cur_node->next;
        cur_node->next = new_node;
    }
}


/*
    filling hierarchical list from input stream
    as (a(bc)d)
    first_bracket is var which needed for skip first bracket
    but not skip second and next, because it require for create sublists
*/
void filling_list(HList **cur, bool *first_bracket, string &str, size_t &i)
{

    char c = ' '; //contain currnent alpha
    //if cur character is eof - return
    while(c!= ')' && i < str.length())
    {
    c = str[i];
        while(c == ' ')
        {
            ++i;
        c = str[i];
        }
        if(*first_bracket)
        {
            *first_bracket = false;
            ++i;
            continue;
        }
        if(isalpha(c))
            append_atom(cur, c);
        //Head not empty
        else if(c == '(')
        {
            append_sublist(cur);
            HList *cur_node = *cur;
            while(cur_node->next)
                cur_node = cur_node->next;
            ++i;
            filling_list(&cur_node->sublist, first_bracket, str, i);
        }
        ++i;
    }
}


void replace(HList *hlist, char target, char replacement)
{
    HList *cur = hlist;
    while(cur)
    {
        if(cur->sublist == nullptr)
        {
            if(cur->atom == target)
                cur->atom = replacement;
        }
        else if(cur->sublist)
            replace(cur->sublist, target, replacement);
        cur = cur->next;
    }
}


void delete_hlist(HList *hlist)
{
    HList *cur = hlist;
    while(cur)
    {
        //atom
        if(!cur->sublist)
        {
            HList *time_cur = cur;
            cur = cur->next;
            delete time_cur;
        }
        //sublist
        else
        {
            delete_hlist(cur->sublist);
        }
        cur = cur->next;
    }
}

void print_hlist(HList *hlist, QString &qstr)
{
    HList *cur = hlist;
    while(cur)
    {
        if(cur->sublist == nullptr)
        {

            qstr +=  cur->atom;
            qstr += " ";
        }
        else if(cur->sublist)
        {
            qstr += "(";
            print_hlist(cur->sublist, qstr);
            qstr += ")";
        }
        cur = cur->next;
    }
}


void shell_print(HList *hlist, QString &qstr)
{
    qstr += "(";
    print_hlist(hlist, qstr);
    qstr += ")";
}

