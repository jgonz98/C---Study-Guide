#include <cstddef>
#include <iostream>

template <typename E>
class SLinkedList;

template <typename E>
class SNode
{
private:
    E data;
    SNode<E> *next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList
{
public:
    SLinkedList();
    ~SLinkedList();
    E &front();
    void push_front(const E &element);
    void push_back(const E &element);
    void pop_front();
    void pop_back();
    bool empty();
    void print_list();

private:
    SNode<E> *head;
};

template <typename E>
SLinkedList<E>::SLinkedList()
{
    head = nullptr;
}

template <typename E>
E &SLinkedList<E>::front()
{
    return head->data;
}

template <typename E>
void SLinkedList<E>::push_front(const E &element)
{
    SNode<E> *e = new SNode<E>;
    e->data = element;
    e->next = head;
    head = e;
}

template <typename E>
void SLinkedList<E>::pop_front()
{
    SNode<E> *temp = new SNode<E>;
    temp = head;
    if (temp->next == nullptr)
    {
        head = nullptr;
        delete temp;
        return;
    }
    head = head->next;
    delete temp;
}

template <typename E>
void SLinkedList<E>::push_back(const E &element)
{
    SNode<E> *e = new SNode<E>;
    e->data = element;
    e->next = nullptr;

    if (head == nullptr)
    {
        head = e;
        return;
    }

    SNode<E> *traverse = new SNode<E>;
    traverse = head;

    while (traverse->next != nullptr)
    {
        traverse = traverse->next;
    }
    traverse->next = e;
}

template <typename E>
void SLinkedList<E>::pop_back()
{
    SNode<E> *traverse = new SNode<E>;
    traverse = head;

    if (traverse == nullptr) // If no elements in slinked list return
        return;
    if (traverse->next == nullptr) // If only one element delete and set head to nullptr
    {
        delete traverse;
        head = nullptr;
        return;
    }
    while (traverse->next->next != nullptr) // Traverse slinked list until 2nd to last element or the next element has a next of nullptr
    {
        traverse = traverse->next;
    }
    delete traverse->next;
    traverse->next = nullptr;
}

template <typename E>
bool SLinkedList<E>::empty()
{
    return (head == nullptr);
}

template <typename E>
SLinkedList<E>::~SLinkedList()
{
    while (!empty()) // pop elements until empty
    {
        pop_front();
    }
}

template <typename E>
void SLinkedList<E>::print_list()
{
    SNode<E> *traverse = head;
    while (traverse != nullptr) // Traverse slinked list and print until pointer is nullptr aka end of list
    {
        std::cout << traverse->data << " ";
        traverse = traverse->next;
    }
    std::cout << std::endl;
}