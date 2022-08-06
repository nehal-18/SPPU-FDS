/*
Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of Second, third and final year of department can be granted
membership on request. Similarly one may cancel the membership of club.
First node is reserved for president of club and last node is reserved
for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name.
Write functions to,
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club.
c) Display members.
d) Display list in reverse order using recursion.
e) Two linked lists exists for two divisions. Concatenate two lists.
*/
#include<iostream.h>
class pinnacle
{
	struct node
	{
		int prn;
		char name[50];
		struct node *next;
	}*start1, *temp1, *temp2,*node1, *start2, *node2;
	public:
	pinnacle();
	void display();
	void addmember();
	void createmembers();
	void addpresident();
	void addsecretary();
	void deletemember();
	void deletepresident();
	void deletesecretary();
	void total();
	void reverse();
	void concatenate();
};

void pinnacle :: pinnacle()
{
	start1=start2=NULL;
}
void pinnacle :: display()
{
	temp1=start1;
	// Traverse from 1 to last node, displaying the list
	while(temp1!=NULL)
	{
		cout<<temp1->prn<<"  "<<temp1->name<<"  ";
		temp1=temp1->next;
	}
}

void pinnacle :: total()
{
	temp1=start1;
	int n=0;
		// Traverse from 1 to last node, counting in n
	while(temp1!=NULL)
	{
		n++;
		temp1=temp1->next;
	}
	cout<<endl<<"The total number of members are : "<<n;
}

void pinnacle :: createmembers()
{
	int n,i;
	cout<<"How many members do you want to create?";
	cin>>n;

	// Create list of n members
	for(i=1;i<=n;i++)
	{
	// If list not yet created, create it
	if(start1==NULL)
	{
		start1 = new node;
		cout<<endl<<"Enter PRN and name of a student : ";
		cin>>start1->prn>>start1->name;
		start1->next=NULL;
	}
	// list already created so insert at end
	else
	{
		temp1=start1;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		node1 = new node;
		cout<<endl<<"Enter PRN and name of a student : ";
		cin>>node1->prn>>node1->name;
		temp1->next=node1;
		node1->next = NULL;
	}
	}
	display();
}

void pinnacle :: addpresident()
{
	// Insert at beginning. As president is 1st node
	if(start1==NULL)
	{
		cout<<"\n\n\tThe list is not created";
		return;
	}

	node1= new node;
	cout<<endl<<"Enter PRN and name of a president: ";
	cin>>node1->prn>>node1->name;

	// Pointer manipulations
	node1->next=start1;
	start1=node1;
	display();

}
void pinnacle :: addsecretary()
{
	// Insert at end. As secretary is last node
	if(start1==NULL)
	{
		cout<<"\n\nt\tList is not created";
		return;
	}

	node1= new node;
	temp1=start1;

	while(temp1->next!=NULL)
		temp1=temp1->next;

	cout<<endl<<"Enter PRN and name of a secretary: ";
	cin>>node1->prn>>node1->name;

	// Pointer manipulations
	temp1->next=node1;
	node1->next=NULL;
	display();
	return;
}
void pinnacle :: addmember()
{
	temp1=start1;
	// List already created. Insert new element at 2nd last position
	// Go to second last node
	while(temp1->next->next!=NULL)
		temp1=temp1->next;
	node1 = new node;
	cout<<endl<<"Enter PRN and name of new member: ";
	cin>>node1->prn>>node1->name;
	node1->next=temp1->next;
	temp1->next=node1;
	display();
}

void pinnacle::deletemember()
{
	int key;
	cout<<endl<<"Enter membre PRN to be deleted";
	cin>>key;
	temp1=temp2=start1;

	// Search the node to be deleted
	while(temp1->prn !=key && temp1->next->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}

	// Not found
	if(temp1->prn!=key)
	{
		cout<<"PRN not found. Delete fail";
		return;
	}

	// First node cant be deleted from this function / option
	if(temp1==start1)
	{
		cout<<"This is the President. Delete fail. Cant delete from this option";
		return;
	}
	// Delete in between
	// PRN found
	temp2->next=temp1->next;
	delete temp1;
	display();
}
void pinnacle::deletepresident()
{
	if(start1==NULL)
	{
		cout<<"\n\n\tEmpty list. Nothing to delete.";
		return;
	}
	// Delete in beginning
	temp1=start1;
	start1=start1->next;
	delete temp1;
	display();

}

void pinnacle::deletesecretary()
{
	if(start1==NULL)
	{
		cout<<"\n\n\tEmpty list. Nothing to delete";
		return;
	}

	// Go to the end of the list
	temp2=temp1=start1;
	while(temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	// Delete at the end
	temp2->next=NULL;
	delete temp1;
	display();
}
void pinnacle::reverse()
{
	// Reverse the list
	struct node *p,*q,*r;
	p=NULL;
	q=start1;
	r=q->next;
	while(q!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL)
			r=r->next;
	}
	start1=p;
	display();
}

void pinnacle::concatenate()
{

	int n,i;

	// Create list 2
	cout<<"How many members do you want to create in 2nd shift list?";
	cin>>n;
	for(i=1;i<=n;i++)
	{
	if(start2==NULL)
	{
		start2 = new node;
		cout<<endl<<"Enter PRN and name of a student : ";
		cin>>start2->prn>>start2->name;
		start2->next=NULL;
	}
	else
	{
		temp2=start2;
		while(temp2->next!=NULL)
			temp2=temp2->next;
		node2 = new node;
		cout<<endl<<"Enter PRN and name of a student : ";
		cin>>node2->prn>>node2->name;
		temp2->next=node2;
		node2->next = NULL;
	}
	}
	// Concatenate list 1 and 2
	// Got to last node of list 1 and connect it to start
	temp1=start1;
	while(temp1->next!=NULL)
		temp1=temp1->next;
	temp1->next = start2;
	display();
}


int main()
{
	int ch;
	char ch1;
	pinnacle p;
	do
	{
	cout<<endl<<"1. Create list with members"<<endl<<"2. Add President";
	cout<<endl<<"3. Add Secretary"<<endl<<"4. Add new member";
	cout<<endl<<"5. Display"<<endl<<"6. Delete member";
	cout<<endl<<"7. Delete President"<<endl<<"8. Delete Secretary";
	cout<<endl<<"9. Total count"<<endl<<"10. Reverse";
	cout<<endl<<"11. Concatenate";
	cout<<endl<<"Enter choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: p.createmembers();
			break;
		case 2: p.addpresident();
			break;
		case 3: p.addsecretary();
			break;
		case 4: p.addmember();
			break;
		case 5: p.display();
			break;
		case 6: p.deletemember();
			break;
		case 7:p.deletepresident();
			break;
		case 8:p.deletesecretary();
			break;
		case 9:p.total();
			break;
		case 10:p.reverse();
			break;
		case 11: p.concatenate();
			break;
	}
	cout<<endl<<"Do you want to continue?";
	cin>>ch1;
	}while(ch1=='Y' || ch1=='y');

	return 0;
}

