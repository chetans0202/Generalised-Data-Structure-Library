#include<iostream>
using namespace std;

template<class T>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

template<class T>
class  DoublyCircular
{
    public:
        struct node<T> *first;
        struct node<T> *last;
        int iCnt;

        DoublyCircular();
        void InsertFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No, int ipos);
        void DeleteAtPos(int ipos);
        void Display();
        int CountNode();
};

template<class T>
DoublyCircular<T>::DoublyCircular()
{
    first = NULL;
    last = NULL;
    iCnt = 0;
}
template<class T>
void DoublyCircular<T>::InsertFirst(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
        last->next = first;
        first->prev = last;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
        first->prev = last;
        last->next = first;
    }
    iCnt++;
}
template<class T>
void DoublyCircular<T>::InsertLast(T No)
{ 
    struct node<T> *newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
        last->next = first;
        first->prev = last;
    }
    iCnt++;
}

template<class T>
void DoublyCircular<T>::DeleteFirst()
{
    if((first == NULL) || (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        delete last;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCnt--;
}

template<class T>
void DoublyCircular<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        delete last;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    iCnt--;
}
template<class T>
void DoublyCircular<T>::Display()
{
    struct node<T> *Temp = first;
    struct node<T> *LTemp = last;
    cout<<"Node of Linked List :\n";
    cout<<"Address of last node <=>";
    do
    {
        cout<<"|"<<Temp->data<<"|<=>";
        Temp = Temp->next;
    }while(Temp != LTemp->next);
    cout<<"Address of First node \n\n";
}
template<class T>
int DoublyCircular<T>::CountNode()
{
    return iCnt;
}
template<class T>
void DoublyCircular<T>::InsertAtPos(T No, int ipos)
{
    if((ipos < 1) || (ipos > iCnt+1))
    {
        cout<<"Invalid Position..!\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(No);
    }
    else if(ipos == iCnt+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *Temp = first;
        struct node<T> *LTemp = last;
        struct node<T> *newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;
        int i = 0;

        for( i = 1; i< ipos-1; i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        Temp->prev = Temp;

        iCnt++;
    }
}
template<class T>
void DoublyCircular<T>::DeleteAtPos(int ipos)
{
      if((ipos < 1) || (ipos > iCnt))
    {
        cout<<"Invalid Position..!\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCnt)
    {
        DeleteLast();
    }
    else
    {
        int i = 0;
        struct node<T> *Temp = first;

        for(i = 1; i< ipos-1; i++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        Temp->next->prev = Temp;

        iCnt--;
    }
}
int main()
{
    int iRet = 0;
    DoublyCircular<int> iobj;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    iobj.InsertLast(101);
    iobj.InsertLast(121);
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    iobj.InsertAtPos(81,3);
    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    iobj.DeleteAtPos(3);

    iobj.Display();
    iRet = iobj.CountNode();
    cout<<"Node of Linked List :"<<iRet<<"\n\n";

    return 0;
}