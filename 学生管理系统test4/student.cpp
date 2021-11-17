#include <iostream>
#include <cstdlib>
#include <string>
#include"student.h"
using namespace std;

//析构函数
Student::~Student()
{
	delete(St);
}

//输入学生的信息
void Student::InputStudent(void)
{
	int len;//学生的人数
	cout << "请输入学生的人数:";
	cin >> len;

	system("cls");

	Size = len;

	St = new Student[Size];

	for (int i = 0; i < len; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的姓名:";
		cin >> St[i].Name;

		cout << "请输入第" << i + 1 << "个学生的年龄:";
		cin >> St[i].Age;

		cout << "请输入第" << i + 1 << "个学生的学号:";
		cin >> St[i].No;



		system("cls");
	}
}
//输出学生的信息
void Student::OutputStudent(void)
{
	cout << "姓名  年龄   学号   " << endl;

	for (int i = 0; i < Size; i++)
	{
		cout << St[i].Name << "  " << St[i].Age << "  " << St[i].No << endl;
	}
}

void Student::DeleteStudent(void)//删除学生信息
{
	string str;
	cout << "请输入你需要删除的学生的姓名:";
	cin >> str;

	int num;//标记姓名相等时的下标

	//寻找姓名相等时的下标
	for (int i = 0; i < Size; i++)
	{
		//当姓名相等时
		if (str == St[i].Name)
		{
			num = i;
		}
	}

	//将后面的学生向前移
	for (int j = num + 1; j < Size; j++)
	{
		St[j - 1] = St[j];
	}

	Size -= 1;//学生人数减少一个 
}

void Student::SearchStudent(void)//查找学生信息
{
	string name;
	cout << "请输入你需要查找的学生的姓名:";
	cin >> name;

	int i;

	for (i = 0; i < Size; i++)
	{
		if (name == St[i].Name)
		{
			break;
		}
	}

	cout << St[i].Name << " " << St[i].Age << " " << St[i].No << endl;
}

void Student::ChangeStudent(void)//修改学生信息
{
	string name;
	cout << "请输入你需要修改的学生的姓名:";
	cin >> name;

	int i;

	for (i = 0; i < Size; i++)
	{
		if (name == St[i].Name)
		{
			break;
		}
	}

	cout << "修改前学生的信息:" << endl;
	cout << St[i].Name << " " << St[i].Age << " " << St[i].No << endl << endl;

	cout << "请输入学生的姓名:";
	cin >> St[i].Name;

	cout << "请输入学生的年龄:";
	cin >> St[i].Age;

	cout << "请输入第个学生的学号:";
	cin >> St[i].No;


}

void Student::choice()
{
	cout << "*************************欢迎使用学生成绩管理系统*******************************\n" << endl;


	cout << "请按任意将进入学生管理系统:" << endl;
	getchar();

	system("cls");

	cout << "================================================================================\n\n";
	cout << "------------------------ 请选择要操作的命令：-----------------------------------\n\n";
	cout << "-------------------------- 1 输入学生信息--------------------------------------\n\n";
	cout << "-------------------------- 2 输出学生信息--------------------------------------\n\n";
	cout << "-------------------------- 3 删除学生信息--------------------------------------\n\n";
	cout << "-------------------------- 4 查找学生信息--------------------------------------\n\n";
	cout << "-------------------------- 5 修改学生信息--------------------------------------\n\n";
	cout << "================================================================================\n\n";

	int Item;//操作命令

	Student st;//学生对象

	while (1)
	{
		cout << "请选择操作命令: 1输入 2输出 3删除 4查找 5修改\n";
		cin >> Item;
		system("cls");//清屏  

		switch (Item)
		{
		case 1://输入学生信息  
		{
			st.InputStudent();
		}
		break;

		case 2://输出学生信息  
		{
			st.OutputStudent();
		}
		break;

		case 3://删除学生信息  
		{
			st.DeleteStudent();
		}
		break;

		case 4://查找学生信息  
		{
			st.SearchStudent();
		}
		break;

		case 5://修改学生信息  
		{
			st.ChangeStudent();
		}
		break;


		}

		system("pause");
	}
}

