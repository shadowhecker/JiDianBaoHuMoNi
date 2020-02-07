#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class Operation_Case//�����ն˰���һ���豸
{
public:
	Operation_Case();
	int IsBKON();//�жϿ����Ƿ��ں�λ
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
	vector<int> TWJ;//�������࿪��λ��
	int NoAction;//��ѹ�ͽ�ֹ�غϡ���ֹ��բ����ֹ��բ����ֹ��������֤���ز������ı�־λ
	int TJR;//��һ��TJR�ȿ�������Ҳ���Ա����غ�բ��Ҳ��������������������
};

