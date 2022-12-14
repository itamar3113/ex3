#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
    T m_data;
    Node<T> m_next;

public:
    Node<T>(T &data):   m_data(new T(data)),
                        m_next(NULL)
                        { }
    //todo should be default?
    Node<T>(const Node<T> &) = default;
    ~Node() = default;

    template <typename T>
    &T Node<T>::getData()
    {
        return &m_data;
    }

    template <typename T>
    Node<T> Node<T>::getNext()
    {
        return &m_next;
    }

    template <typename T>
    void Node<T>::setNext(Node next)
    {
        m_next = next;
    }
};

#endif
