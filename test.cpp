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

//˳��������
void DestroyList(SqList2& L)
{
	if (L.elem) {
		delete L.elem;
	}
}

//˳�������
void ClearList(SqList2& L)
{
	L.length = 0;
}

//�ж�˳����Ƿ�Ϊ��
bool IsEmpty(const SqList2& L)
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

//˳���Ĳ���
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

//˳���Ĳ���
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

//˳����ɾ��
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





//======��������

//������Ķ���
typedef struct Lnode
{
	ElemType data;
	struct Lnode* next;
}Lnode, * LinkList;

//������ĳ�ʼ��
bool InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return true;
}

//ͷ�巨���������룩
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

//β�巨���������룩
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

//�ж������Ƿ�Ϊ��
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

//��������
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

//�������
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

//ͳ��������
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

//����ȡֵ
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
	//		return false;//�����ʱpΪ�գ���ζ���Ѿ���������β�ˣ�ֹͣѭ��
	//	}
	//}
	//e = p->data;
	//return true;
}

//��ֵ����
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

//�������в���Ԫ��
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

//ɾ�������ĳ�����
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




//ѭ������
//ѭ������Ķ���
typedef struct CLnode
{
	ElemType data;
	CLnode* next;
}*CircList;

//ѭ������ĳ�ʼ��
void InitList(CircList& L)
{
	L = new CLnode;
	L->next = L;
}

//ѭ������Ļ��������͵������������ͬ��Ψһ��ͬ���ǣ�����ѭ����������һ������next�����ǿ�ָ�룬
// ����ָ��ͷ��㣬��ˣ�ѭ���еĽ�������Ҫ�����仯
//
//������--------------ѭ������
//while (p)--------->while (p != L)
//while (p->next)--->while (p->next != L)





//˫������
//˫������Ķ���
typedef struct DuLnode
{
	ElemType data;
	DuLnode* prior, * next;
} *DuLinkList;

//˫������ĳ�ʼ��
void InitList(DuLinkList& L)
{
	L = new DuLnode;
	L->prior = nullptr;
	L->next = nullptr;
}

//ͷ�巨����˫������
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

//β�巨����˫������
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

//��˫������ĵ�i��λ�ò���Ԫ��
bool ListInsert_DuL(DuLinkList& L, const int i, const ElemType& e)
{
	//�ƶ�ָ�뵽i��
	DuLnode* p = L->next;
	int j = 1;
	while (p->next && j < i)
	{
		++j;
		p = p->next;
	}
	if (j < i || j < 1) //���i������Χ�ڣ������whileѭ������ֹ��������j<i
	{
		cerr << "out of range" << endl;
		return false;
	}
	//�ڶ�������Ҫ����Ľ��
	DuLnode* s = new DuLnode;
	s->data = e;
	//���½������ӹ�ϵ
	s->prior = p->prior; //��һ����s��ǰ������p��ǰ��
	p->prior->next = s;  //�ڶ�������p��ǰ������nextָ�����Ԫ��s�������˵�һ����
	s->next = p;         //��������s�ĺ��ָ��p
	p->prior = s;        //���Ĳ���p��ǰ����Ϊָ��s�������˵ڶ�����
	//return
	return true;
}

//ɾ��˫�������е�ĳ��Ԫ��
bool ListErase_DuL(DuLinkList& L, const int i)
{
	//�ƶ�ָ�뵽i��
	DuLnode* p = L->next;
	int j = 1;
	while (p->next && j < i)
	{
		++j;
		p = p->next;
	}
	if (j < i || j < 1) //���i������Χ�ڣ������whileѭ������ֹ��������j<i
	{
		cerr << "out of range" << endl;
		return false;
	}
	//�ı����ӹ�ϵ
	p->prior->next = p->next;//p��ǰ������next����p�ĺ��
	if ((p->next))//���ɾ���Ĳ������һ��Ԫ��
	{
		p->next->prior = p->prior;
	}
	//�ͷ�p
	delete p;
	//����
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

