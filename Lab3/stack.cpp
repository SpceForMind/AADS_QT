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

void check_str(QString const &file_name, bool &correct_str)
{
    QFile f(file_name);
    Stack *stack = nullptr;
    char c;
    if(f.exists() && f.open(QIODevice::ReadOnly))
    {
        while(!f.atEnd())
        {
            f.read(&c, 1);
            if(c!= 'C')
                push(&stack, c);
            else
            {
                char cur_el;
                f.read(&c, 1);
                while(pop(&stack, cur_el))
                {
                    if(cur_el!=  c)
                    {
                        correct_str = false;
                        return;
                    }
                    f.read(&c, 1);
                    if(f.atEnd())
                        return;
                }
                //string may was equal for some character but it length great than string from stack
                if(c!= 'D')
                {
                    correct_str = false;
                    return;
                }
            }
        }
    }
}
