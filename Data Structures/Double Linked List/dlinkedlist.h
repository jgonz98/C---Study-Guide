#include <cstddef>
#include <iostream>

template <typename E>
class DLinkedList;

template <typename E>
class DNode
{
private:
    E data;
    DNode<E> *next;
    DNode<E> *prev;
    friend class DLinkedList<E>;
};

template <typename E>
class DLinkedList
{
public:
    DLinkedList();
    ~DLinkedList();
    E &front();
    E &back();
    void push_front(const E &element);
    void push_back(const E &element);
    void pop_front();
    void pop_back();
    bool empty();
    void print_list();
    void remove(DNode<E> *current);

private:
    DNode<E> *head;
    DNode<E> *tail;
};

template <typename E>
DLinkedList<E>::DLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename E>
E &DLinkedList<E>::front()
{
    return head->data;
}

template <typename E>
E &DLinkedList<E>::back()
{
    return tail->data;
}

template <typename E>
void DLinkedList<E>::remove(DNode<E> *current)
{
    if (current == nullptr)
    {
        return;
    }
    if (current == tail && current == head)
    {
        delete current;
        tail = nullptr;
        head = nullptr;
        return;
    }
    DNode<E> *n;
    DNode<E> *p;
    short int flag = 2;
    flag = current == head ? 0 : flag;
    flag = current == tail ? 1 : flag;

    switch (flag)
    {
    case 0: //Remove head
        n = current->next;
        delete head;
        head = n;
        head->prev = nullptr;
        return;
    case 1: //Remove tail
        p = current->prev;
        p->next = nullptr;
        delete tail;
        tail = p;
        return;
    default:
        n = current->next;
        p = current->prev;
        p->next = n;
        n->prev = p;
        delete current;
        break;
    }
}

template <typename E>
void DLinkedList<E>::push_front(const E &element)
{
    DNode<E> *e = new DNode<E>;
    e->data = element;
    e->next = head;
    e->prev = nullptr;
    if (head == nullptr)
        tail = e;
    head = e;
}

template <typename E>
void DLinkedList<E>::pop_front()
{
    remove(head);
}

template <typename E>
void DLinkedList<E>::push_back(const E &element)
{
    DNode<E> *e = new DNode<E>;
    e->data = element;
    e->prev = tail;
    e->next = nullptr;

    if (head == nullptr)
    {
        head = e;
        tail = e;
        return;
    }
    tail->next = e;
    tail = e;
}

template <typename E>
void DLinkedList<E>::pop_back()
{
    remove(tail);
}

template <typename E>
bool DLinkedList<E>::empty()
{
    return (head == nullptr);
}

template <typename E>
DLinkedList<E>::~DLinkedList()
{
    while (!empty()) // pop elements until empty
    {
        pop_front();
    }
}

template <typename E>
void DLinkedList<E>::print_list()
{
    DNode<E> *traverse = head;
    while (traverse != nullptr) // Traverse dlinked list and print until pointer is nullptr aka end of list
    {
        std::cout << traverse->data << " ";

        traverse = (traverse->next == nullptr) ? nullptr : traverse->next;
    }
    std::cout << std::endl;
}