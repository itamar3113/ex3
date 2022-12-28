#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#define EMPTY_LIST m_size==0
#define ONE_ELEMENT_LIST m_head == m_tail
#define END_LIST !(m_current->m_next)


class Queue
{
private:

	struct Node
	{
		// todo encapsulation?
		double m_data;
		Node* m_next;
		Node(const double& data, Node* next = nullptr): m_data(data), m_next(next) {};
	};

	Node* m_head;
	Node* m_tail;
	int m_size;
	
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
	void pushBack(const double &data);

	/*
	 * Get the first element in the queue
	 * @return refrance for the first element
	 */
	//todo the test demand this to be const
	double& front() const;

	/*
	 * pop the first elemnt in the list
	 */
	void popFront();

	/*
	 * @return the size of the queue
	 */
	int size() const;

};


Queue::Queue() : m_head(nullptr),
					m_tail(nullptr),
					m_size(0)
{
}


Queue::Queue(const Queue &other) : m_head(nullptr),
										 m_tail(nullptr),
										 m_size(0)
{
	Node* tmp = other.m_head;
	while(tmp)
	{
		pushBack(tmp->m_data);
		tmp = tmp->m_next;
	}
}


Queue& Queue::operator=(const Queue& other)
{
	if(this == &other)
	{
		return *this;
	}
	
	Queue* copyQueue = new Queue();
	try
	{
		Node* tmp = other.m_head;
		while(tmp)
		{
			(*copyQueue).pushBack(tmp->m_data);
			tmp = tmp->m_next;
		}
	}
	catch (const std::bad_alloc& e)
	{
		(*copyQueue).clear();
		throw e;
	}
	(*this).clear();

	this->m_head = copyQueue->m_head;
	this->m_tail = copyQueue->m_tail;
	this->m_size = copyQueue->m_size;
	return *this;
}


Queue::~Queue()
{
	(*this).clear();
}


void Queue::clear()
{
	while(m_head)
	{
		(*this).popFront();
	}
}


void Queue::pushBack(const double &data)
{
	try
	{
		Node* insertNode = new Node(data);
		m_size++;
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
		(*this).clear();
		throw e;
	}
}


double& Queue::front() const
{
	if(EMPTY_LIST)
	{
		throw Queue::EmptyQueue();
	}
	return m_head->m_data;
}


void Queue::popFront()
{
	if(m_head != nullptr)
	{
		Node* deleteNode = m_head;
		m_head = m_head->m_next;
		m_size--;
		delete deleteNode;
	}
	else
	{
		std::cout << "elsepop";
		
		throw EmptyQueue();
	}
}


int Queue::size() const
{
	return m_size;
}


class Queue::Iterator
{
private:
	Node *m_current;
	//todo it's shouldn't be const?
	Iterator (Node *current);
	friend class Queue;

public:
	double &operator*() const;
	Iterator &operator++();
	Iterator operator++(int);
	bool operator!=(const Iterator &other);
	
	class InvalidOperation {};
};


Queue::Iterator::Iterator (Node *current) : m_current(current)
{
}


double &Queue::Iterator::operator*() const
{
	return m_current->m_data;
}


 Queue::Iterator &Queue::Iterator::operator++()
{
	if(END_LIST)
	{
		//todo should be clear here??
		throw InvalidOperation();
	}
	m_current = m_current->m_next;
	return *this;
}

// needed in linked list?

 Queue::Iterator Queue::Iterator::operator++(int signal)
{
	Iterator result = *this;
	++*this;
	return result;
}


bool Queue::Iterator::operator!=(const Iterator &other){
	//todo need to check == for nodes.
	return m_current != other.m_current;
}


 Queue::Iterator Queue::begin(){
	return Iterator(m_head);
}


 Queue::Iterator Queue::end(){
	return Iterator(nullptr);
}


class Queue::ConstIterator
{
private:
	Node *m_current;
	//todo it's shouldn't be const
	ConstIterator( Node *current);
	friend class Queue;

public:
	const double &operator*() const;
	ConstIterator &operator++();
	ConstIterator operator++(int);
	bool operator!=(const ConstIterator &other);
	
	class InvalidOperation {};
};


Queue::ConstIterator::ConstIterator( Node *current) : m_current(current)
{
}


const double &Queue::ConstIterator::operator*() const
{
	return m_current->m_data;
}


 Queue::ConstIterator &Queue::ConstIterator::operator++()
{
	if(END_LIST)
	{
		throw InvalidOperation();
	}
	m_current = m_current->m_next;
	return *this;
}

// needed in linked list?

 Queue::ConstIterator Queue::ConstIterator::operator++(int signal)
{
	ConstIterator result = *this;
	++*this;
	return result;
}


bool Queue::ConstIterator::operator!=(const ConstIterator &other){
	//todo need to check == for nodes.
	return m_current != other.m_current;
}
//Return constIterator od Iterator?

 Queue::ConstIterator Queue::begin() const{
	return ConstIterator(m_head);
}


 Queue::ConstIterator Queue::end() const{
	return ConstIterator(nullptr);
}


/**
 * Filter the queue members and return queue only wirh those who meet the condition.
 * @param origin - the queue that we want to filter.
 * @param c - the condition of the filter.
 */
template < class Condition>
Queue filter(const Queue &origin, Condition c)
{
	Queue filtered;
	for( Queue::ConstIterator i = origin.begin(); i != origin.end(); ++i)
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
template <class Transformator>
void transform(Queue &queue, Transformator transformator)
{
	for( Queue::Iterator i = queue.begin(); i != queue.end(); ++i)
	
	{
		transformator(*i);
	}
}


#endif // QUEUE_H
