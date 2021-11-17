#include "Administer.h"
Administer::Administer(string na, string id, string passw) :name(na), ID(id), password(passw)

{}

void Administer::display()

{

	cout << endl << "******************" << endl;

	cout << endl << "* 姓名:" << name;

	cout << endl << "* 账号:" << ID;

	cout << endl << "******************" << endl;

}// 作者：编程小马达 https ://www.bilibili.com/read/cv6184094/ 出处：bilibili