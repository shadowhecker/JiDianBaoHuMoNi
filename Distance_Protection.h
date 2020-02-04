#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class Distance_Protection
{
public:
	Distance_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I);//������Ĭ�Ϲ��캯��
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	ActionState DistanceProtection();//����̵���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
private:
	vector<Electric_Voltage> U_m;//�����迹�̵����ϵĵ�ѹ��
	vector<Electric_Current> I_m;//�����迹�̵��������ĵ�����
	pair<Resistance_Impedance,double> Z_m;//�����迹�̵����Ĳ����迹,���Զ������迹�̵���
};

