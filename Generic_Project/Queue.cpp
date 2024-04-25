#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{
    public:
        struct node<T> first;
        int iCnt;

        Queue();
        void Enqueue(T No);
}

template <class T>
Queue::Queue()
{
    first = NULL;
    iCnt = 0
}

template <class T>
void Enqueue(T No)
{
    
}
int main()
{
    Queue <int>iobj;

    iobj.Enqueue(51);
    iobj.Enqueue(21);
    iobj.Enqueue(51);

    return 0;
}