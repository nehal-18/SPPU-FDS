//============================================================================
// Name        : gsbcq.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 Pizza parlor accepting maximum M orders. Orders are served in first
come first served basis. Order once placed can not be cancelled. Write
C++ program to simulate the system using circular queue using array.
 */
#include <iostream>
#define MAX 5
using namespace std;

class cqueuepizza
{
	int q[MAX],rear,front;
public:
	cqueuepizza();
	void insert(int);
	int delete1();
	void display();
};

cqueuepizza :: cqueuepizza()
{
	front=rear=-1;
}
void cqueuepizza::insert (int value)
{
	if (((rear == MAX-1) && (front == -1))|| (rear -front)==-1)
		/*
		 * Reference : Fundamentals of Data Structures in C
		 * by Horowitz, Sahani, Freed. Page 116
		 * To distinguish queue full and queue empty ( as both have  FRONT = REAR),
		 * Queue full allows MAX - 1 elements , rather than MAX
		 */
		cout<<"\n Queue is Full";
	else
	{
		if (rear == MAX-1)	//creating circular link
			rear = -1;
		rear ++;
		q[rear] = value;
		cout<<"Order added at "<<rear<<endl;
	}
}

int cqueuepizza::delete1 ( )
{
	int value;
	if (rear == front)
	{
		cout<<endl<<"Queue is Empty";
			return -999;
	}
	else
	{
		if ((front == MAX-1) && rear < front)	//creating circular link
			front = -1;
		front ++;
		value = q[front];
		cout<<"Order removed from "<<front<<endl;
		return value;
	}
}

void cqueuepizza :: display()
{
	int i;

	cout<<endl;
	      if(front <= rear)
	      {
	    	  i = front+1;
	    	  while(i <= rear)
	    		  cout<<q[i++]<<"  ";
	      }
	      else
	      {
	    	  i = front+1;
	    	  while(i <= MAX - 1)
	    		  cout<<q[i++]<<"  ";
		 i = 0;
		 while(i <= rear)
			 cout<<q[i++]<<"  ";
	      }



}
int main()
{
	int choice,x,y;
	char ans;
	cqueuepizza q1;
	do
	{

		cout<<"\n*****MENU*****";
		cout<<"\n1. Place an order id ";
		cout<<"\n2. Remove an order id ";
		cout<<"\n3. Display the queue ";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1: cout<<"\n Enter the order id  :  ";
				cin>>y;
				q1.insert(y);
				q1.display();
				break;
		case 2:  x=q1.delete1();
				 if(x!=-999)
					 cout<<"\nThe removed order is: "<<x;
				 q1.display();
				 break;
		case 3:  q1.display();
				 break;
		default: cout<<"\nWrong choice!!";
				 break;
		}
		cout<<"\nDo you want to continue(y/n)??";
		cin>>ans;
	}while(ans=='y');

	return 0;

}

/*
 * *****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  10
Order added at 0

10
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  20
Order added at 1

10  20
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  30
Order added at 2

10  20  30
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  40
Order added at 3

10  20  30  40
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  50
Order added at 4

10  20  30  40  50
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  60

 Queue is Full
10  20  30  40  50
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 2
Order removed from 0

The removed order is: 10
20  30  40  50
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 2
Order removed from 1

The removed order is: 20
30  40  50
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  60
Order added at 0

30  40  50  60
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  70

 Queue is Full
30  40  50  60
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 2
Order removed from 2

The removed order is: 30
40  50  60
Do you want to continue(y/n)??y

*****MENU*****
1. Place an order id
2. Remove an order id
3. Display the queue
Enter your choice: 1

 Enter the order id  :  70
Order added at 1

40  50  60  70
Do you want to continue(y/n)??n
/*
 */
