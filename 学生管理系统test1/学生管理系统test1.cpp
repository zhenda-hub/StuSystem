// 学生管理系统test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void ShowUI()
{
    cout << "=================================学生信息管理系统==================================" << endl;
	cout << "-------------------------------------功能菜单--------------------------------------" << endl;
	cout << "\t\t\t\t1. 录入学生信息" << endl;
	cout << "\t\t\t\t2. 查找学生信息" << endl;
	cout << "\t\t\t\t3. 删除学生信息" << endl;
	cout << "\t\t\t\t4. 修改学生信息" << endl;
	cout << "\t\t\t\t5. 排序" << endl;
	cout << "\t\t\t\t6. 统计学生总人数" << endl;
	cout << "\t\t\t\t7. 显示所有学生信息" << endl;
	cout << "\t\t\t\t0. 退出系统" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

    
}

void Insert() {}

void Search() {}

void Delete_info() {}

void Modify() {}

void Sort_info() {}

void TotalNum() {}

void ShowAll() {}




int main()
{
	while (true)
	{
		cout << "欢迎使用学生管理系统！！" << endl;
		ShowUI();
		int answer;
		cout << "请输入功能对应的编号：" << endl;
		try
		{
			cin >> answer;

		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}

		if ((int)answer == 0)
		{
			cout << "谢谢您的使用，再见！" << endl;
			break;
		}
		else if ((int)answer == 1)
		{
			Insert();

		} 
		else if ((int)answer == 2)
		{
			Search();

		}
		else if ((int)answer == 3)
		{
			Delete_info();

		}
		else if ((int)answer == 4)
		{
			Modify();

		}
		else if ((int)answer == 5)
		{
			Sort_info();

		}
		else if ((int)answer == 6)
		{
			TotalNum();

		}
		else if ((int)answer == 7)
		{
			ShowAll();

		}
		else
		{
			cout << "输入异常，请重新输入" << endl;
			continue;
		}
		
		

	}
	

    return 0;
}
