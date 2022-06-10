#pragma once
//Node chứa số
struct numNode
{
	float key;
	numNode* pNext;
};

struct numStack
{
	numNode* top;
};

//khởi tạo numStack 
void initialize(numStack** w_Stack);

//hủy numStack 
void deinitialize(numStack** w_Stack);

//làm rỗng stack
void emptiedStack(numStack* u_Stack);

//kiểm tra rỗng
bool IsEmpty(numStack* r_Stack);

//thêm vao top
void push(numStack* u_Stack, float r_val);

//lấy phần tử ở top
float peek(numStack* u_Stack);

//xóa ở top
void pop(numStack* u_Stack);