#pragma once
#include <cstdlib>
#include <string>
using namespace std;
class Student//学生类
{
public:
	~Student();//析构函数
	void InputStudent(void);//输入学生信息
	void OutputStudent(void);//输出学生信息
	void DeleteStudent(void);//删除学生信息
	void SearchStudent(void);//查找学生信息
	void ChangeStudent(void);//修改学生信息
	void choice(void);//选项

private:
	Student* St;     //学生类指针
	int Size;       //学生的人数    
	string Name;    //姓名
	int Age;        //年龄
	int No;         //学号

};
//————————————————
//版权声明：本文为CSDN博主「armor_1_blue」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/weixin_51105360/article/details/112908385