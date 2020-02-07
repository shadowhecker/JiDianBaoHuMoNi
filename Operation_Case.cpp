#include "Operation_Case.h"

Operation_Case::Operation_Case()
{
	TWJ.push_back(1);
	TWJ.push_back(1);
	TWJ.push_back(1);
	//默认开关初始位置在合位
	NoAction = 0;//默认开关正常可以动作
	TJR = 0;
}

int Operation_Case::IsBKON()
{
	for (auto i = TWJ.begin(); i != TWJ.end(); ++i)
		if (*i == 0)
			return 0;
	return 1;
}

int Operation_Case::IsBKAON()
{
	return TWJ[0];
}

int Operation_Case::IsBKBON()
{
	return TWJ[1];
}

int Operation_Case::IsBKCON()
{
	return TWJ[2];
}

void Operation_Case::OffBKA()
{
	TWJ[0] = 0;
}

void Operation_Case::OffBKB()
{
	TWJ[1] = 0;
}

void Operation_Case::OffBKC()
{
	TWJ[2] = 0;
}

void Operation_Case::OnBKA()
{
	TWJ[0] = 1;
}

void Operation_Case::OnBKB()
{
	TWJ[1] = 1;
}

void Operation_Case::OnBKC()
{
	TWJ[2] = 1;
}

void Operation_Case::OffBKABC()
{
	TWJ[0] = 0;
	TWJ[1] = 0;
	TWJ[2] = 0;
}

Operation_Case& Operation_Case::operator=(const Operation_Case& Input)
{
	TWJ = Input.TWJ;
	NoAction = Input.NoAction;
	TJR = Input.TJR;
	return *this;
	// TODO: 在此处插入 return 语句
}
