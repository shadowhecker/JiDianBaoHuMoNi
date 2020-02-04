#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class ZeroSeq_Protection
{
public:
	ZeroSeq_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I) { U_m = U; I_m = I; }
	int ZPCoreAlgorithmQuad_��();//������
	int ZPCoreAlgorithmQuad_��();//������
	ActionState ZeroSeqProtection();//������̵���
private:
	vector<Electric_Voltage> U_m;//�����迹�̵����ϵĵ�ѹ��
	vector<Electric_Current> I_m;//�����迹�̵��������ĵ�����
};

