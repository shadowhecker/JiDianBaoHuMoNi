#include"Static_Lib.h"

using namespace std;

double GetDataFromAngle(double InputData)//����һ���ǶȻ����ֵ(�������ֵ��ΪPI/2��������90)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return InputData / 180 * M_PI;
}


double GetAngleFromData(double InputData)//����һ���ǶȻ����ֵ(�������ֵ��ΪPI/2��������90)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return InputData * 180 / M_PI;
}

void FiltComplex(complex<double>& Data)
{
	if (abs(Data.real()) < 0.00001)
		Data.real(0);
	if (abs(Data.imag()) < 0.00001)
		Data.imag(0);
}
