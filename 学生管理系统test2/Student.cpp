#include<iostream>

using namespace std;

struct Stu
{
	char no[10];
	char name[16];
	int math;
	int chi;
	double ave;
};

class Student
{
public:
	Stu st;
	Student* next;
public:
	Student() {}
	Student(Stu s)
	{
		st = s;
		next = NULL;
		st.ave = (st.math + st.chi) / 2.0;
	}
	void setst(Stu s)
	{
		st = s;
		st.ave = (st.math + st.chi) / 2.0;
	}
	Stu getst()
	{
		return st;
	}
	void show()
	{
		cout << "----------------------------" << endl;
		cout << "ѧ��:" << st.no << endl;
		cout << "����:" << st.name << endl;
		cout << "��ѧ�ɼ�:" << st.math << endl;
		cout << "���ĳɼ�:" << st.chi << endl;
		cout << "ƽ���ɼ�:" << st.ave << endl;
		cout << "----------------------------" << endl;
	}
};