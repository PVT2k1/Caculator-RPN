#include "RPN.h"

void solvePostfix(numStack* u_stack, char* expression)
{
	float number = 0;
	for (int i = 0; i < (int)strlen(expression); i++)
	{
		if (isdigit(expression[i]))//hàm có sẵn trong thư viện STL, kiểm tra có phải số không
		{
			if (isdigit(expression[i + 1]))	// trường hợp cho số có nhiều chữ số 
				number = number * 10 + (float)(expression[i] - '0');
			else
			{
				number = number * 10 + (float)(expression[i] - '0');
				push(u_stack, number);
				number = 0;
			}
		}
		if (isOperator(expression[i]))
		{
			float result = 0;
			float tmp1 = peek(u_stack);
			pop(u_stack);
			float tmp2 = peek(u_stack);
			pop(u_stack);
			switch (expression[i])
			{
			case '*':
			{
				result = tmp1 * tmp2;
				break;
			}
			case '/':
			{
				result = tmp2 / tmp1;
				break;
			}
			case '+':
			{
				result = tmp1 + tmp2;
				break;
			}
			case '-':
			{
				result = tmp2 - tmp1;
				break;
			}
			case '^':
			{
				result = (float)pow((double)tmp2, (double)tmp1);
				break;
			}
			default:
				break;
			}
			push(u_stack, result);
		}
	}
}

void TransfInfixToPostfix(charStack* u_stack, char* exp, char* result)
{
	for (int i = 0; i < strlen(exp); i++)
	{
		if (isdigit(exp[i]))
		{
			char buffer[2] = { '\0' };
			buffer[0] = exp[i];
			strcat(result, buffer);
		}

		if (isOperator(exp[i]))
		{
			strcat(result, " ");
			if (IsEmptyChar(u_stack))
				pushChar(u_stack, exp[i]);
			else
			{
				switch (exp[i])
				{
				case '*':
				case '/':
				{
					char buffer[2] = { '\0' };
					while (peekChar(u_stack) == '^' || peekChar(u_stack) == '*' || peekChar(u_stack) == '/')
					{
						buffer[0] = peekChar(u_stack);
						strcat(result, buffer);
						strcat(result, " ");
						popChar(u_stack);
					}
					pushChar(u_stack, exp[i]);
					break;

				}
				case '+':
				case '-':
				{
					char buffer[2] = { '\0' };
					while (peekChar(u_stack) == '^' || peekChar(u_stack) == '*' ||
						peekChar(u_stack) == '/' || peekChar(u_stack) == '+' || peekChar(u_stack) == '-')
					{
						buffer[0] = peekChar(u_stack);
						strcat(result, buffer);
						strcat(result, " ");
						popChar(u_stack);
					}
					pushChar(u_stack, exp[i]);
					break;
				}
				case '^':
				{
					pushChar(u_stack, exp[i]);
					break;
				}
				default:
					break;
				}
			}
		}

		if (exp[i] == '(')
			pushChar(u_stack, exp[i]);

		if (exp[i] == ')') //đưa ra toán tử cho đến khi đầu stack là (
		{
			while (peekChar(u_stack) != '(')
			{
				char buffer[2] = { '\0' };
				buffer[0] = peekChar(u_stack);
				strcat(result, " ");
				strcat(result, buffer);
				popChar(u_stack);
			}
			popChar(u_stack);	//bỏ đi dấu ( ở đầu stack
		}
	}

	while (IsEmptyChar(u_stack) == false)
	{
		char buffer[2] = { '\0' };
		buffer[0] = peekChar(u_stack);
		strcat(result, " ");
		strcat(result, buffer);
		popChar(u_stack);
	}
}

bool isOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
		return true;
	return false;
}