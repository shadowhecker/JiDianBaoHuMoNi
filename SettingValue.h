#pragma once
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<sstream>
#include<direct.h>
#include<io.h>
#include<utility>
#include<map>
using namespace std;

class SettingValue
{
public:
	SettingValue() { InitializeSettingValue(); }
	int LoadSettingValue(string cate_dir);//���붨ֵ
	void InitializeSettingValue();//��ʼ����ֵ
	double GetValue(string name, string value);//��ȡ��ֵ
	void DisplayValue(string name);//��ʾ����ֵ
	int IsEmpty();//�ж��Ƿ�Ϊ��
private:
	map<string, map<string, double> > AllSettingValue;
};

