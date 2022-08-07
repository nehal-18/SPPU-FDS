/*
 * Queues are frequently used in computer programming, and a typical
example is the creation of a job queue by an operating system. If the
operating system does not use priorities, then the jobs are processed in
the order they enter the system.
Write C++ program for simulating job queue.
Write functions to add job and delete job from queue
 */

#include <iostream>
using namespace std;
#define MAX 5

class jobqueue
{
		int a[MAX],front,rear;
public:
		jobqueue()
		{
			front=-1;
			rear=-1;
		}
		void addjob(int);
		int deletejob();
		int isfull();
		int isempty();
		void display();

};

void jobqueue::addjob(int x)
{
	if(isfull()==1)
		cout<<"\nThe queue is FULL. New jobs can't be added !!";
	else
	{
		rear++;
		a[rear]=x;
	}
}

int jobqueue::deletejob()
{
	int value;
	if(isempty()==0)
	{
		cout<<"\nThe queue is EMPTY. No jobs to delete !!";
		return -999;
	}
	else
	{
		front++;
		value=a[front];
		return value;
	}
}
int jobqueue::isfull()
{
	if(rear==MAX-1)
		return 1;
	else
		return 0;
}
int jobqueue::isempty()
{
	if(rear==front)
		return 0;
	else
		return 1;
}
void jobqueue::display()
{	int x=0;
	cout<<"\nThe queue is: ";
	cout<<" ->";
	for(x=front+1; x<=rear; x++)
	{
		cout<<" "<<a[x];
	}
}

int main()
{
	int choice,x,y;
	char ans;
	jobqueue q1;
	do
	{

		cout<<"\n*****MENU*****";
		cout<<"\nMENU DRIVE";
		cout<<"\n1. Add a job";
		cout<<"\n2. Delete a job";
		cout<<"\n3. Display the job queue";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1: cout<<"\n Enter the job :  ";
				cin>>y;
				q1.addjob(y);
				q1.display();
				break;
		case 2:  x=q1.deletejob();
				 if(x!=-999)
					 cout<<"\nThe deleted element is: "<<x;
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
