/*In any language program mostly syntax error occurs due to unbalancing
delimiter such as (),{},[]. Write C++ program using stack to check
whether given expression is well parenthesized or not.*/

#include<iostream.h>
#define MAX 10
class stack
{

	int top;
	char stck [MAX], expr[MAX];
	public:
	stack();
	void push(char);
	void read();
	void check_parenthesis ();
	int IsEmpty ();
	char pop();
};

stack :: stack ()
{
	top=-1;
}

int stack :: IsEmpty ()
{
	 //top is always at last added element
	if (top == -1) 		//check if elements were added
		return (-1);
	else
		return (1);
}

void stack :: push(char temp)
{
	 //top is always at last added element (earlier element).
	top ++;	 		//take it to empty position
	if (top == MAX)		//check if there is any space
		cout<<"Stack is Full";
	else
	{
		stck [top] = temp;	//add ‘value’ at topth position
	       //	cout<<"New element pushed on the stack";
	}

}

char stack :: pop()
{
	int status;
	char temp;
	status = IsEmpty ();
	if (status == -1) {
		cout<<"Stack is Empty";
		return ('@');
	}
	else	{
		temp = stck [top--];	//fetch topth position in temp
		return (temp);
	}

}
void stack :: read()
{
	cout<<"Enter expression ";
	cin>>expr;
}
void stack :: check_parenthesis()

{
	int val;
	char temp;
	for (int i=0; expr [i]!= '\0'; i++)	//read the expression character by char
	{
		if (expr [i] == '(' || expr[i]=='{' || expr[i] == '[')	//opening parenthesis, push
			push (expr [i]);
		else if (expr [i] == ')'|| expr[i]=='}' || expr[i] == ']')	//closing parenthesis, pop
		{
			val = IsEmpty ();
			if (val == -1)		//stack is empty
			{
				cout<<"ERROR: More closing parethesis";
				return;
			}

			else
			{
				temp=pop ();	   // (/{/[ parenthesis will be popped
				if(expr[i]==')' && temp!='(')
				{
					cout<<"ERROR : Not matching ()";
					return;
				}
				if(expr[i]=='}' && temp!='{')
				{
					cout<<"ERROR : Not matching ()";
					return;
				}
				if(expr[i]==']' && temp!='[')
				{
					cout<<"ERROR : Not matching []";
					return;
				}
			} // End of else
		} // End of pop else
		//else, do nothing. Move ahead on the expression
	}// End of for loop
	val=IsEmpty();
	if(val == -1)
		cout<<"Paranthesis match";
	else
		cout<<"ERROR : More opening parenthesis";
}

int main()
{
	stack s;
	s.read();
	s.check_parenthesis();
	return 0;
}


