#include <iostream>
#include <cstdlib>
#include <string>
#include"student.h"
using namespace std;

//��������
Student::~Student()
{
	delete(St);
}

//����ѧ������Ϣ
void Student::InputStudent(void)
{
	int len;//ѧ��������
	cout << "������ѧ��������:";
	cin >> len;

	system("cls");

	Size = len;

	St = new Student[Size];

	for (int i = 0; i < len; i++)
	{
		cout << "�������" << i + 1 << "��ѧ��������:";
		cin >> St[i].Name;

		cout << "�������" << i + 1 << "��ѧ��������:";
		cin >> St[i].Age;

		cout << "�������" << i + 1 << "��ѧ����ѧ��:";
		cin >> St[i].No;



		system("cls");
	}
}
//���ѧ������Ϣ
void Student::OutputStudent(void)
{
	cout << "����  ����   ѧ��   " << endl;

	for (int i = 0; i < Size; i++)
	{
		cout << St[i].Name << "  " << St[i].Age << "  " << St[i].No << endl;
	}
}

void Student::DeleteStudent(void)//ɾ��ѧ����Ϣ
{
	string str;
	cout << "����������Ҫɾ����ѧ��������:";
	cin >> str;

	int num;//����������ʱ���±�

	//Ѱ���������ʱ���±�
	for (int i = 0; i < Size; i++)
	{
		//���������ʱ
		if (str == St[i].Name)
		{
			num = i;
		}
	}

	//�������ѧ����ǰ��
	for (int j = num + 1; j < Size; j++)
	{
		St[j - 1] = St[j];
	}

	Size -= 1;//ѧ����������һ�� 
}

void Student::SearchStudent(void)//����ѧ����Ϣ
{
	string name;
	cout << "����������Ҫ���ҵ�ѧ��������:";
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

void Student::ChangeStudent(void)//�޸�ѧ����Ϣ
{
	string name;
	cout << "����������Ҫ�޸ĵ�ѧ��������:";
	cin >> name;

	int i;

	for (i = 0; i < Size; i++)
	{
		if (name == St[i].Name)
		{
			break;
		}
	}

	cout << "�޸�ǰѧ������Ϣ:" << endl;
	cout << St[i].Name << " " << St[i].Age << " " << St[i].No << endl << endl;

	cout << "������ѧ��������:";
	cin >> St[i].Name;

	cout << "������ѧ��������:";
	cin >> St[i].Age;

	cout << "������ڸ�ѧ����ѧ��:";
	cin >> St[i].No;


}

void Student::choice()
{
	cout << "*************************��ӭʹ��ѧ���ɼ�����ϵͳ*******************************\n" << endl;


	cout << "�밴���⽫����ѧ������ϵͳ:" << endl;
	getchar();

	system("cls");

	cout << "================================================================================\n\n";
	cout << "------------------------ ��ѡ��Ҫ���������-----------------------------------\n\n";
	cout << "-------------------------- 1 ����ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 2 ���ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 3 ɾ��ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 4 ����ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 5 �޸�ѧ����Ϣ--------------------------------------\n\n";
	cout << "================================================================================\n\n";

	int Item;//��������

	Student st;//ѧ������

	while (1)
	{
		cout << "��ѡ���������: 1���� 2��� 3ɾ�� 4���� 5�޸�\n";
		cin >> Item;
		system("cls");//����  

		switch (Item)
		{
		case 1://����ѧ����Ϣ  
		{
			st.InputStudent();
		}
		break;

		case 2://���ѧ����Ϣ  
		{
			st.OutputStudent();
		}
		break;

		case 3://ɾ��ѧ����Ϣ  
		{
			st.DeleteStudent();
		}
		break;

		case 4://����ѧ����Ϣ  
		{
			st.SearchStudent();
		}
		break;

		case 5://�޸�ѧ����Ϣ  
		{
			st.ChangeStudent();
		}
		break;


		}

		system("pause");
	}
}

