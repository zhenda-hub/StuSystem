// 随手测试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main1()
{
    std::cout << "Hello World!\n";
    cout << (int)'?' << endl;
    cout << (char)63 << endl;
	return 0;
}

int main2()
{
	int a = 10;
	cout << (3 | 4) << endl;

	if (!(a ==3||a==4))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;

	}
    return 0;
}

int main3()
{
	vector<int> vtest;
	vtest.push_back(10);
	vtest.push_back(20);
	vtest.push_back(30);
	vtest.push_back(40);
	/*for (vector<int>::iterator it = vtest.begin(); it!=vtest.end(); it++) 判断多个会错误
	{
		if (*it==30)
		{
			it = vtest.erase(it);

		}
	}*/
	for (vector<int>::iterator it = vtest.begin(); it!=vtest.end();)//vector 删除元素的方法
	{
		if (*it == 30||*it == 40)
		{
			it = vtest.erase(it);
		} 
		else
		{
			it++;
		}
	}

	for (vector<int>::iterator it = vtest.begin(); it != vtest.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}

int main()
{
	
	vector<int> ii;
	cout << ii.size() << endl;
	cin.get();
	return 0;
}



