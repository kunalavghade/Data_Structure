#include <cstring>

// char Stack
char stack[25];
int top = -1;

void push(char item)
{
	stack[++top] = item;
}

char pop()
{
	return stack[top--];
}

// int stack
int stack_int[25];
int top_int = -1;

void push_int(int item)
{
	stack_int[++top_int] = item;
}

int pop_int()
{
	return stack_int[top_int--];
}

//returns precedence of operators
int precedance(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 2;
			break;
		case '*':
		case '/':
			return 3;
			break;
		case '^':
			return 4;
			break;
		case '(':
		case ')':
		case '#':
			return 1;
			break;
	}
	return 1;
}

//check whether the symbol is operator?
int isOperator(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case ')':
		case '(':
		case '^':
			return 1;
			break;
		default:
			return 0;
	}
}

// coverts infix to postfix
void convert(char infix[], char postfix[])
{
	stack[++top]='#';
	int symbol,j=0;
	
	for(int i = 0; i <strlen(infix); i++)
	{
		symbol = infix[i];
		
		if(!isOperator(symbol))
		{
			postfix[j] = symbol;
			j++;
		}
		else
		{
			if(symbol == '(')
			{
				push(symbol);
			}
			else
			{
				if(symbol==')')
				{
					while(stack[top] !='(')
					{
						postfix[j++] = pop();
					}
					pop(); // pop out (
				}
				else
				{
					if(precedance(symbol)>precedance(stack[top]))
					{
						push(symbol);
					}
					else
					{
						while(precedance(symbol)<=precedance(stack[top]))
						{
							postfix[j++] = pop();
						}
					push(symbol);
					}
				}
			}
		}
	}	
	while(stack[top]!='#')
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
}

// evaluets postfix expression
int evaluate(char *postfix)
{
	char ch;
	int operand1,operand2,i=0;
	
	while((ch = postfix[i++]) != '\0')
	{
		if(!isOperator(ch))
		{
			push_int(ch-'0');
		}
		else
		{
			operand2 = pop_int();
			operand1 = pop_int();
			
			switch(ch)
			{
				case '+':
					push_int(operand1+operand2);
					break;
				case '-':
					push_int(operand1-operand2);
					break;
				case '*':
					push_int(operand1*operand2);
					break;
				case '/':
					push_int(operand1/operand2);
					break;
			}
		}
	}
	return stack_int[top_int];
} 











