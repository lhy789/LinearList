#define _CRT_SECURE_NO_WARNINGS 1
#define MaxSize 100

#include<iostream>

using namespace std;

typedef int ElemType;
typedef struct
{
	ElemType elem[MaxSize];
	int length;
} SqList1;	//˳�������Ͷ���1����̬���䣩
typedef struct 
{
	ElemType* elem;
	int length;
}SqList2;	//˳�������Ͷ���2����̬���䣩

//˳���ĳ�ʼ��
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

//˳��������
void DestroyList(SqList2 &L)
{
	if (L.elem) {
		delete L.elem;
	}
}

//˳�������
void ClearList(SqList2 &L)
{
	L.length = 0;
}

//�ж�˳����Ƿ�Ϊ��
bool IsEmpty(const SqList2 &L)
{
	return static_cast<bool>(L.length);
}

//˳����ȡֵ
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

