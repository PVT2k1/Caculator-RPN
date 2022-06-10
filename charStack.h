#pragma once
//Node chứa ký tự
struct charNode
{
	char key;
	charNode* pNext;
};

struct charStack
{
	charNode* top;
};

//khởi tạo charStack
void initializeChar(charStack** w_Stack);

//hủy charStack
void deinitializeChar(charStack** w_Stack);

//làm rỗng stack
void emptiedStackChar(charStack* u_Stack);

//kiểm tra stack rỗng
bool IsEmptyChar(charStack* r_Stack);

//thêm ở top
void pushChar(charStack* u_Stack, char r_char);

//lấy phần tử ở top
char peekChar(charStack* u_Stack);

//xóa ở top
void popChar(charStack* u_Stack);

