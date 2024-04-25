#include<iostream>
using namespace std;

template<class T>

struct node
{
    int data;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>
class DoublyLL
{
    public:
        struct node<T> *First;
        int iCnt;

        DoublyLL();
        void InsertFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No, int ipos);
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
        
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCnt = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        First->next = NULL;
        First->prev = NULL;
    }
    else
    { 
        First->prev = newn;
        newn->next = First;
        First = newn;
        First->prev = NULL;
    }
    iCnt++;
} 
template<class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        First->next = NULL;
        First->prev = NULL;
    }
    else
    {
        struct node<T> *Temp = First;

        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
        newn->next = NULL;
    }
    iCnt++;
}
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First->prev = NULL;
        First->next = NULL;
    }
    else
    {
        struct node<T> *Temp = First;
        First = First->next;
        delete Temp;
        First->prev = NULL;

    }
    iCnt--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First->next = NULL;
        First->prev = NULL;
    }
    else
    {
        struct node<T> *Temp = First;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete Temp->next;
        Temp->next = NULL;
    }
    iCnt--;
}
template<class T>
void DoublyLL<T>::Display()
{
    struct node<T> *Temp = First;
    cout<<"Node of Linked List \n";
    cout<<"NULL <=>";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|<=>";
        Temp = Temp->next;
    }
    cout<<"NULL \n";

}

template<class T>
int DoublyLL<T>::Count()
{
    return iCnt;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T No, int ipos)
{
    if((ipos < 1) || (ipos > iCnt+1))
    {
        cout<<"Invalide Position..! \n";
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
        struct node<T> *newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;
        int i = 0;
        struct node<T> *Temp = First;

        for(i = 1; i < ipos-1; i++)
        {
            Temp = Temp->next;
        }
        Temp->next->prev = newn;
        newn->next = Temp->next;
        Temp->next = newn;
        Temp->next->prev = Temp;

        iCnt++;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) && (ipos > iCnt))
    {
        cout<<"Invalid Position :\n";
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
        struct node<T> *Temp = First;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
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

    DoublyLL<int> iobj;
    DoublyLL<float> fobj;
    // DoublyLL<double> dobj;
    int iRet = 0;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.InsertLast(101);
    iobj.InsertLast(121);
    iobj.DeleteFirst();
    iobj.DeleteLast();
    iobj.InsertAtPos(81,3);
    iobj.DeleteAtPos(2);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Node of Count :"<<iRet<<"\n\n";

    

    fobj.InsertFirst(51.00);
    fobj.InsertFirst(21.00);
    fobj.InsertFirst(11.00);
    fobj.InsertLast(101.00);
    fobj.InsertLast(121.00);
    fobj.InsertLast(151.00);    
    fobj.DeleteFirst();
    fobj.DeleteLast();
    fobj.InsertAtPos(81.00);
    fobj.InsertAtPos(91.00);
    fobj.DeleteAtPos(2);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Node of Count :"<<iRet<<"\n\n";
    return 0;
}