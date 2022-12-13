#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
    T m_data;
    Node<T> m_next;

public:
    Node<T>(T &data);
    //todo should be default?
    Node<T>(const Node<T> &) = default;
    ~Node() = default;
    T getData();
    Node<T> getNext();
    void setNext(Node next);
};

#endif
