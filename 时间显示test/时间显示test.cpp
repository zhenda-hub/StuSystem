// 时间显示test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <windows.h>
#include <iostream>
using namespace std;
int main1()
{
    //1
	//时间练习
	SYSTEMTIME st;
	GetLocalTime(&st);
	char tmp[64] = {};
	sprintf_s(tmp, "%4d-%02d-%02d %02d:%02d:%02d ms:%03d",
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	cout << tmp << endl;

	

	return 0;
}

#include <ctime>
int main()
{
	time_t now = time(0);
	cout << "1970年到现在经过的秒数" << now << endl;

	tm ltm;
	localtime_s(&ltm, &now);
	cout << 1900 + ltm.tm_year << "-" << 1 + ltm.tm_mon << "-" << ltm.tm_mday << " " <<
		ltm.tm_hour << ":" << ltm.tm_min << ":" << ltm.tm_sec<< endl;
	return 0;
}