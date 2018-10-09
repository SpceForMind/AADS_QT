#ifndef STACK_H
#define STACK_H
#include <QString>

struct Stack
{
    char item;
    struct Stack *next;
};

void push(Stack **stack, char new_item);
bool pop(Stack **stack, char &el);
void check_str(QString const &file_name, bool &correct_str);

#endif // STACK_H
