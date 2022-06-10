#include "RPN.h"

//khởi tạo và hủy stack với Node là số nguyên, cùng các hàm xử lý liên quan
void initialize(numStack** w_Stack)
{
	(*w_Stack) = new numStack;
	if (*w_Stack == nullptr)
	{
		cout << "allocate stack containing number failed\n";
		return;
	}
	(*w_Stack)->top = nullptr;
}

void deinitialize(numStack** w_Stack)
{
	if (*w_Stack != nullptr)
	{
		emptiedStack(*w_Stack);
		delete (*w_Stack);
		*w_Stack = nullptr;
	}
}

void emptiedStack(numStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (u_Stack->top != nullptr)
		{
			numNode* pNode = u_Stack->top;
			for (pNode; pNode != nullptr;)
			{
				u_Stack->top = u_Stack->top->pNext;
				delete pNode;
				pNode = u_Stack->top;
			}
		}
	}
}

bool IsEmpty(numStack* r_Stack)
{
	if (r_Stack != nullptr)
	{
		if (r_Stack->top == nullptr)
			return true;
		return false;
	}
}

void push(numStack* u_Stack, float r_val)
{
	if (u_Stack != nullptr)
	{
		numNode* newNode = new numNode{ r_val, nullptr };
		if (IsEmpty(u_Stack))
		{
			u_Stack->top = newNode;
			return;
		}
		newNode->pNext = u_Stack->top;
		u_Stack->top = newNode;
	}

}

float peek(numStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (IsEmpty(u_Stack))
			return NULL;
		return (u_Stack->top->key);
	}
}

void pop(numStack* u_Stack)
{
	if (u_Stack != nullptr)
	{
		if (IsEmpty(u_Stack))
			return;
		numNode* tmp = u_Stack->top;
		u_Stack->top = u_Stack->top->pNext;
		delete tmp;
	}
}