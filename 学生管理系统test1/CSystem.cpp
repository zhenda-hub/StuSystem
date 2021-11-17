#include "CSystem.h"
#include "CStudent.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void CSystem::ShowUI()
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

void CSystem::Save(vector<CStudent> m_stuVec)
{
	ofstream wfile("stuInfo.txt");
	if (!wfile.is_open())
	{
		cout << "文件打开失败" << endl;
	}

	//写入

	//wfile << m_stuVec.size() << endl;

	for (int i = 0; i < m_stuVec.size(); i++)
	{

		wfile << m_stuVec[i].getm_num() << '\t'
			<< m_stuVec[i].getm_name() << '\t'
			<< m_stuVec[i].getm_iEnglishScore() << '\t'
			<< m_stuVec[i].getm_iPythonScore() << '\t'
			<< m_stuVec[i].getm_iJavaScore() << endl;

	}

	wfile.close();
}

void CSystem::ReadFile()
{
	ifstream rfile("stuInfo.txt");
	if (!rfile.is_open())
	{
		cout << "读取文件失败" << endl;
	}

	string num, name;
	int engls, pys, javas;
	while (rfile >> num >> name >> engls >> pys >> javas)//读取文件最好的方法！！！！
	{
		CStudent st(num, name, engls, pys, javas);
		m_stuVec.push_back(st);

	}
	rfile.close();
}

void CSystem::ShowAll()
{
	cout << "学号" << "\t" << "姓名" << "\t" << "英语" << "\t" << "python" << "\t" << "java" << endl;
	vector<CStudent>::iterator it;
	for (it = m_stuVec.begin(); it!=m_stuVec.end(); it++)
	{
		cout << it->getm_num() << "\t" << it->getm_name() << "\t" << it->getm_iEnglishScore()
			<< "\t" << it->getm_iPythonScore() << "\t" << it->getm_iJavaScore() << endl;
	}

}

void CSystem::Insert()
{
	while (true)
	{
		string num, name;
		int engls, pys, javas;
		cout << "请输入学生编号:" << endl;
		cin >> num;
		cout << "请输入学生姓名:" << endl;
		cin >> name;
		cout << "请输入学生英语成绩:" << endl;
		cin >> engls;
		cout << "请输入学生python成绩:" << endl;
		cin >> pys;
		cout << "请输入学生java成绩:" << endl;
		cin >> javas;
		CStudent st(num, name, engls, pys, javas);

		m_stuVec.push_back(st);

		char answerk;
		while (true)
		{
			cout << "是否继续？(y/n)" << endl;
			cin >> answerk;
			if (!(answerk == 'y' || answerk == 'n'))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (answerk == 'y')
		{
			continue;
		}
		else if (answerk == 'n')
		{
			break;
		}
	}

	Save(m_stuVec);
}

void CSystem::Search()
{
	while (true)
	{
		cout << "请输入查找学生的学号：" << endl;
		string num;
		cin >> num;

		vector<CStudent>::iterator it;
		bool flag = false;
		for (it = m_stuVec.begin(); it != m_stuVec.end(); it++)
		{
			if (it->getm_num() == num)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			cout << "找到学生信息" << endl;
			cout << "学号" << "\t" << "姓名" << "\t" << "英语" << "\t" << "python" << "\t" << "java" << endl;
			cout << it->getm_num() << "\t" << it->getm_name() << "\t" << it->getm_iEnglishScore()
				<< "\t" << it->getm_iPythonScore() << "\t" << it->getm_iJavaScore() << endl;
		} 
		else
		{
			cout << "没有找到学生信息" << endl;
		}

		char answerk;
		while (true)
		{
			cout << "是否继续？(y/n)" << endl;
			cin >> answerk;
			if (!(answerk == 'y' || answerk == 'n'))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (answerk == 'y')
		{
			continue;
		}
		else if (answerk == 'n')
		{
			break;
		}
	}
}

void CSystem::Delete_info()
{
	string answer;
	vector<string> fileText;
	while (true)
	{
		ShowAll();
		cout << "请输入删除的学生编号：" << endl;
		cin >> answer;

		bool flag = false;

		vector<CStudent>::iterator it;
		for (it = m_stuVec.begin(); it != m_stuVec.end(); it++)
		{
			if (answer == it->getm_num())
			{
				flag = true;
				break;
			}
		
		}

		if (!flag)
		{
			cout << "没有找到对应的学生成绩！！!" << endl;

		}
		else
		{
			m_stuVec.erase(it);
			cout << "学生信息删除完成！" << endl;

		}
		Save(m_stuVec);
		//统一结束语句
		char answerk;
		while (true)
		{
			cout << "是否继续？(y/n)" << endl;
			cin >> answerk;
			if (!(answerk == 'y' || answerk == 'n'))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (answerk == 'y')
		{
			continue;
		}
		else if (answerk == 'n')
		{
			break;
		}
	}
}

void CSystem::Modify()
{
	while (true)
	{
		ShowAll();
		cout << "请输入希望修改的学生的学号：" << endl;
		string num;
		cin >> num;

		vector<CStudent>::iterator it;
		bool flag = false;
		for (it = m_stuVec.begin(); it != m_stuVec.end(); it++)
		{
			if (it->getm_num() == num)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			
			cout << "下面开始修改信息:" << endl;

			string num, name;
			int engls, pys, javas;
			cout << "请输入学生编号:" << endl;
			cin >> num;
			cout << "请输入学生姓名:" << endl;
			cin >> name;
			cout << "请输入学生英语成绩:" << endl;
			cin >> engls;
			cout << "请输入学生python成绩:" << endl;
			cin >> pys;
			cout << "请输入学生java成绩:" << endl;
			cin >> javas;
			CStudent st(num, name, engls, pys, javas);
			
			m_stuVec.erase(it);
			m_stuVec.push_back(st);
			

			Save(m_stuVec);
			cout << "学生信息修改完成！" << endl;


		}
		else
		{
			cout << "没有找到学生信息" << endl;
		}

		char answerk;
		while (true)
		{
			cout << "是否继续？(y/n)" << endl;
			cin >> answerk;
			if (!(answerk == 'y' || answerk == 'n'))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (answerk == 'y')
		{
			continue;
		}
		else if (answerk == 'n')
		{
			break;
		}
	}
}

void CSystem::TotalNum()
{
	cout << "一共有" << m_stuVec.size() << "名学生的信息" << endl;
}

bool cmp00(CStudent c1, CStudent c2)
{
	return c1.getm_iEnglishScore() < c2.getm_iEnglishScore();
}
bool cmp10(CStudent c1, CStudent c2)
{
	return c1.getm_iEnglishScore() > c2.getm_iEnglishScore();
}
bool cmp01(CStudent c1, CStudent c2)
{
	return c1.getm_iPythonScore() < c2.getm_iPythonScore();
}
bool cmp11(CStudent c1, CStudent c2)
{
	return c1.getm_iPythonScore() > c2.getm_iPythonScore();
}
bool cmp02(CStudent c1, CStudent c2)
{
	return c1.getm_iJavaScore() < c2.getm_iJavaScore();
}
bool cmp12(CStudent c1, CStudent c2)
{
	return c1.getm_iJavaScore() > c2.getm_iJavaScore();
}

void CSystem::Sort_info()
{
	while (true)
	{
		int answer, answer2;
		cout << "从小到达排列请输入0，反之请输入1：" << endl;
		cin >> answer;
		while (!(answer==0||answer==1))
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> answer;

		}
		cout << "请选择排序的科目 0英语 1python 2java：" << endl;
		cin >> answer2;
		while (!(answer2==0 || answer2==1 || answer2==2))
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> answer2;

		}
		
		if (answer == 0)
		{
			if (answer2 == 0)
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp00);
			} 
			else if(answer2 == 1)
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp01);

			}
			else
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp02);

			}
		} 
		else
		{
			if (answer2 == 0)
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp10);

			}
			else if (answer2 == 1)
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp11);

			}
			else
			{
				sort(m_stuVec.begin(), m_stuVec.end(), cmp12);

			}
		}
		
		


		Save(m_stuVec);
		cout << "排序结果为：" << endl;
		ShowAll();
		


		char answerk;
		while (true)
		{
			cout << "是否继续？(y/n)" << endl;
			cin >> answerk;
			if (!(answerk == 'y' || answerk == 'n'))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (answerk == 'y')
		{
			continue;
		}
		else if (answerk == 'n')
		{
			break;
		}
	}
}

void CSystem::LetusGo()
{
	cout << "欢迎使用学生管理系统！！" << endl;
	ReadFile();

	while (true)
	{
		
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
}
