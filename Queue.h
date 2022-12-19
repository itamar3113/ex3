#ifndef QUEUE_H
#define QUEUE_H

#define EMPTY_LIST !m_head
#define ONE_ELEMENT_LIST m_head == m_tail
#define END_LIST !(m_current->m_next)
template <class T>
struct Node
{
	// todo encapsulation?
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
	class Iterator;

	Iterator begin() const;
	Iterator end() const;

	class EmptyQueue {} ;
	/*
	 * C'tor of generic empty Queue;
	 */
	Queue();

	/*
	 * copy c'tor of generic Queue;
	 */
	Queue(const Queue &other);

	// TODO need to change?
	~Queue() = default;
	// todo assignment operator

	/*
	 * Add element for the end of the queue
	 * @param data - the data for the queue
	 */
	void pushBack(const T &data);

	/*
	 * Get the frst element in the queue
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
Queue<T>::Queue(const Queue<T> &other) : m_head(other.m_head),
										 m_tail(other.m_tail)
{
}

template <class T>
void Queue<T>::pushBack(const T &data)
{
	if (EMPTY_LIST)
	{
		m_head = new Node<T>;
		m_head.m_data = data;
		m_head.m_next = nullptr;
	}
	else if (ONE_ELEMENT_LIST)
	{
		m_tail = new Node<T>;
		m_tail.m_data = data;
		m_tail.m_next = nullptr;
		m_head.m_next = m_tail;
	}
	else // more than one element
	{
		Node<T> insertNode = new Node<T>;
		insertNode.m_data = data;
		insertNode.m_next = nullptr;
		m_tail.m_next = insertNode;
		m_tail = insertNode;
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
int Queue<T>::size()
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
	Node<T> tmp = origin.m_head;
	while (tmp)
	{ // todo encapsulation?
		if (c(tmp.m_data))
		{
			filtered.pushBack(tmp.m_data);
		}
		tmp = tmp.m_next;
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
	Node<T> tmp = queue.m_head;
	while (tmp)
	{
		tmp.m_data = transformator(tmp.m_data);
		tmp = tmp.m_next;
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
	const T &operator*() const;
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
const T &Queue<T>::Iterator::operator*() const
{
	return m_current->m_data;
}

template <class T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++()
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
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int signal)
{
	Iterator result = *this;
	++*this;
	return result;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &other){
	//todo need to check == for nodes.
	return m_current == other.m_current;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const{
	return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const{
	return Iterator(nullptr);
}

#endif // QUEUE_H
