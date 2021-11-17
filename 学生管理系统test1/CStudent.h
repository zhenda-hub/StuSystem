#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CStudent
{
	string m_num;
	string m_name;
	int m_iEnglishScore;
	int m_iPythonScore;
	int m_iJavaScore;
	
public:
	CStudent(string num="", string name="", int englScore = 0, int PyScore = 0, int JavaScore = 0);
	~CStudent() {};

	string getm_num() { return m_num; };
	string getm_name() { return m_name; };
	int getm_iEnglishScore() { return m_iEnglishScore; };
	int getm_iPythonScore() { return m_iPythonScore; };
	int getm_iJavaScore() { return m_iJavaScore; };
};

