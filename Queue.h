#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#define EMPTY_LIST m_size == 0
#define ONE_ELEMENT_LIST m_size == 1
#define END_LIST !(m_current)

template <class T>
class Queue
{
private:
	template <class U>
	struct Node
	{
		U m_data;
		Node *m_next;
		Node(const U &data, Node *next = nullptr) : m_data(data), m_next(next){};
	};

	Node<T> *m_head;
	Node<T> *m_tail;
	int m_size;

public:
	class Iterator;
	class ConstIterator;

	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;

	class EmptyQueue
	{
	};
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
	Queue &operator=(const Queue &);

	/*
	 * Add element for the end of the queue
	 * @param data - the data for the queue
	 */
	void pushBack(const T &data);

	/*
	 * Get the first element in the queue
	 * @return refrance for the first element
	 */
	// todo the test demand this to be const
	const T &front() const;

	T &front();

	/*
	 * pop the first elemnt in the list
	 */
	void popFront();

	/*
	 * @return the size of the queue
	 */
	int size() const;
};

template <class T>
Queue<T>::Queue() : m_head(nullptr),
					m_tail(nullptr),
					m_size(0)
{
}

template <class T>
Queue<T>::Queue(const Queue<T> &other) : m_head(nullptr),
										 m_tail(nullptr),
										 m_size(0)
{
	Node<T> *tmp = other.m_head;
	try
	{
		while (tmp)
		{
			pushBack(tmp->m_data);
			tmp = tmp->m_next;
		}
	}
	catch (const std::bad_alloc &e)
	{
		(*this).clear();
		throw e;
	}
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &other)
{
	if (this == &other)
	{
		return *this;
	}
	Queue<T> copy;
	Node<T> *curr = other.m_head;
	while (curr)
	{
		try
		{
			copy.pushBack(curr->m_data);
			curr = curr->m_next;
		}
		catch (const std::bad_alloc &e)
		{
			copy.clear();
			throw e;
		}
	}

	// Swap the contents of the temporary queue and the current queue
	Node<T> *tmpHead = m_head;
	m_head = copy.m_head;
	copy.m_head = tmpHead;

	Node<T> *tmpTail = m_tail;
	m_tail = copy.m_tail;
	copy.m_tail = tmpTail;

	int tmpSize = m_size;
	m_size = copy.m_size;
	copy.m_size = tmpSize;
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	(*this).clear();
}

template <class T>
void Queue<T>::clear()
{
	while (m_head)
	{
		(*this).popFront();
	}
}

template <class T>
void Queue<T>::pushBack(const T &data)
{
	Node<T> *insertNode = new Node<T>(data);
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
	m_size++;
}

template <class T>
const T &Queue<T>::front() const
{
	if (EMPTY_LIST)
	{
		throw EmptyQueue();
	}
	return m_head->m_data;
}

template <class T>
T &Queue<T>::front()
{
	if (EMPTY_LIST)
	{
		throw EmptyQueue();
	}

	return m_head->m_data;
}

template <class T>
void Queue<T>::popFront()
{
	if (EMPTY_LIST)
	{
		throw EmptyQueue();
	}
	else if (ONE_ELEMENT_LIST) // required?
	{
		Node<T> *toDelete = m_head;
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
		delete toDelete;
	}
	else
	{
		Node<T> *toDelete = m_head;
		m_head = m_head->m_next;
		m_size--;
		delete toDelete;
	}
}

template <class T>
int Queue<T>::size() const
{
	return m_size;
}

/**
 * Filter the queue members and return queue only wirh those who meet the condition.
 * @param origin - the queue that we want to filter.
 * @param c - the condition of the filter.
 */
template <class T, class Condition>
Queue<T> filter(const Queue<T> &origin, Condition c)
{
	Queue<T> filtered;
	for (typename Queue<T>::ConstIterator i = origin.begin(); i != origin.end(); ++i)
	{
		try
		{
			if (c(*i))
			{
				filtered.pushBack(*i);
			}
		}
		catch (const std::bad_alloc &e)
		{
			filtered.clear();
			throw e;
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
	for (typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i)

	{
		transformator(*i);
	}
}

template <class T>
class Queue<T>::Iterator
{
private:
	Node<T> *m_current;
	// todo it's shouldn't be const?
	Iterator(Node<T> *current);
	friend class Queue;

public:
	T &operator*() const;
	Iterator &operator++();
	Iterator operator++(int);
	bool operator!=(const Iterator &other);

	class InvalidOperation
	{
	};
};

template <class T>
Queue<T>::Iterator::Iterator(Node<T> *current) : m_current(current)
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
	if (END_LIST)
	{
		// todo should be clear here??
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
bool Queue<T>::Iterator::operator!=(const Iterator &other)
{
	// todo need to check == for nodes.
	return m_current != other.m_current;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
	return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
	return Iterator(nullptr);
}

template <class T>
class Queue<T>::ConstIterator
{
private:
	Node<T> *m_current;
	// todo it's shouldn't be const
	ConstIterator(Node<T> *current);
	friend class Queue;

public:
	const T &operator*() const;
	ConstIterator &operator++();
	ConstIterator operator++(int);
	bool operator!=(const ConstIterator &other);

	class InvalidOperation
	{
	};
};

template <class T>
Queue<T>::ConstIterator::ConstIterator(Node<T> *current) : m_current(current)
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
	if (END_LIST)
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
	ConstIterator result = *this;
	++*this;
	return result;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &other)
{
	// todo need to check == for nodes.
	return m_current != other.m_current;
}
// Return constIterator od Iterator?
template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
	return ConstIterator(m_head);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
	return ConstIterator(nullptr);
}

#endif // QUEUE_H
