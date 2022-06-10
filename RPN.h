#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_SIZE 80

#include <iostream>
#include <string>
#include <cmath>
#include "charStack.h"
#include "number_Stack.h"

using namespace std;

// giải quyết biểu thức bằng hậu tố
void solvePostfix(numStack * u_stack, char* expression);

//chuyển biểu thức từ trung tố sang hậu tố
void TransfInfixToPostfix(charStack* u_stack, char* exp, char* result);

//kiểm tra có phải toán tử
bool isOperator(char op);