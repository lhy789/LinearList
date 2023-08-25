#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100

#include<iostream>

using namespace std;

typedef int ElemType;
typedef struct
{
	ElemType elem[MaxSize];
	int length;
} SqList1;	//顺序表的类型定义1（静态分配）
typedef struct 
{
	ElemType* elem;
	int length;
}SqList2;	//顺序表的类型定义2（动态分配）

//顺序表的初始化
bool InitList(SqList2 &L)
{
	//L.elem = (ElemType*)malloc(sizeof(ElemType) * MaxSize);	//C
	L.elem = new ElemType[MaxSize];	//C++
	if (!L.elem)
	{
		cerr << "error" << endl;
		return false;
	}
	L.length = 0;
	return 1;
}

//顺序表的销毁
void DestroyList(SqList2 &L)
{
	if (L.elem) {
		delete L.elem;
	}
}

//顺序表的清空
void ClearList(SqList2 &L)
{
	L.length = 0;
}

//判断顺序表是否为空
bool IsEmpty(const SqList2 &L)
{
	return static_cast<bool>(L.length);
}

//顺序表的取值
bool GetElem(const SqList2& L, const int i, ElemType& e) 
{	
	if (i<1 || i>L.length)
	{
		cerr << "out of range" << endl;
		return false;
	}
	e = L.elem[i - 1];
	return true;
}

//



int main()
{
	return 0;
}

