
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void defining_priority();           //created a function to define the priority 
void pop_insertion_array();         // function - logic of push operator in array  and pop once $ is encountered 
void stack_logic(int,char);        // Function perform the main logic of push and pop until $ is encountered  
void menu();
char infix[MAX],a;
long int stack[MAX];
char postfix[MAX];
int top,previous;
int n,j,k,s,b;

int main()
{
	top =-1;
	j=0;
	system("clear");
	printf("Enter the Infix\n");
	gets(infix);
	n=strlen(infix);
	defining_priority();
	printf("Output is : %s \n",postfix);

}

void defining_priority()
{
	int i;
	char symbol;
	for (i = 0; i < n ; ++i)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case'+':
					k=1;
					stack_logic(k,symbol);
					break;
			case'-':
					k=1;
					stack_logic(k,symbol);
					break;
			case'*':
					k=2;
					stack_logic(k,symbol);
					break;
			case'/':
					k=2;
					stack_logic(k,symbol);
					break;
			case'^':
					k=3;
					stack_logic(k,symbol);
					break;
			case'$':
					pop_insertion_array();
					break;
			default  :
			{
				postfix[j]=symbol;
				j++  ;
			}
		}

	}
}

void stack_logic(int t,char a)
{

	if (top==-1)
	{
		top++;
		stack[top]=a;
		top++;
		stack[top]=t;
		previous=t;
	}
	else if(t<=previous)
	{
		while(t<=stack[top] && top>=-1)
		{
			top=top-1;
			postfix[j]=stack[top];
			j++;
			top=top-1;
		}
		top++;
		stack[top]=a;
		top++;
		stack[top]=t;
		previous=t;
	}
	else 
	{
		top++;
		stack[top]=a ;
		top++;
		stack[top]=t;
		previous=t;
	}


}

void pop_insertion_array()
{
	int i;
	top=top-1;
	for(i=top;i>=0;i=i-2)
	{
		postfix[j]=stack[i];
		j++;
	}

}



