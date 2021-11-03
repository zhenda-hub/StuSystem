// 文件读写test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
using namespace std;


int main1()
{
	//system("test3.txt");//直接弹出文件


    ifstream rfile("111.txt");
    if (!rfile)
    {
        cout << "111打开失败" << endl;
    } 

    ofstream wfile("222.txt");
    if (!wfile)
    {
		cout << "222打开失败" << endl;
    } 
    
    //转移数据
	char ch;
    while (!rfile.eof())
    {
		rfile.read(&ch, 1);
        wfile.write(&ch, 1);
    }
    //结束
    rfile.close();
    wfile.close();


    return 0;
}

int main()
{
    ofstream f1("11.txt");
    ifstream f2("11.txt");
    ofstream f3("22.txt");

    if (!f1.is_open())
    {
        cout << "f1NG" << endl;
    }
	if (!f2)
	{
		cout << "f2NG" << endl;
	}
	if (!f3)
	{
		cout << "f3NG" << endl;
	}

    //写入
    char ch[1024] = "wqerqwegfdgdfgdf4134342";
    /*string st1 = "wqerqwegfdgdfgdf4134342";*/
    f1 << ch << endl;



    /*char ch;
    while (!f2.eof())
    {
        f2.read(&ch, 1);
        f3.write(&ch, 1);
    }*/
    //char buf[1024] = {0};
    string st1;
    while (f2>>st1)
    {
		cout << st1 << endl;
		f3 << st1;

    }
    f1.close();
    f2.close();
    f3.close();





    return 0;
}