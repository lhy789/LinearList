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
bool InitList(SqList2& L)
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
void DestroyList(SqList2& L)
{
	if (L.elem) {
		delete L.elem;
	}
}

//顺序表的清空
void ClearList(SqList2& L)
{
	L.length = 0;
}

//判断顺序表是否为空
bool IsEmpty(const SqList2& L)
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

//顺序表的查找
int LocateList(const SqList2& L, const ElemType& e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

//顺序表的插入
bool InsertList(SqList2& L, const ElemType& e, const int& i)
{
	if (L.length >= MaxSize)
	{
		cerr << "can not inert!" << endl;
		return false;
	}
	if (i<1 || i>L.length + 1)
	{
		cerr << "wrong insert position!" << endl;
		return false;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	L.length++;
	return true;
}

//顺序表的删除
bool EraseList(SqList2& L, const int& i, ElemType& e)
{
	if (i<1 || i>L.length)
	{
		cerr << "wrong erase position!" << endl;
		return false;
	}
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return true;
}





//======单向链表

//单链表的定义
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;

//单链表的初始化
bool InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return true;
}

//头插法（倒序输入）
LinkList List_headInsert(LinkList& L, const size_t t)
{
	Lnode* p = NULL;
	L = new Lnode;
	L->next = NULL;
	for (int i = 0; i < t; i++)
	{
		p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

//尾插法（正序输入）
void List_tailInsert(LinkList& L, const size_t t)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* p = L;
	for (int i = 0; i < t; i++)
	{
		Lnode* temp = new Lnode;
		cin >> temp->data;
		temp->next = NULL;
		p->next = temp;
		p = temp;
	}
	p->next = NULL;
}

//判断链表是否为空
bool IsEmpty(const LinkList& L)
{
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//销毁链表
bool DestroyList(LinkList& L)
{
	while (L)
	{
		Lnode* p = L;
		L = L->next;
		delete p;
	}
	return true;
}

//清空链表
bool ClearList(LinkList& L)
{
	if (L->next)
	{
		cerr << "it is empty!!!" << endl;
		return false;
	}
	Lnode* p = L->next;
	while (p)
	{
		Lnode* q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return true;
}

//统计链表长度
int ListLength(LinkList& L)
{
	Lnode* p = L->next;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

//链表取值
bool GetElem(const LinkList& L, const int& i, ElemType& e)
{
	if (i < 0)
	{
		cerr << "out of range" << endl;
		e = -1;
		return false;
	}
	Lnode* p = L->next;
	int j = 1;
	while (p)
	{
		if (j == i)
		{
			e = p->data;
			return true;
		}
		else
		{
			p = p->next;
			j++;
		}
	}
	cerr << "not here!!!" << endl;
	return false;
	//Lnode* p = L->next;
	//for (int j = 1; j < i + 1; ++j)
	//{
	//	p = p->next;
	//	if (!p)
	//	{
	//		cerr << "out of range" << endl;
	//		return false;//如果此时p为空，意味着已经到达链表尾端，停止循环
	//	}
	//}
	//e = p->data;
	//return true;
}

//按值查找
size_t LocateElem(LinkList& L, ElemType& e)
{
	Lnode* p = L->next;
	int cnt = 1;
	while (p)
	{
		if (p->data == e)
		{
			return cnt;
		}
		else
		{
			++cnt;
			p = p->next;
		}
	}
	cerr << "not found!!!" << endl;
	return 0;
}

//在链表中插入元素
bool InsertList(LinkList& L, const int& i, const ElemType& e)
{
	Lnode* p = L;
	if (i < 1 || !p)
	{
		cerr << "not here" << endl;
		return false;
	}
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	Lnode* temp = new Lnode;
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	return 1;
}

//删除链表的某个结点
bool EraseList(LinkList& L, const int& i)
{
	Lnode* p = L;
	int j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || i < 1)
	{
		cerr << "out of range" << endl;
		return false;
	}
	Lnode* q = p->next;
	p->next = p->next->next;
	delete q;
	return true;
}




//循环链表
//循环链表的定义
typedef struct CLnode
{
	ElemType data;
	CLnode* next;
}*CircList;

//循环链表的初始化
void InitList(CircList& L)
{
	L = new CLnode;
	L->next = L;
}

//循环链表的基本操作和单链表基本上相同，唯一不同的是，由于循环链表的最后一个结点的next不再是空指针，
// 而是指向头结点，因此，循环中的结束条件要发生变化
//
//单链表--------------循环链表
//while (p)--------->while (p != L)
//while (p->next)--->while (p->next != L)





//双向链表
//双向链表的定义
typedef struct DuLnode
{
	ElemType data;
	DuLnode* prior, * next;
} *DuLinkList;

//双向链表的初始化
void InitList(DuLinkList& L)
{
	L = new DuLnode;
	L->prior = nullptr;
	L->next = nullptr;
}

//头插法创建双向链表
void CreatListHead(DuLinkList& L, const size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		DuLnode* p = new DuLnode;
		cin >> p->data;
		p->prior = L;
		p->next = L->next;
		L->next = p;
	}
}

//尾插法创建双向链表
void CreatListTail(DuLinkList& L, const size_t n)
{
	DuLnode* r = L;
	for (int i = 0; i < n; ++i)
	{
		DuLnode* p = new DuLnode;
		cin >> p->data;
		p->prior = r;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}

//在双向链表的第i个位置插入元素
bool ListInsert_DuL(DuLinkList& L, const int i, const ElemType& e)
{
	//移动指针到i处
	DuLnode* p = L->next;
	int j = 1;
	while (p->next && j < i)
	{
		++j;
		p = p->next;
	}
	if (j < i || j < 1) //如果i在链表范围内，上面的while循环的终止条件就是j<i
	{
		cerr << "out of range" << endl;
		return false;
	}
	//在堆区创建要插入的结点
	DuLnode* s = new DuLnode;
	s->data = e;
	//重新建立链接关系
	s->prior = p->prior; //第一步：s的前趋等于p的前趋
	p->prior->next = s;  //第二步，用p的前趋结点的next指向插入元素s，更改了第一条链
	s->next = p;         //第三步：s的后继指向p
	p->prior = s;        //第四步：p的前趋改为指向s，更改了第二条链
	//return
	return true;
}

//删除双向链表中的某个元素
bool ListErase_DuL(DuLinkList& L, const int i)
{
	//移动指针到i处
	DuLnode* p = L->next;
	int j = 1;
	while (p->next && j < i)
	{
		++j;
		p = p->next;
	}
	if (j < i || j < 1) //如果i在链表范围内，上面的while循环的终止条件就是j<i
	{
		cerr << "out of range" << endl;
		return false;
	}
	//改变链接关系
	p->prior->next = p->next;//p的前趋结点的next等于p的后继
	if ((p->next))//如果删除的不是最后一个元素
	{
		p->next->prior = p->prior;
	}
	//释放p
	delete p;
	//结束
	return true;
}


void test01()
{

}

int main()
{
	test01();
	return 0;
}

