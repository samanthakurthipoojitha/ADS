#include<iostream>
#include<stdlib.h>
using namespace std;
class sll
{

    struct list
    {
     int data;
     struct data *next;
    }*head;
public:
    typedef struct list node;
    sll();
    void create();
    void insert();
    void display();
    int count();
    int deletepos();
    void insertatbeg();
    void insertatmid();
    void insertatend();
    void search();

};
sll::sll()
{

    head=NULL;

}
int main()
{

    int ch,k,c;
    sll obj;
    do
    {

        cout<<"\n\tMAIN MENU";
        cout<<"\t\t1.create\t\t2.display\t\t3.insert\t\t4.deletepos\t\t5.count\t\t6.search\n\n7.exit\n";
        cout<<"Enter your choice";
        cin>>ch;
        switch(ch)
        {

            case 1:obj.create();
                  break;
            case 2:obj.display();
                  break;
            case 3:obj.insert();
                  break;
            case 4:k=obj.deletepos();
                  break;
            case 5:c=obj.count();
                   break;
            case 6:obj.search();
                   break;
            case 7:exit(0);
            }

    }while(ch>0&&ch<8);

}
void sll::create()
{

    node *temp,*p;
    temp=new node;
    cout<<"Enter the element :";
    cin>>temp->data;
    if(head=NULL)
    {

        temp->next=head;
        head=temp;

    }
    else{
        p=head;
        while(p->next!=NULL)
        p=p->next;
        temp->next=NULL;
        p->next=temp;

    }
}
void sll::display()
{

    node *q;
    q=head;
    cout<<"elements in the list are\n";
    while(q!=NULL)
    {

        cout<<"->"<<q->data;
        q=q->next;

    }
}
int sll::count()
{

    node *p;
    int c=0;
    p=head;
    while(p!=NULL)
    {

        p=p->next;
        c++;

    }
    return(c);
}
void sll::search()
{

    int f=0,k,v;
    node *p;
    p=head;
    cout<<"Enter the element you want to found \n";
    cin>>k;
    while(p!=NULL)
    {

        if(p->data==k)
        {

            f=1;
            cout<<"Element found";

        }
        p=p->next;

    }
    if(f==0)
    {

        cout<<"Element not found ";

    }
}
void sll::insert()
{

    int ch;
    do
    {

        cout<<"\n\t\t1.insertatbeg\n\t\t2.insertatmid\n\t\t3.insertatend\n\t\t4.display\n\t\t5.exit";
        cout<<"Enter your choice";
        cin>>ch;
        switch(ch)
        {

            case 1:insertatbeg();
                   break;
            case 2:insertatmid();
                   break;
            case 3:insertatend();
                   break;
            case 4:display();
                   break;
            default:
                break;

        }
    }while(ch>0&&ch<5);

}
void sll::insertatbeg()
{

    node *temp;
    temp=new node;
    cout<<"Enter the inserted element";
    cin>>temp->data;
    temp->next=head;
    head=temp;

}
void sll::insertatmid()
{

    node *temp,*p;
    int key;
    temp=new node;
    cout<<"enter the element";
    cin>>temp->data;
    cout<<"Enter the key element";
    cin>>key;
    p=head;
    while(p!=NULL)
    {

        if(p->data==key)
        {

            temp->next=p->next;
            p->next=temp;

        }
        p=p->data;
    }
}
void sll::insertatend()
{

    node *temp,*p;
    temp=new node;
    cout<<"\nEnter element";
    cin>>temp->data;
    if(head==NULL)
    {

        temp->next=head;
        head=temp;

    }
    else
    {

        p=head;
        while(p->next!=NULL)
        p=p->next;
        temp->next=NULL;
        p->next=temp;


    }
}
int sll::deletepos()
{

    node *p;
    int pos,i,k;
    cout<<"\nEnter the podsition for deletion";
    cin>>pos;
    if(head!=NULL)
    {

        if(pos==1)
        {

            k=head->data;
            head=head->next;
            return(k);

        }
        else
        {

        i=2;
        p=head;
        while((p!=NULL)&&(i<pos))
        {

          p=p->next;
          i++;

        }
        if(p!=NULL)
        k=p->next->data;
        p->next=p->next->next;
        return(k);

    }
    }
else
    cout<<"\n\tLIST IS EMPTY";

}
