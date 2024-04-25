#include<iostream>
using namespace std;

template<class T>

struct node
{
    T data;
    struct node *next;
};

template<class T>
class Stack
{
    public:
        struct node<T> *First;
        int iCnt;

        Stack();
        void PUSH(T No);
        void Display();
        void POP();
        int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    First = NULL;
    iCnt = 0;
}

template<class T>
void Stack<T>::PUSH(T No)
{
    struct node<T> *newn = new struct node<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCnt++;
}

template<class T>
void Stack<T>::POP()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T> *Temp = First;
        First = First->next;
        delete Temp;
    }
    iCnt--;
}

template<class T>
void Stack<T>::Display()
{
    struct node<T> *Temp = First;
    cout<<"Containt of Stack List :\n";

    while(Temp != NULL)
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }
    cout<<"NULL \n";

}
template<class T>
int Stack<T>::CountNode()
{
    return iCnt;
}
int main()
{
    Stack <int>sobj;
    Stack <float>fobj;
    int iRet = 0;

    sobj.PUSH(51);
    sobj.PUSH(21);
    sobj.PUSH(11);
    sobj.Display();
    iRet = sobj.CountNode();
    cout<<"Stackt Member in :"<<iRet<<"\n\n";

    sobj.POP();
    sobj.Display();
    iRet = sobj.CountNode();
    cout<<"Stackt Member in :"<<iRet<<"\n\n";

    fobj.PUSH(51.000f);
    fobj.PUSH(21.000f);
    fobj.PUSH(51.000f);
    fobj.Display();
    iRet = fobj.CountNode();
    cout<<"Stackt Member in :"<<iRet<<"\n\n";

    return 0;
}