#pragma once
#include "CStudent.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CSystem
{
	vector<CStudent>m_stuVec;
public:
	void ShowUI();
	void Save(vector<CStudent> m_stuVec);
	void ReadFile();
	void ShowAll();
	void Insert();
	void Search();
	void TotalNum();
	void Delete_info();
	void Modify();
	void Sort_info();
	void LetusGo();



};

