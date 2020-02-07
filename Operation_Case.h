#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class Operation_Case//智能终端包含一次设备
{
public:
	Operation_Case();
	int IsBKON();//判断开关是否在合位
	int IsBKAON();
	int IsBKBON();
	int IsBKCON();
	void OffBKA();
	void OffBKB();
	void OffBKC();
	void OnBKA();
	void OnBKB();
	void OnBKC();
	void OffBKABC();
	Operation_Case& operator=(const Operation_Case& Input);
private:
	vector<int> TWJ;//包含三相开关位置
	int NoAction;//气压低禁止重合、禁止合闸、禁止分闸、禁止操作，保证开关不动作的标志位
	int TJR;//设一个TJR既可以永跳也可以闭锁重合闸，也可以用于其他保护动作
};

