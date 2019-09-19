#include<iostream>
#include<stdlib.h>
#define MAX 5
int queue_arr[MAX];
int rear=-1;
int front=-1;
using namespace std;
class queue_using_array
{
public:
void insert();
void del();
void display();
};
int main()
{
 queue_using_array obj;
 int choice;
 while(1)
 {
  cout<<"\n1.insert\n\t2.delete\n\t3.display\n\t4.quit\n";
  cout<<"Enter your choice:";
  cin>>choice;
  switch(choice)
  {
    case 1:obj.insert();
           break;
    case 2:obj.del();
           break;
    case 3:obj.display();
           break;
    case 4:exit(1);
    default:cout<<"Wrong choice \n";
   }
  }
}
void queue_using_array::insert()
{
  int added_item;
  if(rear==MAX-1)
  cout<<"Queue overflow \n";
  else
  {
    if(front==-1)
    front=0;
    cout<<"Input the element for adding in queue:";
    cin>>added_item;
    rear=rear+1;
    queue_arr[rear]=added_item;
  }
}
void queue_using_array::display()
{
  int i;
  if(front==-1)
  cout<<"Queue is empty \n";
  else
  {
     cout<<"Queue is :\n";
     for(i=front;i<=rear;i++)
     cout<<queue_arr[i]<<"\n";
  }
}
void queue_using_array::del()
{
   if(front==-1)
    {
      cout<<"Queue underflow\n";
      return;
    }
     else
      {
       cout<<"Element deleted from queue is :\n"<<queue_arr[front];
       front=front+1;
      }
}
  
