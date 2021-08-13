
#include <iostream>
#include <cstdio>

template <typename T>
class Stack;

template <typename T>
class SNode
{
private:
    T data;
    SNode<T> *next;
    friend class Stack<T>;
};

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    T &top();
    void push(T element);
    void pop();
    void print();

private:
    SNode<T> *tos;
};

template <typename T>
Stack<T>::Stack()
{
    tos = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while (tos != nullptr)
        pop();
}

template <typename T>
T &Stack<T>::top()
{
    return tos;
}

template <typename T>
void Stack<T>::push(T element)
{
    SNode<T> *e = new SNode<T>;
    e->data = element;
    e->next = tos;
    tos = e;
}

template <typename T>
void Stack<T>::pop()
{
    SNode<T> *e = new SNode<T>;
    e = tos->next;
    delete tos;
    tos = e;
}

template <typename T>
void Stack<T>::print()
{
    SNode<T> *traverse = tos;
    while (traverse != nullptr)
    {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
    std::cout << std::endl;
}