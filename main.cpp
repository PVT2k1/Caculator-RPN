#include "RPN.h"

int main()
{
	numStack* numS = nullptr;
	charStack* charS = nullptr;
	initialize(&numS);
	if (numS != nullptr)
	{
		initializeChar(&charS);
		if (charS != nullptr)
		{
			char exp[MAX_SIZE] = { '\0' }, result[MAX_SIZE] = { '\0' };
			cout << "Enter infix expression: ";
			cin.getline(exp, 80);
			TransfInfixToPostfix(charS, exp, result);
			cout << "Postfix expression: " << result << "\n";
			solvePostfix(numS, result);
			cout << "Result: " << numS->top->key;
			deinitializeChar(&charS);
		}
		deinitialize(&numS);
	}
}