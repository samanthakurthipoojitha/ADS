//Double Linked List
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class dll
{
  struct list
  {
    int data;
    struct list *prev,*next;
  }*head;
  public:
    typedef struct list node;
    dll();
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
dll::dll()
{
  head=NULL;
}
int main()
{
  int ch,k;
  dll obj;
  do
  {
    cout<<"\n\tMAIN MENU\n";
    cout<<"\t\t1.Create\n\t\t2.Display\n\t\t3.Insert\n\t\t4.Deletepos\n\t\t5.Search\n\t\t6.Exit\n";
    cout<<"\n\tEnter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:obj.create();
             break;
      case 2:obj.display();
             break;
      case 3:obj.insert();
             break;
      case 4:obj.deletepos();
             break;
      case 5:obj.search();
             break;
      case 6:exit(0);
    }
  }while(ch>0&&ch<7);
}
void dll :: create()
{
   node *temp,*p;
   temp=new node;
   cout<<"Enter the element:";
   cin>>temp->data;
   if(head==NULL)
   {
     temp->next=head;
     temp->prev=head;
     head=temp;
   }
   else
   {
     p=head;
     while(p->next!=NULL)
       p=p->next;
     temp->next=NULL;
     temp->prev=p;
     p->next=temp;
   }
}
void dll :: display()
{
   int d;
   node *q;
   q=head;
   cout<<"Elements in the list are:\n";
   while(q!=NULL)
   {
     cout<<"->"<<q->data;
     q=q->next;
   }
}
void dll :: search()
{
  int f=0,k,c;
  node *p;
  p=head;
  c=0;
  cout<<"Enter the element you want to find:";
  cin>>k;
  while(p!=NULL)
  {
    c++;
    if(p->data==k)
    {
       f=1;
       cout<<"Element found";
    }
    p=p->next;
  }
  if(f==0)
  {
    cout<<"Element not found";
  }
}
void dll :: insert()
{
  int ch;
  do
  {
    cout<<"\n\t\t1.Insertatbeg\n\t\t\t2.Insertatmid\n\t\t\t3.Insertatend\n\t\t\t4.Display\n\t\t\t5.Exit";
    cout<<"Enter your choice:\n";
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
void dll :: insertatbeg()
{
  node *temp;
  temp=new node;
  cout<<"Enter the inserted element:";
  cin>>temp->data;
  temp->next=head;
  temp->prev=NULL;
  head->prev=temp;
  head=temp;
}
void dll :: insertatmid()
{
  node *temp,*p;
  int key;
  temp=new node;
  cout<<"Enter the element:";
  cin>>temp->data;
  cout<<"Enter the key element:";
  cin>>key;
  p=head;
  while(p!=NULL)
  {
     if(p->data==key)
     {
       p->next->prev=temp;
       temp->next=p->next;
       p->next=temp;
       temp->prev=p;
     }
     p=p->next;
  }
}
void dll :: insertatend()
{
   node *temp,*p;
   temp=new node;
   cout<<"Enter element:\n";
   cin>>temp->data;
   if(head==NULL)
   {
     temp->next=head;
     temp->prev=head;
     head=temp;
   }
   else 
   {
     p=head;
     while(p->next!=NULL)
       p=p->next;
     temp->next=NULL;
     temp->prev=p;
     p->next=temp;
   }
}
int dll :: deletepos()
{
   node *p,*t,*q;
   int pos,i,k;
   cout<<"Enter the position for deletion:\n";
   cin>>pos;
   if(head!=NULL)
   {
      if(pos==1)
      {
        t=head;
        head=head->next;
        head->prev=NULL;
        cout<<t->data<<" is deleted\n";
        delete(t);
      }
      else 
      {
        i=1;
        p=head;
        q=head;
        while(i<pos)
        {
          q=p;
          p=p->next;
          i++;
        }
        t=p;
        q->next=p->next;
        p->next->prev=q;
        cout<<t->data<<" is deleted\n";
        free(t);
      }
   }
   else
     cout<<"\nList is empty";
}
