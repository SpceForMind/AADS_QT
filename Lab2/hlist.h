#ifndef HLIST_H
#define HLIST_H
#include <string>
#include <QApplication>
using namespace std;

struct HList
{
    char atom;
    struct HList *sublist;
    struct HList *next;
};

void append_sublist(HList **cur);
void append_atom(HList **cur, char atom);
void filling_list(HList **cur, bool *first_bracket, string &str, size_t &i);
void replace(HList *hlist, char target, char replacement);
void print_hlist(HList *hlist, QString &qstr);
void shell_print(HList *hlist, QString &qstr);
void delete_hlist(HList *hlist);

#endif // HLIST_H
