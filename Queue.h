#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

#define EMPTY_LIST !m_head
#define ONE_ELEMENT_LIST m_head == m_tail
#define END_LIST !(m_current->m_next)

template <class T>
class Queue
{
private:

	template <class U>
	struct Node
	{
		// todo encapsulation?
		U m_data;
		Node* m_next;
		Node(const U& data, Node* next = nullptr): m_data(data), m_next(next) {};
	};

	Node<T>* m_head;
	Node<T>* m_tail;

public:
	class Iterator;
	class ConstIterator;

	Iterator begin() ;
	Iterator end() ;
	ConstIterator begin() const;
	ConstIterator end() const;

	class EmptyQueue {} ;
	/*
	 * C'tor of generic empty Queue;
	 */
	Queue();

	/*
	 * copy c'tor of generic Queue;
	 */
	Queue(const Queue &other);

	/*
	* Destractor of queue
	*/
	~Queue();

	/*
	* delete all elements of the queue
	*/
	void clear();

	/*
	* Assignment operator of queue
	*/
	Queue& operator=(const Queue&);

	/*
	 * Add element for the end of the queue
	 * @param data - the data for the queue
	 */
	void pushBack(const T &data);

	/*
	 * Get the first element in the queue
	 * @return refrance for the first element
	 */
	T front();

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
Queue<T>::Queue() : m_head(nullptr),
					m_tail(nullptr)
{
}

template <class T>
Queue<T>::Queue(const Queue<T> &other) : m_head(nullptr),
										 m_tail(nullptr)
{
	Node<T>* tmp = other.m_head;
	while(tmp)
	{
		pushBack(tmp->m_data);
		tmp = tmp->m_next;
	}
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if(this == &other)
	{
		return *this;
	}
	this.clear();
	Node<T>* tmp = other.m_head;
	while(tmp)
	{
		pushBack(tmp->m_data);
		tmp = tmp->m_next;
	}
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	this.clear();
}

template <class T>
void Queue<T>::clear()
{
	Node<T>* deleteNode = m_head;

	while(deleteNode)
	{
		m_head = m_head->m_next;
		delete deleteNode;
		deleteNode = m_head;
	}
}

template <class T>
void Queue<T>::pushBack(const T &data)
{
	try
	{
		Node<T> insertNode = new Node<T>(data);
		if (EMPTY_LIST)
		{
			m_head = insertNode;
			m_tail = insertNode;
		}
		else // at least one element
		{
			m_tail->m_next = insertNode;
			m_tail = insertNode;
		}
	}
	catch (std::bad_alloc& e)
	{
		this.clear();
		throw;
	}
}

template <class T>
T Queue<T>::front()
{
	if(EMPTY_LIST)
	{
		throw EmptyQueue();
	}
	return &(m_head.m_data);
}

template <class T>
void Queue<T>::popFront()
{
	if(EMPTY_LIST)
	{
		throw EmptyQueue();
	}
	m_head = m_head.m_next;
}

template <class T>
int Queue<T>::size() //todo implement with iterator
{
	if (EMPTY_LIST)
	{
		return 0;
	}
	if (ONE_ELEMENT_LIST)
	{
		return 1;
	}

	int cnt = 1;
	Node<T> tmp = m_head;
	while (tmp.m_next)
	{
		cnt++;
		tmp = tmp.m_next;
	}
	return cnt;
}

/**
 * Filter the queue members and return queue only wirh those who meet the condition.
 * @param origin - the queue that we want to filter.
 * @param c - the condition of the filter.
 */
template <class T, class Condition>
Queue<T> filter(Queue<T> &origin, Condition c)
{
	Queue<T> filtered;
	for(typename Queue<T>::ConstIterator i = origin.begin(); i != origin.end(); ++i)
	{
		if (c(*i))
		{
			filtered.pushBack(*i);
		}
	}
	return filtered;
}

/**
	 * Changes all queue members according to the transformator.
	@param queue - the queue we want to change.
	@param transformator - the operation to change the queue members
	*/
template <class T, class Transformator>
void transform(Queue<T> &queue, Transformator transformator)
{
	for(typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i)
	
	{
		*i = transformator(*i);
	}
}

template <class T>
class Queue<T>::Iterator
{
private:
	Node<T> *m_current;
	Iterator(const Node<T> *current);
	friend class Queue;

public:
	T &operator*() const;
	Iterator &operator++();
	Iterator operator++(int);
	bool operator!=(const Iterator &other);
	
	class InvalidOperation {};
};

template <class T>
Queue<T>::Iterator::Iterator(const Node<T> *current) : m_current(current)
{
}

template <class T>
T &Queue<T>::Iterator::operator*() const
{
	return m_current->m_data;
}

template <class T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++()
{
	if(END_LIST)
	{
		//should be clear here??
		throw InvalidOperation();
	}
	m_current = m_current->m_next;
	return *this;
}

// needed in linked list?
template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int signal)
{
	Iterator result = *this;
	++*this;
	return result;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &other){
	//todo need to check == for nodes.
	return *this != *other;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin(){
	return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end(){
	return Iterator(nullptr);
}

template <class T>
class Queue<T>::ConstIterator
{
private:
	Node<T> *m_current;
	ConstIterator(const Node<T> *current);
	friend class Queue;

public:
	const T &operator*() const;
	ConstIterator &operator++();
	ConstIterator operator++(int);
	bool operator!=(const ConstIterator &other);
	
	class InvalidOperation {};
};

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Node<T> *current) : m_current(current)
{
}

template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
	return m_current->m_data;
}

template <class T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++()
{
	if(END_LIST)
	{
		throw InvalidOperation();
	}
	m_current = m_current->m_next;
	return *this;
}

// needed in linked list?
template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int signal)
{
	Iterator result = *this;
	++*this;
	return result;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &other){
	//todo need to check == for nodes.
	return *this != *other;
}
//Return constIterator od Iterator?
template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const{
	return ConstIterator(m_head);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const{
	return ConstIterator(nullptr);
}

#endif // QUEUE_H
