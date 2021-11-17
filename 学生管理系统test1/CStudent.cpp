#include "CStudent.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

CStudent::CStudent(string num, string name, int englScore, int PyScore, int JavaScore):
	m_num(num), m_name(name), m_iEnglishScore(englScore), m_iPythonScore(PyScore), m_iJavaScore(JavaScore)
{};
