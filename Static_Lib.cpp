#include"Static_Lib.h"

using namespace std;

double GetDataFromAngle(double InputData)//输入一个角度获得数值(例如该数值用为PI/2，而不是90)
{
	// TODO: 在此处添加实现代码.
	return InputData / 180 * M_PI;
}


double GetAngleFromData(double InputData)//输入一个角度获得数值(例如该数值用为PI/2，而不是90)
{
	// TODO: 在此处添加实现代码.
	return InputData * 180 / M_PI;
}

void FiltComplex(complex<double>& Data)
{
	if (abs(Data.real()) < 0.00001)
		Data.real(0);
	if (abs(Data.imag()) < 0.00001)
		Data.imag(0);
}
