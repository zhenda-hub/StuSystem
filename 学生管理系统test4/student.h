#pragma once
#include <cstdlib>
#include <string>
using namespace std;
class Student//ѧ����
{
public:
	~Student();//��������
	void InputStudent(void);//����ѧ����Ϣ
	void OutputStudent(void);//���ѧ����Ϣ
	void DeleteStudent(void);//ɾ��ѧ����Ϣ
	void SearchStudent(void);//����ѧ����Ϣ
	void ChangeStudent(void);//�޸�ѧ����Ϣ
	void choice(void);//ѡ��

private:
	Student* St;     //ѧ����ָ��
	int Size;       //ѧ��������    
	string Name;    //����
	int Age;        //����
	int No;         //ѧ��

};
//��������������������������������
//��Ȩ����������ΪCSDN������armor_1_blue����ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/weixin_51105360/article/details/112908385