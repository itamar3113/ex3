template <typename T>
class Queue
{
private:
    Node<T> &head;
    Node<T> &tail;

public:
    Queue(T& data);
    ~Qeueu() = default;
    void add(T& data);
    void removeHead();
    void removeTail();
};