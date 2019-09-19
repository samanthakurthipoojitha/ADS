#include<iostream>
#define MAX 5
int top=-1;
int a[10];
using namespace std;
class SUA
{
  public:
         void push();
		 void pop();
		 void display();
};
int main()
{
  SUA obj;
  int choice;
  while(1)
  {
   cout<<"!.push\t\t2.pop\t\t3.display\t\t4.exit\n";
   cout<<"Enter choice :\n";
   cin>>choice;
   switch(choice)
   {
    case 1:obj.push();
	       break;
    case 2:obj.pop();
	       break;
    case 3:obj.display();
	       break;
    case 4:exit(0);
	default:cout<<"Invalid choice \n";
	        break;
   }
  }
}
void SUA::push()
{
  int pushed_item;
  if(top==(MAX-1))
    cout<<"Stack overflow \n";
	else
	{
	  cout<<"Enter the elements to be pushed into the stack :\n";
	  cin>>pushed_item;
	  top=top+1;
	  a[top]=pushed_item;
     }
}
void SUA::display()
{
  int i;
  if(top==-1)
    cout<<"Stack is empty";
	else
	{
	cout<<"Stack elements :\n";
	for(i=top;i>=0;i--)
	cout<<a[i]<<"\n";
	}
}
void SUA::pop()
{
  if(top==-1)
   cout<<"Stack underflow \n";
   else
   {
     cout<<"Enter the element to be popped out of a Stack :\n"<<a[top];
	 top=top-1;
   }
}
	 
	
	
	 
 

