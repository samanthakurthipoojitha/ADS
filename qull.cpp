//Queue using linked list
#include<stdlib.h>
#include<iostream>
using namespace std;
class QULL
{
  struct queue
  {
    int data;
    struct queue *next;
  }*front,*rear;
  public:typedef struct queue node;
         void insert();
         int del();
         void display();
         QULL();
};
QULL :: QULL()
{
  front = NULL;
  rear = NULL;
}
int main()
{
  QULL obj;
  int ch,k;
  while(1)
  {
    cout<<"\n\tMAIN MENU\n";
    cout<<"\n\t\t1.Insert\n\t\t2.Delete\n\t\t3.Display\n\t\t4.Exit\n";
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:obj.insert();
             break;
      case 2:k=obj.del();
             cout<<"Deleted element from the queue is:"<<k;
             break;
      case 3:obj.display();
             break;
      case 4:exit(0);
      default:cout<<"Invalid choice";
              break;
    }
  }
}
void QULL :: insert()
{
  node *temp;
  temp=new node;
  cout<<"Enter the  element:";
  cin>>temp->data;
  if(front == NULL)
  {
    temp->next=front;
    front=rear=temp;
  }
  else
  {
    temp->next=rear->next;
    rear->next=temp;
    rear=temp;
  }
}
void QULL :: display()
{
  node *p;
  p=front;
  if(front!=NULL)
  {
    cout<<"Elements in the queue are:\n";
    while(p!=NULL)
    {
      cout<<"->"<<p->data;
      p=p->next;
    }
  }  
  else
    cout<<"Queue is empty";
}
int QULL :: del()
{
   int k;
   node *p;
   if(front!=NULL)
   {
     k=front->data;
     p=front;
     front=front->next;
     free(p);
     return k;
   }
}
