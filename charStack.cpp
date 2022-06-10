#include "RPN.h"

void initializeChar(charStack** w_Stack)
{
	(*w_Stack) = new charStack;
	if (*w_Stack == nullptr)
	{
		cout << "allocate stack containing character failed\n";
		return;
	}
	(*w_Stack)->top = nullptr;
}

void deinitializeChar(charStack** w_Stack)
{
	if (*w_Stack != nullptr)
	{
		emptiedStackChar(*w_Stack);
		delete (*w_Stack);
		*w_Stack = nullptr;
	}
}

void emptiedStackChar(charStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (u_Stack->top != nullptr)
		{
			charNode* pNode = u_Stack->top;
			for (pNode; pNode != nullptr;)
			{
				u_Stack->top = u_Stack->top->pNext;
				delete pNode;
				pNode = u_Stack->top;
			}
		}
	}
}

bool IsEmptyChar(charStack* r_Stack)
{
	if (r_Stack != nullptr)
	{
		if (r_Stack->top == nullptr)
			return true;
		return false;
	}
}

void pushChar(charStack* u_Stack, char r_char)
{
	if (u_Stack != nullptr)
	{
		charNode* newNode = new charNode{ r_char, nullptr };
		if (IsEmptyChar(u_Stack))
		{
			u_Stack->top = newNode;
			return;
		}
		newNode->pNext = u_Stack->top;
		u_Stack->top = newNode;
	}
}

char peekChar(charStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (IsEmptyChar(u_Stack))
			return '\0';
		return (u_Stack->top->key);
	}
}

void popChar(charStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (IsEmptyChar(u_Stack))
			return;
		charNode* tmp = u_Stack->top;
		u_Stack->top = u_Stack->top->pNext;
		delete tmp;
	}
}