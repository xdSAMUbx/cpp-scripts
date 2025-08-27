#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *link;
};

int main()
{
    Node<double> *A;
    A = nullptr;
    Node<double> *temp = new Node<double>{1.0, nullptr};
    A = temp;
    delete A;
    A = nullptr;
    temp = nullptr;
    return 0;
}
