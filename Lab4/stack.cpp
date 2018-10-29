#include "stack.h"
#include <QFile>

void push(Stack **stack, char new_item)
{
    Stack *new_node = new Stack;
    new_node->item = new_item;
    //empty stack
    if(*stack == nullptr)
    {
        new_node->next = nullptr;
        *stack = new_node;
    }
    //change stack - set new top node
    else
    {
        new_node->next = *stack;
        *stack = new_node;
    }
}

bool pop(Stack **stack, char &el)
{
    //empty stack
    if(*stack == nullptr)
        return false;
    else
    {
        el = (*stack)->item;
        Stack *time_top = *stack;
        *stack = time_top->next;
        delete time_top;
        return true;
    }
}

void check_str(QString const &file_name, QString &record_tree, bool &correct_data)
{
    QFile f(file_name);
    Stack *stack = nullptr;
    char c;
    if(f.exists() && f.open(QIODevice::ReadOnly))
    {
        while(!f.atEnd())
        {
            f.read(&c, 1);
            record_tree += c;
            if(c == '(')
                push(&stack, c);
            else if(c == ')')
                if(!pop(&stack, c))
                    correct_data = false;
        }
        //stack not empty
        if(stack!= nullptr)
            correct_data = false;
    }
}
