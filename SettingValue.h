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
	int LoadSettingValue(string cate_dir);//导入定值
	void InitializeSettingValue();//初始化定值
	double GetValue(string name, string value);//获取定值
	void DisplayValue(string name);//显示出定值
	int IsEmpty();//判断是否为空
private:
	map<string, map<string, double> > AllSettingValue;
};

