#include <iostream>
#include "slinkedlist.h"

int main()
{
    SLinkedList<int> test;
    test.push_front(1);
    test.push_front(2);
    test.print_list();
    test.pop_front();
    test.print_list();
    test.push_back(3);
    test.print_list();
    test.pop_back();
    test.print_list();
    test.pop_front();
    test.push_front(2);
    test.print_list();
    test.pop_front();
    test.push_back(3);
    test.push_back(3);
    test.print_list();
    return 0;
}