#include<iostream>
using namespace std;
struct Student
{
	char id[9];
	char name[20];
	float Mark[3];
	float dtb;
};
struct node
{
	Student info;
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

node* malloc_node(Student a)
{
	node* p;
	p = new node;
	if (p == NULL) cout << "Khong du bo nho";
	p->pNext = NULL;
	p->info = a;
	return p;
}

void addFirst(list& l, Student k)//Thêm 1 node  vào đầu
{
	node* p = malloc_node(k);
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(list& l, Student k)//Thêm 1 sinh viên vào danh sách
{
	node* temp = l.pHead;
	node* q = malloc_node(k);
	while (temp->pNext != NULL)
	{
		temp = temp->pNext;
	}
	temp->pNext = q;
}

void add_after_node(list& l, node* p, Student k)
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
void Input_struct(Student& k)
{
	cin.ignore();
	cout << "Nhap ten: ";
	cin.getline(k.name, 20);
	
	cin.ignore();
	cout << "Nhap id: ";
	cin.getline(k.id, 11);
	//cin.ignore();

	cout << "Nhap diem: ";
	for (int i = 0; i < 3; i++)
	{
		cin >> k.Mark[i];
	}
	k.dtb = k.Mark[0]*0.25 + k.Mark[1]*0.25 + k.Mark[2]*0.5;
}
void Xeploai(Student S)
{
	if (S.dtb < 5) cout << "Yeu";
	if ((S.dtb >= 5 )&&(S.dtb <7)) cout<<"Trung Binh";
	if ((S.dtb >= 7) && (S.dtb < 8)) cout << "Kha";
	if (S.dtb > 8) cout << "Xuat sac";
}

void Input_list(list& l, int& n)
{
	Student k;
	cout << "Nhap so node: "; cin >> n;
	initList(l);
	node* temp = l.pHead;
	int i = 0;
	while (i < n)
	{
		i++;

		if (l.pHead == NULL)
		{
			cout << "Node " << i << ": "<<endl; Input_struct(k);
			addFirst(l, k);
		}
		else
		{
			cout << "Node " << i << ": "<<endl; Input_struct(k);
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
			cout << endl;
			cout << p->info.id << "   " << p->info.name << "    " << p->info.dtb << "    ";
			Xeploai(p->info);
			cout << endl;
		}
}


int main()
{
	Student k;
	list l;
	int n = 0;
	Input_list(l, n);
	Output_list(l);
	cout << "Nhap them mot sinh vien: "<<endl;
	cout << "Nhap thong tin sinh vien: " << endl;
	Input_struct(k);
	addTail(l, k);
	cout << "Danh sach sau khi them: ";
	Output_list(l);
	return 0;
	
}