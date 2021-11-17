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
	cout << "=================================ѧ����Ϣ����ϵͳ==================================" << endl;
	cout << "-------------------------------------���ܲ˵�--------------------------------------" << endl;
	cout << "\t\t\t\t1. ¼��ѧ����Ϣ" << endl;
	cout << "\t\t\t\t2. ����ѧ����Ϣ" << endl;
	cout << "\t\t\t\t3. ɾ��ѧ����Ϣ" << endl;
	cout << "\t\t\t\t4. �޸�ѧ����Ϣ" << endl;
	cout << "\t\t\t\t5. ����" << endl;
	cout << "\t\t\t\t6. ͳ��ѧ��������" << endl;
	cout << "\t\t\t\t7. ��ʾ����ѧ����Ϣ" << endl;
	cout << "\t\t\t\t0. �˳�ϵͳ" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}

void CSystem::Save(vector<CStudent> m_stuVec)
{
	ofstream wfile("stuInfo.txt");
	if (!wfile.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	//д��

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
		cout << "��ȡ�ļ�ʧ��" << endl;
	}

	string num, name;
	int engls, pys, javas;
	while (rfile >> num >> name >> engls >> pys >> javas)//��ȡ�ļ���õķ�����������
	{
		CStudent st(num, name, engls, pys, javas);
		m_stuVec.push_back(st);

	}
	rfile.close();
}

void CSystem::ShowAll()
{
	cout << "ѧ��" << "\t" << "����" << "\t" << "Ӣ��" << "\t" << "python" << "\t" << "java" << endl;
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
		cout << "������ѧ�����:" << endl;
		cin >> num;
		cout << "������ѧ������:" << endl;
		cin >> name;
		cout << "������ѧ��Ӣ��ɼ�:" << endl;
		cin >> engls;
		cout << "������ѧ��python�ɼ�:" << endl;
		cin >> pys;
		cout << "������ѧ��java�ɼ�:" << endl;
		cin >> javas;
		CStudent st(num, name, engls, pys, javas);

		m_stuVec.push_back(st);

		char answerk;
		while (true)
		{
			cout << "�Ƿ������(y/n)" << endl;
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
		cout << "���������ѧ����ѧ�ţ�" << endl;
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
			cout << "�ҵ�ѧ����Ϣ" << endl;
			cout << "ѧ��" << "\t" << "����" << "\t" << "Ӣ��" << "\t" << "python" << "\t" << "java" << endl;
			cout << it->getm_num() << "\t" << it->getm_name() << "\t" << it->getm_iEnglishScore()
				<< "\t" << it->getm_iPythonScore() << "\t" << it->getm_iJavaScore() << endl;
		} 
		else
		{
			cout << "û���ҵ�ѧ����Ϣ" << endl;
		}

		char answerk;
		while (true)
		{
			cout << "�Ƿ������(y/n)" << endl;
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
		cout << "������ɾ����ѧ����ţ�" << endl;
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
			cout << "û���ҵ���Ӧ��ѧ���ɼ�����!" << endl;

		}
		else
		{
			m_stuVec.erase(it);
			cout << "ѧ����Ϣɾ����ɣ�" << endl;

		}
		Save(m_stuVec);
		//ͳһ�������
		char answerk;
		while (true)
		{
			cout << "�Ƿ������(y/n)" << endl;
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
		cout << "������ϣ���޸ĵ�ѧ����ѧ�ţ�" << endl;
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
			
			cout << "���濪ʼ�޸���Ϣ:" << endl;

			string num, name;
			int engls, pys, javas;
			cout << "������ѧ�����:" << endl;
			cin >> num;
			cout << "������ѧ������:" << endl;
			cin >> name;
			cout << "������ѧ��Ӣ��ɼ�:" << endl;
			cin >> engls;
			cout << "������ѧ��python�ɼ�:" << endl;
			cin >> pys;
			cout << "������ѧ��java�ɼ�:" << endl;
			cin >> javas;
			CStudent st(num, name, engls, pys, javas);
			
			m_stuVec.erase(it);
			m_stuVec.push_back(st);
			

			Save(m_stuVec);
			cout << "ѧ����Ϣ�޸���ɣ�" << endl;


		}
		else
		{
			cout << "û���ҵ�ѧ����Ϣ" << endl;
		}

		char answerk;
		while (true)
		{
			cout << "�Ƿ������(y/n)" << endl;
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
	cout << "һ����" << m_stuVec.size() << "��ѧ������Ϣ" << endl;
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
		cout << "��С��������������0����֮������1��" << endl;
		cin >> answer;
		while (!(answer==0||answer==1))
		{
			cout << "�����������������" << endl;
			cin >> answer;

		}
		cout << "��ѡ������Ŀ�Ŀ 0Ӣ�� 1python 2java��" << endl;
		cin >> answer2;
		while (!(answer2==0 || answer2==1 || answer2==2))
		{
			cout << "�����������������" << endl;
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
		cout << "������Ϊ��" << endl;
		ShowAll();
		


		char answerk;
		while (true)
		{
			cout << "�Ƿ������(y/n)" << endl;
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
	cout << "��ӭʹ��ѧ������ϵͳ����" << endl;
	ReadFile();

	while (true)
	{
		
		ShowUI();
		
		int answer;
		cout << "�����빦�ܶ�Ӧ�ı�ţ�" << endl;
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
			cout << "лл����ʹ�ã��ټ���" << endl;
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
			cout << "�����쳣������������" << endl;
			continue;
		}



	}
}
