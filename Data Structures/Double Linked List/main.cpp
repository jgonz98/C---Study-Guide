#include <iostream>
#include "dlinkedlist.h"

int main()
{
    DLinkedList<int> test;
    test.push_front(2);
    test.push_front(1);
    test.print_list();
    test.push_front(0);
    test.print_list();
    test.push_back(3);
    test.print_list();
    test.pop_back();
    test.print_list();
    test.pop_front();
    test.print_list();
    test.pop_front();
    test.pop_back();
    test.pop_back();
    test.print_list();
    test.push_back(3);
    test.print_list();
    return 0;
}