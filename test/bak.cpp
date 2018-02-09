#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

//strcpy����
char *mystrcpy(char *dest, const char *src)
{
	assert(NULL!=dest && NULL!=src);
	char *addr = dest;
	while((*dest++=*src++)!='\0')
	NULL;
	return addr;
}

//strlen����
int mystrlen(const char *str)
{
	assert(str!=NULL);
	int len = 0;
	while(*str++!='\0')
		++len;
	return len;
}

//strcmp����
int mystrcmp(const char *s, const char *t)
{
	assert(NULL!=s && NULL!=t);
	while(*s&&*t&&*s==*t)
	{
		++s;
		++t;
	}
	return *s-*t;
}

//strcat����
char *mystrcat(char *dest, const char *src)
{
	assert(NULL!=dest && NULL!=src);
	char *addr = dest;
	while(*dest!='\0')
		dest++;
	while((*dest++=*src++)!='\0')
	NULL;
	return addr;

}

//memcpy����
void *mymemcpy(void *dest, const void *src,int count)
{
	assert(NULL!=dest && NULL!=src);
	void *addr = dest;
	while(count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest+1;
		src = (char*)src + 1;
	}
	return addr;
}

//memcpy����
void *mymemset(void *dest, int ch, int count)
{
	assert(NULL!=dest);
	void *addr = dest;
	while(count--)
	{
		*(char*)dest = (char)ch;
		dest = (char*)dest+1;
	}
	return addr;
}

//string���Ա����
class String
{
	public:
		String(const char *str=NULL);
		~String();
		String(const String &rhs);
		String& operator=(const String&rhs);
	protected:
	private:
		char *m_data;
};

//string�๹�캯��
//String::String(const char *str)

String::String(const char *str)
{
	if(NULL==str)
	{
		m_data = new char[1];
		m_data[0] = '\0';

	}
	else
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data,str);
	}
	cout<<"���캯��"<<endl;
}


//string����������
String::~String()
{
	if(NULL!=m_data)
	{
		delete []m_data;
		m_data = NULL;
	}
	cout<<"��������"<<endl;
}

//string�࿽�����캯��
String::String(const String &rhs)
{
	m_data = new char[strlen(rhs.m_data)+1];
	strcpy(m_data,rhs.m_data);
	cout<<"�������캯��"<<endl;
}

//string�ำֵ���캯��
String& String::operator=(const String &rhs)
{
	if(this==&rhs)
		return *this;
	delete []m_data;
	m_data = new char[strlen(rhs.m_data)+1];
	strcpy(m_data,rhs.m_data);
	cout<<"��ֵ���캯��"<<endl;
	return *this;

}

//����ڵ㶨��
typedef struct Node{
	int data;
	Node *next;
}Node;

//��������
Node *create(int num)
{
	Node *head=NULL, *p=NULL, *s=NULL;
	for(int i=0;i<num;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = i+1;
		if(NULL==head)
		{
			head = p;
			s = p;
		}
		else
		{
			s->next = p;
			s=s->next;
		}		
	}
	s->next = NULL;
	return head;
}

//��������
Node *reverse(Node *head)
{
	Node *p,*s,*t;
	if(NULL==head)
		return;
	p = head;
	s = p->next;
	t = s->next;
	p->next = NULL;
	while(t)
	{
		s->next = p;
		p = s;
		s = t;
		t = t->next;
	}
	s->next = p;
	return s;
	
}

//��ӡ����
void print(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}

//�����ں�
Node *merge(Node *head1, Node *head2)
{
	Node *head;
	if(NULL==head1)
		return head2;
	if(NULL==head2)
		return head1;
	
	if(head1->data<head2->data)
	{
		head = head1;
		head->next = merge(head1->next,head2);
	}
	else
	{
		head = head2;
		head->next = merge(head1,head2->next);
	}
	return head;
}

//�������л�
bool checkLoop(Node *head)
{
	Node *low,*fast;
	if(NULL == head || NULL == head->next)
		return false;
	low = head,fast = head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		low = low->next;
		fast = fast->next->next;
		if(low == fast)
			return true;
	}
	return false;
}

//ð������
void bubbleSort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//ѡ������
void selectSort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//int�����ӡ
void printArr(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i];
	cout<<endl;
}

//�������ڵ㶨��
typedef struct BiTNode{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode, *BiTree;


//����������
void createBiTree(BiTree &T)
{
	char ch;
	cin>>ch;
	if('#' == ch)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}

//ǰ�����
void PreOrder(BiTree T)
{
	if(NULL == T)
		return;
	
	cout<<T->data;
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	
}

//�������
void InOrder(BiTree T)
{
	if(NULL == T)
		return;

	InOrder(T->lchild);
	cout<<T->data;
	InOrder(T->rchild);

}

//�������
void LastOrder(BiTree T)
{
	if(NULL == T)
		return;

	LastOrder(T->lchild);
	LastOrder(T->rchild);
	cout<<T->data;
	
}

//�������߶�/���
int Height(BiTree T)
{
	if(NULL == T)
		return 0;
	int left = Height(T->lchild);
	int right = Height(T->rchild);
	return (left>right)?(left+1):(right+1);
}

const int StackSize = 10;

//ջ�ඨ��
class Stack{
	public:
		void display();
		void pushInt(int x);
		int popInt();
		void isEmpty();
		int getTop();
		Stack();
		~Stack();
	protected:
	private:
		int top;
		int data[StackSize];
};

Stack::Stack()
{
	top = -1;
}
Stack::~Stack()
{}

void Stack::isEmpty()
{
	if(-1 == top)
		cout<<"ջΪ��"<<endl;
	else
		cout<<"ջ��Ϊ��"<<endl;
}

void Stack::pushInt(int x)
{
	if(StackSize-1 == top)
		cout<<"ջ��"<<endl;
	else
	{
		data[++top] = x;
	}
}

int Stack::popInt()
{
	int tmp = -1;
	if(-1 == top)
		cout<<"ջΪ��"<<endl;
	else
	{
		tmp = data[top--];
	}
	return tmp;
}

int Stack::getTop()
{
	int tmp = -1;
	if(-1 != top)
	{
		tmp= data[top];
	}
	return tmp;
}

void Stack::display()
{
	for(int i=top;i>=0;i--)
	{
		if(0 == i)
			cout<<data[i];
		else
			cout<<data[i]<<",";
	}
	cout<<endl;
}

typedef struct {
	int data[StackSize];
	int top;
}SqStack;

void Push(SqStack *st, int x)
{
	
}

int main(int argc, char **argv)
{
/*
	Node *head = NULL;
	head = create(5);
	print(head);
	Node *head2 = reverse(head);
	print(head2);
	
	int arr1[] = {1,3,2,5,4};
	int arr2[] = {1,3,2,5,4};
	printArr(arr1,5);
	printArr(arr2,5);
	bubbleSort(arr1,5);
	selectSort(arr2,5);
	printArr(arr1,5);
	printArr(arr2,5);
	
	BiTree T;
	createBiTree(T);
	PreOrder(T);
	cout<<endl;
	InOrder(T);
	cout<<endl;
	LastOrder(T);
	cout<<endl;
	cout<<Height(T)<<endl;
*/

	Stack st;
	st.isEmpty();

	for(int i=0;i<10;i++)
		st.pushInt(i+1);
		
	st.isEmpty();

	st.display();
	cout<<st.popInt()<<endl;
	st.display();

	return 0;
}
