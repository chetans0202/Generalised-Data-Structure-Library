#include<iostream>
using namespace std;

template<class T>

struct node
{
    int data;
    struct node *next;

};

template<class T>
class SinglyCL
{
    public:
        struct node<T> *First;
        struct node<T> *Last;
        int iCount;

        SinglyCL();
        void InserFirst(T No);
        void InsertLast(T No);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T No, int ipos);
        void DeleteAtPos(int ipos);
        void Display();
        T Count();
   
};

    template<class T>
    SinglyCL<T>::SinglyCL()
    {
        First = NULL;
        Last = NULL;
        iCount = 0;
    }

    template<class T>
    void SinglyCL<T>::InserFirst(T No)
    {
        struct node<T> *newn =  new struct node<T>;
        newn->data = No; 
        newn->next = NULL;

        if((First == NULL) && (Last == NULL))
        {
            First = newn;
            Last = newn;
            Last->next = First;
        }
        else
        {   
            newn->next = First;
            First = newn;
            Last->next = First;
        }
         iCount++;
    }

    template<class T>
    void SinglyCL<T>::InsertLast(T No)
    {
        struct node<T> *newn = new struct node<T>;
        newn->data = No;
        newn->next = NULL;

        if((First == NULL) || (Last == NULL))
        {
            First = newn;
            Last = newn;
            Last->next = First;
        }
        else
        {
            Last->next = newn;
            Last = newn;
            Last->next = First;
        }
        iCount++;
    }

    template<class T>
    void SinglyCL<T>::DeleteFirst()
    {
        if((First == NULL) && (Last == NULL))
        {
           return;
        }
        else if(First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            First = First->next;
            delete Last->next;
            Last->next = First;
        }
        iCount--;
    }

    template<class T>
    void SinglyCL<T>::DeleteLast()
    {
        struct node<T> *Temp = First;

        if((First == NULL) && (Last == NULL))
        {
            return;
        }
        else if(First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            while(Temp->next != Last)
            {
                Temp = Temp->next;
            }
            delete[]Temp->next;
            Last = Temp;
            Last->next = First;
        }
        iCount--;
    }

    template<class T>
     void SinglyCL<T>::Display()
    {
        struct node<T> *Temp = First;
        struct node<T> *Ltemp = Last;

        cout<<"Elements of LinkList : \n";
        cout<<"Address of Last Node ->";
        do
        {
            cout<<"| "<<Temp->data<<"|->";
            Temp = Temp->next; 
        }while(Temp != Ltemp->next);
        cout<<"Elements of Last Node\n";
    }

    template<class T>
    T SinglyCL<T>::Count()
    {
        return iCount;
    }

    template<class T>
    void SinglyCL<T>::InsertAtPos(T No, int ipos)
    {
        if((ipos < 1) || (ipos > iCount+1))
        {
            cout<<"Invalid Position..! \n";
            return;
        }

        if(ipos == 1)
        {
            InserFirst(No);
        }
        else if(ipos == iCount+1)
        {
            InsertLast(No);
        }
        else
        {
            int i = 0;
            struct node<T> *Temp = First;
            struct node<T> *newn = new struct node<T>;
            newn->data = No;
            newn->next = NULL;

            for(i = 1; i < ipos-1; i++)
            {
                Temp = Temp->next;
            }
            newn->next = Temp->next;
            Temp->next = newn;

            iCount++;
        }
    }

    template<class T>
    void SinglyCL<T>::DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > iCount))
        {
            cout<<"Invalid Position..!\n";
        }

        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iCount)
        {
            DeleteLast();
        }
        else
        {
            struct node<T> *Temp = First;

            int  i = 0;

            for(i = 1; i < ipos-1; i++)
            {
                Temp = Temp->next;
            }
            struct node<T> *targat(Temp->next);
            Temp->next = Temp->next->next;
            delete targat;

            iCount--;
        }
    }
   

int main()
{
    int iRet = 0;

   SinglyCL<int> iobj;
   SinglyCL<float> fobj;
   SinglyCL<double> dobj;
   SinglyCL<char> cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);

    cout<<"LinkList of Integers :"<<"\n";
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Count of node is :"<<iRet<<"\n\n";

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"LinkList of Float :"<<"\n";
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Count of node is :"<<iRet<<"\n\n";

    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    cout<<"LinkList of Double :"<<"\n";
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Count of node is :"<<iRet<<"\n\n";

    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"LinkedList of Characters : "<<"\n";
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Count of node is :"<<iRet<<"\n\n";


    return 0;
}