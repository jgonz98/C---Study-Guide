#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> test;
    test.push(3);
    test.print();
    test.push(2);
    test.print();
    test.push(1);
    test.print();
    test.pop();
    test.print();
    test.push(1);
    test.print();
}