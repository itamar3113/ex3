#include "Node.h"

template <typename T>
Node<T>::Node(T &data) : m_data(new T(data)),
                         m_next(NULL)
{
}

template <typename T>
&T Node<T>::getData(){
    return &m_data;
}

Node<T> getNext();
void setNext(Node next);
