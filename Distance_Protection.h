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
	Distance_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I);//不允许默认构造函数
	int DPCoreAlgorithmOne_Ⅰ(double FaultStyle);//距离继电器动作特性一  Ⅰ段
	int DPCoreAlgorithmOne_Ⅱ(double FaultStyle);//距离继电器动作特性一  Ⅱ段
	int DPCoreAlgorithmOne_Ⅲ(double FaultStyle);//距离继电器动作特性一  Ⅲ段
	ActionState DistanceProtection();//距离继电器
	int DPCoreAlgorithmQuad_Ⅰ(double FaultStyle);//距离继电器动作四边形动作特性 Ⅰ段
	int DPCoreAlgorithmQuad_Ⅱ(double FaultStyle);//距离继电器动作四边形动作特性 Ⅱ段
	int DPCoreAlgorithmQuad_Ⅲ(double FaultStyle);//距离继电器动作四边形动作特性 Ⅲ段
private:
	vector<Electric_Voltage> U_m;//距离阻抗继电器上的电压量
	vector<Electric_Current> I_m;//距离阻抗继电器流经的电流量
	pair<Resistance_Impedance,double> Z_m;//距离阻抗继电器的测量阻抗,配以动作的阻抗继电器
};

