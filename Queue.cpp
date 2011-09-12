#include <iostream>
using namespace std;

class Queue
{

    public:
        Queue(int max);
        bool isEmpty();
        bool isFull();
        void enqueue(int item);
        int dequeue(int item);
        int queueCount();
        int queueFront();
        int queueRear();
};

struct queStruct
{
    int maxSize;
    int count;
    int front;
    int rear;
    int size;
};

/** Global var. **/
queStruct que;
int * a;

Queue::Queue( int max )
{
    a = new int[max+1];
    que.maxSize = max;
    que.front = 0;
    que.rear = 0;
}

bool Queue::isEmpty()
{
    return (que.size == 0);
}

bool Queue::isFull()
{
   // return ( ((que.rear+1)%que.maxSize) == que.front );
   return (que.rear+1 == que.front );
}

void Queue::enqueue(int itemIn)
{
    //if you hit the end of the array, move the front pointer up 1
    if( (que.rear+1 == que.maxSize) || (que.rear+1 == que.front))
    {
        if( que.front+1 == que.maxSize ) que.front = 0;
        else que.front++;
        
    }
    que.rear = (que.rear+1)%que.maxSize;
    a[que.rear] = itemIn;
    que.size++;
    //cout << que.front << " - " << que.rear << endl;
}

int Queue::dequeue(int itemOut)
{
    //cout << que.front << " - " << que.rear << endl;
    
    if( que.size != 0 )
    {
        que.front = (que.front+1)%que.maxSize;
        if( (que.front == que.rear) )
        {
            if( que.rear+1 == que.maxSize )
            {
                que.rear = 0;
            }
            else que.rear++;
        }

        itemOut = a[que.front];
        que.size--;
    }
    cout << "Error" << endl;
}

int Queue::queueCount()
{
    return que.size;
}

int Queue::queueFront()
{
    return que.front;
}

int Queue::queueRear()
{
    return que.rear;
}

int main(void)
{
    int item = 999;
    Queue q(5);
    q.enqueue(item);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.dequeue(item);
    q.dequeue(item);
    q.dequeue(item);
    q.dequeue(item);
    q.dequeue(item);
    q.dequeue(item);
    q.dequeue(item);
    cout << "size: " << q.queueCount() << endl;
    cout << "front: " << q.queueFront() << endl;
    cout << "rear: " << q.queueRear() << endl;
    cout << "isFull: " << q.isFull() << endl;
    cout << "isEmpty: " << q.isEmpty() << endl;
    cout << "item: " << item << endl;
}
