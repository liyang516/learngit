#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <iostream>
#include <vector.h>
using namespace std;

#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <iostream.h>
#include <fcntl.h>
#include <sys/types.h>

#define PORT 8888

//strcpy函数
char *mystrcpy(char *dest, const char *src)
{
	assert(NULL!=dest && NULL!=src);
	char *addr = dest;
	while((*dest++=*src++)!='\0')
	NULL;
	return addr;
}

//strlen函数
int mystrlen(const char *str)
{
	assert(str!=NULL);
	int len = 0;
	while(*str++!='\0')
		++len;
	return len;
}

//strcmp函数
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

//strcat函数
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

//memcpy函数
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

//memcpy函数
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

//string类成员函数
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

//string类构造函数
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
	cout<<"构造函数"<<endl;
}


//string类析构函数
String::~String()
{
	if(NULL!=m_data)
	{
		delete []m_data;
		m_data = NULL;
	}
	cout<<"析构函数"<<endl;
}

//string类拷贝构造函数
String::String(const String &rhs)
{
	m_data = new char[strlen(rhs.m_data)+1];
	strcpy(m_data,rhs.m_data);
	cout<<"拷贝构造函数"<<endl;
}

//string类赋值构造函数
String& String::operator=(const String &rhs)
{
	if(this==&rhs)
		return *this;
	delete []m_data;
	m_data = new char[strlen(rhs.m_data)+1];
	strcpy(m_data,rhs.m_data);
	cout<<"赋值构造函数"<<endl;
	return *this;

}

//链表节点定义
typedef struct Node{
	int data;
	Node *next;
}Node;

//创建链表
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

//链表逆序
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

//打印链表
void print(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head = head->next;
	}
}

//链表融合
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

//单链表有环
bool checkLoop(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	return (fast==NULL || fast->next==NULL);
}

int loopLength(Node *head)
{
	bool again = false;
	bool begin = false;
	Node *slow = head;
	Node *fast = head;
	int length = 0;
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast && again==false)
		{
			again = true;
			begin = true;
		}
		if(slow==fast && begin==true)
			break;
		if(begin == true)
			length++;
	}
	return length;
	
}

//冒泡排序
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

//选择排序
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

//插入排序
void insertSort(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

//int数组打印
void printArr(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i];
	cout<<endl;
}

//二叉树节点定义
typedef struct BiTNode{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
}BiTNode, *BiTree;


//创建二叉树
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

//前序遍历
void PreOrder(BiTree T)
{
	if(NULL == T)
		return;
	
	cout<<T->data;
	PreOrder(T->lchild);
	PreOrder(T->rchild);
	
}

//中序遍历
void InOrder(BiTree T)
{
	if(NULL == T)
		return;

	InOrder(T->lchild);
	cout<<T->data;
	InOrder(T->rchild);

}

//后序遍历
void LastOrder(BiTree T)
{
	if(NULL == T)
		return;

	LastOrder(T->lchild);
	LastOrder(T->rchild);
	cout<<T->data;
	
}

//二叉树高度/深度
int Height(BiTree T)
{
	if(NULL == T)
		return 0;
	int left = Height(T->lchild);
	int right = Height(T->rchild);
	return (left>right)?(left+1):(right+1);
}

const int MaxSize = 10;

//栈类定义
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
		int data[MaxSize];
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
		cout<<"栈为空"<<endl;
	else
		cout<<"栈不为空"<<endl;
}

void Stack::pushInt(int x)
{
	if(MaxSize-1 == top)
		cout<<"栈满"<<endl;
	else
	{
		data[++top] = x;
	}
}

int Stack::popInt()
{
	int tmp = -1;
	if(-1 == top)
		cout<<"栈为空"<<endl;
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
	int data[MaxSize];
	int top;
}SqStack;

void Push(SqStack *st, int x)
{
	
}

//队列定义
class SqQueue
{
	public:
		SqQueue();
		~SqQueue();
	protected:
	private:
		int data[MaxSize];
		int front;
		int rear;
};

SqQueue::SqQueue()
{
	front = 0;
	rear = 0;
}

SqQueue::~SqQueue()
{}



int main(int argc, char **argv)
{

	vector<string> vec_host;
	while(1)
	{
		sleep(1);
		vec_host.clear();
	}
	
	return 0;
}
