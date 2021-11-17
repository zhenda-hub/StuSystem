#include<fstream>
#include"Student.cpp"

using namespace std;
const string pathName = "\\kcsj.txt";

Student* create_List();
void traverse_List(Student* pHead);
bool is_empty(Student* pHead);
int length_List(Student* pHead);
bool insert_List(Student* pHead, int position, Stu st);
bool delete_List(Student* pHead, int position, Stu* st);
void sort_List(Student* pHead);
void menu_select();
void handle_menu(int s);
void outFile();
Student* inFile();
void delFile();

Student* pHead;


void main()
{
	menu_select();
}

void menu_select()
{
	int s;
	cout << "请输入您要操作的选项:" << endl;
	cout << "1.增加原始记录" << endl;
	cout << "2.按平均分排序显示所有记录" << endl;
	cout << "3.保存原始文件" << endl;
	cout << "4.读取原始文件" << endl;
	cout << "5.删除原始文件" << endl;
	cout << "6.插入单条记录" << endl;
	cout << "7.删除单条记录" << endl;
	cout << "8.显示记录总条数" << endl;
	cout << "9.结束程序运行" << endl << endl;
	cout << "左边数字对应功能选择,请选择1-9:";
	cin >> s;
	handle_menu(s);
}

void handle_menu(int s)
{
	switch (s)
	{
	case 1:
	{
		system("cls");
		pHead = create_List();
		system("cls");
		menu_select();
		break;
	}
	case 2:
	{
		if (NULL == pHead)
		{
			cout << "记录总条数为零" << endl;
			getchar();
			getchar();
			system("cls");
			menu_select();
		}
		system("cls");
		sort_List(pHead);
		traverse_List(pHead);
		getchar();
		getchar();
		system("cls");
		menu_select();
		break;
	}
	case 3:
	{
		if (pHead != NULL)
		{
			system("cls");
			outFile();
			system("cls");
			menu_select();
		}
		system("cls");
		menu_select();
		break;
	}
	case 4:
	{
		system("cls");
		pHead = inFile();
		system("cls");
		menu_select();
		break;
	}
	case 5:
	{
		system("cls");
		delFile();
		system("cls");
		menu_select();
		break;
	}
	case 6:
	{
		if (NULL == pHead)
		{
			cout << "记录总条数为零" << endl;
			getchar();
			getchar();
			system("cls");
			menu_select();
		}
		system("cls");
		int num;
		Stu st;
		traverse_List(pHead);
		cout << "您想在哪条记录后插入,请输入序号:";
		cin >> num;
		cout << "编辑要插入的记录:" << endl;
		cout << "学号:";
		cin >> st.no;
		cout << "姓名:";
		cin >> st.name;
		cout << "数学成绩:";
		cin >> st.math;
		cout << "语文成绩:";
		cin >> st.chi;
		if (insert_List(pHead, num - 1, st))
		{
			cout << "插入成功!" << endl;
		}
		else
		{
			cout << "插入失败!" << endl;
		}
		getchar();
		getchar();
		system("cls");
		menu_select();
		break;
	}
	case 7:
	{
		if (NULL == pHead)
		{
			cout << "记录总条数为零" << endl;
			getchar();
			getchar();
			system("cls");
			menu_select();
		}
		int num;
		Stu* st = (Stu*)malloc(sizeof(Stu));
		traverse_List(pHead);
		cout << endl << "请输入您要删除的记录的序号:";
		cin >> num;
		if (delete_List(pHead, num, st))
		{
			cout << endl << "成功删除的记录如下:" << endl;
			cout << "学号:" << st->no << endl << "姓名:" << st->name << endl;
		}
		else
		{
			cout << "删除失败!" << endl;
		}
		getchar();
		getchar();
		system("cls");
		menu_select();
		break;
	}
	case 8:
	{
		if (NULL != pHead)
		{
			system("cls");
			cout << "记录总条数:" << length_List(pHead) << "条" << endl;
			getchar();
			getchar();
			system("cls");
			menu_select();
		}
		else
		{
			cout << "记录总条数为零" << endl;
			getchar();
			getchar();
			system("cls");
			menu_select();
		}
		break;
	}
	case 9:
	{
		system("cls");
		cout << "成功退出!" << endl;
		exit(0);
		break;
	}
	}
}


void delFile()
{
	ofstream fileout;
	fileout.open(pathName, ios_base::out);
	fileout << "";
	fileout.close();
}


Student* inFile()
{
	Student* pHead = (Student*)malloc(sizeof(Student));
	if (NULL == pHead)
	{
		cout << "分配失败,程序终止!" << endl;
		exit(0);
	}
	Student* pTail = pHead;
	pTail->next = NULL;
	ifstream in(pathName);
	if (!in.is_open())
	{
		cout << "Error opening file" << endl;
		exit(0);
	}
	while (!in.eof())
	{
		Stu st;
		in.read(reinterpret_cast<char*>(&st), sizeof(st));
		if (in.fail())
		{
			break;
		}
		Student* pNew = new Student();
		if (NULL == pNew)
		{
			printf("分配失败,程序终止\n");
			exit(0);
		}
		pNew->setst(st);
		pTail->next = pNew;
		pNew->next = NULL;
		pTail = pNew;
	}
	in.close();
	return pHead;
}


void outFile()
{
	ofstream out;
	out.open(pathName, ios_base::out | ios_base::app | ios::binary);
	if (!out)
	{
		cout << "文件不存在，退出时别忘记保存文件!" << endl;
		out.close();
		out.open("stu.dat", ios_base::out | ios::binary);
	}
	else
	{
		out.close();
		out.open(pathName, ios_base::out | ios_base::app | ios::binary);
	}
	Student* temp = pHead->next;
	while (temp != NULL)
	{
		Stu st = temp->getst();
		out.write(reinterpret_cast<char*>(&st), sizeof(st));
		temp = temp->next;
	}
	out.close();
}

Student* create_List()
{
	int len;
	Student* pHead = (Student*)malloc(sizeof(Student));
	if (NULL == pHead)
	{
		cout << "分配失败,程序终止!" << endl;
		exit(0);
	}
	Student* pTail = pHead;
	pTail->next = NULL;
	cout << "请输入要存储的学生人数:";
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		Stu st;
		cout << "请输入第" << i + 1 << "个学生的学号:";
		cin >> st.no;
		cout << "请输入第" << i + 1 << "个学生的姓名:";
		cin >> st.name;
		cout << "请输入第" << i + 1 << "个学生的数学成绩:";
		cin >> st.math;
		cout << "请输入第" << i + 1 << "个学生的语文成绩:";
		cin >> st.chi;
		Student* pNew = new Student();
		if (NULL == pNew)
		{
			printf("分配失败,程序终止\n");
			exit(0);
		}
		pNew->setst(st);
		pTail->next = pNew;
		pNew->next = NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_List(Student* pHead)
{
	int i = 1;
	Student* temp = pHead->next;
	while (temp != NULL)
	{
		cout << endl << "序号:" << i << endl;
		temp->show();
		temp = temp->next;
		i++;
	}
}

bool is_empty(Student* pHead)
{
	if (NULL == pHead->next)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int length_List(Student* pHead)
{
	int len = 0;
	Student* temp = pHead->next;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

bool insert_List(Student* pHead, int position, Stu st)
{
	int i = 0;
	Student* p = pHead;

	while (NULL != p && i < position - 1)
	{
		p = p->next;
		i++;
	}
	if (i > position - i || NULL == p)
	{
		return false;
	}
	Student* pNew = (Student*)malloc(sizeof(Student));
	if (NULL == pNew)
	{
		cout << "分配失败,程序终止" << endl;
		exit(0);
	}
	pNew->setst(st);
	pNew->next = p->next;
	p->next = pNew;
	return true;
}

bool delete_List(Student* pHead, int position, Stu* st)
{
	int i = 0;
	Student* p = pHead;

	while (NULL != p->next && i < position - 1)
	{
		p = p->next;
		i++;
	}
	Student* q = p->next;
	*st = q->getst();
	p->next = p->next->next;
	free(q);
	q = NULL;
	return true;
}

void sort_List(Student* pHead)
{
	Student* p, * q;
	Stu temp;
	int i, j;
	int len = length_List(pHead);
	for (i = 0, p = pHead->next; i < len - 1; i++, p = p->next)
	{
		for (j = i + 1, q = p->next; j < len; j++, q = q->next)
		{
			if (q->st.ave > p->st.ave)
			{
				temp = q->st;
				q->st = p->st;
				p->st = temp;
			}
		}
	}
}