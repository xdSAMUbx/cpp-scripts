#include <iostream>

template <typename T>
struct Node
{
    T x;
    Node *next;
};

template <typename T>
Node<T> *init(const T &val)
{
    Node<T> *head = new Node<T>{val, nullptr};
    return head;
}

template <typename T>
void insertOnce(Node<T> *&head, const T &val)
{
    Node<T> *temp = new Node<T>{val, nullptr};
    head->next = temp;
}

template <typename T>
void finish(Node<T> *&head)
{
    while (head->next != nullptr)
    {
        Node<T> *temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
}

int main()
{
    double val = 1.0;
    Node<double> *head = init(val);
    insertOnce(head, 2.);
    finish(head);
    return 0;
}