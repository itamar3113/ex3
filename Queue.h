#ifndef QUEUE_H
#define QUEUE_H

#define EMPTY_LIST !m_head
#define ONE_ELEMENT_LIST m_head == m_tail

template <class T>
struct Node {
    T m_data;
    Node m_next;
};

template <class T>
class Queue
{
private:
    Node<T> m_head;
    Node<T> m_tail;

public:
    /*
    * C'tor of generic empty Queue;
    */
    Queue();

    /*
    * copy c'tor of generic Queue;
    */
    Queue(const Queue& other);


    // TODO need to change?
    ~Queue() = default;
    //todo assignment operator
    
    /*
    * Add element for the end of the queue
    * @param data - the data for the queue
    */
    void pushBack(const T& data);

    /*
    * Get the frst element in the queue
    * @return refrance for the first element
    */
    T* front();

    /*
    * pop the first elemnt in the list
    */
    void popFront();

    /*
    * @return the size of the queue
    */
    int size();

};

template <class T>
Queue<T>::Queue():  m_head(nullptr),
                    m_tail(nullptr)
                    { } 

template <class T>
Queue<T>::Queue(const Queue<T>& other):
                    m_head(other.m_head),
                    m_tail(other.m_tail)
                    { }   

template <class T>
void Queue<T>::pushBack(const T& data)
{
    if(EMPTY_LIST)
    {
        m_head = new Node<T> ;
        m_head.m_data = data;
        m_head.m_next = nullptr;
    }
    else if(ONE_ELEMENT_LIST)
    {
        m_tail = new Node<T>;
        m_tail.m_data = data;
        m_tail.m_next = nullptr;
        m_head.m_next = m_tail; 
    }
    else // more than one element
    {
        Node<T>* insertNode = new Node<T>;
        insertNode.m_data = data;
        insertNode.m_next = nullptr;
        m_tail.m_next = insertNode;
        m_tail = insertNode;
    }
}


template <class T>
T* Queue<T>::front()
{
    return *(m_head.m_data);
}

template <class T>
void Queue<T>::popFront()
{
    m_head = m_head.m_next;
}

template <class T>
int Queue<T>::size()
{
    if(EMPTY_LIST) {
        return 0;
    }
    if(ONE_ELEMENT_LIST) {
        return 1;
    }

    int cnt = 1;
    Node<T> tmp = m_head;
    while(tmp.m_next)
    {
        cnt++;
        tmp = tmp.m_next;
    }
    return cnt;
}


#endif //QUEUE_H
