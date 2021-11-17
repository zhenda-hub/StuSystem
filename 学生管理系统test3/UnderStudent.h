#pragma once
#include<iostream>

#include<string>

using namespace std;

class Understudent

{

private:

	string name;

	string ID;

	string password;

	float grade;

	string sex;

public:

	Understudent() {}

	Understudent(string na, string id, string passw, float gra, string s);

	string get_name() { return name; }

	string get_id() { return ID; }

	string get_password() { return password; }

	float get_grade() { return grade; }

	string get_sex() { return sex; }

	void display();

	bool operator == (const Understudent& u)const //注意此处参数必须为const类型，才能与STL中list的内置函数匹配

	{

		return ID == u.ID;

	}

	void set_password(string passw)

	{

		password = passw;

	}

}; //作者：编程小马达 https ://www.bilibili.com/read/cv6184094/ 出处：bilibili