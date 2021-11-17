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
		cout << "学号:" << st.no << endl;
		cout << "姓名:" << st.name << endl;
		cout << "数学成绩:" << st.math << endl;
		cout << "语文成绩:" << st.chi << endl;
		cout << "平均成绩:" << st.ave << endl;
		cout << "----------------------------" << endl;
	}
};