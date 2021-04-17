#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};

struct list
{
	node* pHead;
	node* pTail;
};

void initList(list& l)
{
	l.pHead = NULL;
};

node* malloc_node(int a)
{
	node* p;
	p = new node;
	if (p == NULL) cout << "Khong du bo nho";
	p->pNext = NULL;
	p->info = a;
	return p;
}

void addFirst(list& l, int k)//Thêm 1 node  vào đầu
{
	node* p = malloc_node(k);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(list& l, int k)//Thêm 1 node vào cuối
{
	node* temp = l.pHead;
	node* q = malloc_node(k);
	while (temp->pNext != NULL)
	{
		temp = temp->pNext;
	}
	temp->pNext = q;
}

void add_after_node(list& l,node*p, int k)
{
	node* q = malloc_node(k);
	node* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp == p)
		{
			q->pNext = temp->pNext;
			temp->pNext = q;
		}
		temp = temp->pNext;
	}
}

void Input_list(list& l, int& n)
{
	int k;
	cout << "Nhap so node: "; cin >> n;
	initList(l);
	node* temp = l.pHead;
	int i = 0;
	while (i<n)
	{
		i++;
		
		if (l.pHead == NULL)
		{
			cout << "Node "<<i<<": "; cin >> k;
			addFirst(l, k);
		}
		else
		{
			cout << "Node " << i << ": "; cin >> k;
			addTail(l, k);
		}
	}
}
void Output_list(list& l)
{
	node* p;
	if (l.pHead == NULL)
		cout << "danh sach trong";
	else
		for (p = l.pHead; p; p = p->pNext)
		{
			cout << p->info << "   ";
		}
}
node* search_value_node(list& l, int& value)
{
	cout << "Nhap gia tri can tim kiem: ";
	cin >> value;
	node* temp = l.pHead;
	node* search = NULL;
	while (temp != NULL)
	{
		if (temp->info == value) search = temp;
		temp = temp->pNext;
	}
	return search;
}

node* search_Tail(list& l)
{
	node* temp = l.pHead;
	while (temp->pNext != NULL)
	{
		temp = temp->pNext;
	}
	return temp;
}

node* search_location_node(list& l, int& value)
{
	cout << "Nhap vi tri can tim kiem: ";
	cin >> value;
	int k = 1;
	node* temp = l.pHead;
	node* search = NULL;
	while (temp != NULL)
	{
		if (k == value) search = temp;
		temp = temp->pNext;
		k++;
	}
	return search;
}
void swap_node(list& l, node* node1, node* node2)
{
	int temp;
	temp = node1->info;
	node1->info = node2->info;
	node2->info = temp;
}

int main()
{
	list l;
	int n = 0,value=0;
	node* search;
	Input_list(l, n);
	Output_list(l);
	cout << endl;
	search = search_value_node(l, value);
	if (search == NULL) cout << "Khong co gia tri can tim kiem";
	else cout << search->info;
	search = search_Tail(l);
	cout << endl;
	cout << "Phan tu cuoi cua danh sach la: " << search->info << endl;
	search = search_location_node(l, value);
	cout << "Phan tu thu " << value << " cua danh sach la: " << search->info << endl;
	return 0;
}