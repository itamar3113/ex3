#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{

public:
    /*
    * C'tor of generic node with recived data and NULL as next
    */
    Node(T &data);
    /*
    * Copy c'tor of generic node 
    */
    Node(const Node& other);
    //todo assignment operator
    
    ~Node();

    T& getData() const;

    Node getNext() const;

    void setNext(Node next);

private:
    T m_data;
    Node<T> m_next;
};

template <class T>
Node<T>::Node(T &data):   m_data(new T(data)),
                    m_next(nullptr)
                    { }

template <class T>
Node<T>::Node(const Node<T> & other):
                    m_data(new T(other.getData())),
                    m_next(new T(other.getNext()))
                    { }

template <class T>
Node<T>::~Node()
{
    delete m_data;
}

template <class T>
T& Node<T>::getData() const
{
    return &m_data;
}

template <class T>
Node<T> Node<T>::getNext() const
{
    return &m_next;
}

template <class T>
void Node<T>::setNext(Node next)
{
    m_next = next;
}
#endif //NODE_H
