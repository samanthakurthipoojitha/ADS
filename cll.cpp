//Circular Linked List
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class cll
{
  struct list
  {
    int data;
    struct list *next;
  }*head;
  public:
    typedef struct list node;
    cll();
    void create();
    void insert();
    void display();
    int deletepos();
    void insertatbeg();
    void insertatmid();
    void insertatend();
    void search();
};
cll::cll()
{
  head=NULL;
}
int main()
{
  int ch,k,c;
  cll obj;
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
void cll :: create()
{
   node *temp,*p;
   temp=new node;
   cout<<"Enter the element:";
   cin>>temp->data;
   if(head==NULL)
   {
     temp->next=temp;
     head=temp;
   }
   else
   {
     p=head;
     while(p->next!=head)
       p=p->next;
     p->next=temp;
     temp->next=head;
   }
}
void cll :: display()
{
   node *q;
   if(head==NULL)
     cout<<"List is empty";
   q=head;
   if(q==head)
     cout<<q->data<<"->";
   q=q->next;
   while(q!=head)
   {
     cout<<q->data<<"->";
     q=q->next;
   }
}
void cll :: search()
{
  int found=0,k;
  node *p;
  p=head;
  cout<<"Enter the element you want to find:";
  cin>>k;
  do
  {
    if(p->data==k)
    {
       found=1;
       cout<<"Element found";
    }
    p=p->next;
  }while((p!=head)&&(found==0));
  if(found==0)
  {
    cout<<"Element not found";
  }
}
void cll :: insert()
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
void cll :: insertatbeg()
{
  node *temp,*p;
  temp=new node;
  cout<<"Enter the inserted element:";
  cin>>temp->data;
  p=head;
  while(p->next!=head)  
    p=p->next;
  p->next=temp;
  temp->next=head;
  head=temp;
}
void cll :: insertatmid()
{
  node *temp,*p;
  int key,element;
  temp=new node;
  cout<<"Enter the element:";
  cin>>element;
  cout<<"Enter the key element:";
  cin>>key;
  p=head;
  do
  {
     if(p->data==key)
     {
       temp->next=p->next;
       temp->data=element;
       p->next=temp;
     }
     else
       p=p->next;
  }while(p!=head);
}
void cll :: insertatend()
{
    node *temp,*p;
   temp=new node;
   cout<<"Enter the element:";
   cin>>temp->data;
   if(head==NULL)
   {
     temp->next=temp;
     head=temp;
   }
   else
   {
     p=head;
     while(p->next!=head)
       p=p->next;
     p->next=temp;
     temp->next=head;
   }
}
int cll :: deletepos()
{
   node *p,*p1;
   int pos,i,k;
   cout<<"Enter the position for deletion:\n";
   cin>>pos;
   p=head;
   if(p->data==pos)
   {
      p1=p->next;
      if(p1==p)
      {
        p=NULL;
        head=p;
      }
      else 
      {
        while(p->next!=head)
          p=p->next;
        p->next=p1;
        head=p1;
      }
   }
   else
   {
     while(p->next!=head)
     {
        if((p->next)->data==pos)
        {
          p1=p->next;
          p->next=p1->next;
          p1->next=NULL;
          delete p1;
        }
        else
        {
          p=p->next;
        }
      }
     cout<<"\nList is empty";
   }
}
