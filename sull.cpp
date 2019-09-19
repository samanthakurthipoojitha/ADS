//Stack using Linked List
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class SULL
{
  struct stack
  {
    int data;
    struct stack *next;
  }*top;
  public:typedef struct stack node;
         void push();
         int pop();
         void display();
         SULL();
};
SULL :: SULL()
{
  top=NULL;
}
int main()
{
  SULL obj;
  int ch,k;
  while(1)
  {
    cout<<"\n\tMAIN MENU\n";
    cout<<"\n\t\t1.Push\n\t\t2.Pop\n\t\t3.Display\n\t\t4.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>ch;
    switch(ch)
    {
      case 1:obj.push();
             break;
      case 2:k=obj.pop();
             cout<<"Popped element is: "<<k;
             break;
      case 3:obj.display();
             break;
      case 4:exit(0);
    }
  }
}
void SULL :: push()
{
  node *temp;
  int element;
  temp=new node;
  cout<<"Enter the element:";
  cin>>element;
  temp->data=element;
  temp->next=top;
  top=temp;
}
int SULL :: pop()
{
  int k;
  node *p,*q;
  p=top;
  k=top->data;
  q=top;
  top=p->next;
  free(q);
  return k;
}
void SULL :: display()
{
  node *p;
  p=top;
  cout<<"Elements in the stack are: \n";
  if(top!=NULL)
  {
    while(p!=NULL)
    {
      cout<<"->"<<p->data;
      p=p->next;
    }
  }
  else
    cout<<"Stack is empty";
}
