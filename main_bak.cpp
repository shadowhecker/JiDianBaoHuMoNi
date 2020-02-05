//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| 8 |||// \
//                     / _||||| -8- |||||- \
//                       | | \\\ 8 /// | |
//                     | \_| ''\-8-/'' | |
//                      \ .-\__ `8` ___/-. /
//                   ___`. .' /--8--\ `. . __
//                ."" '< `.___\_<8>_/___.' >'"".
//               | | : `- \`.;`\ 8 /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  ���汣��                  ����BUG
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Distance_Protection.h"
#include "res.h"
#include "ZeroSeq_Protection.h"
#include "CurrentDiff_Protection.h"

using namespace std;
int main()
{
	cout << "�������ѭGNU v3.0Э�飬����ѧϰʹ��" << endl;
	cout << "Դ�����ַ��" << "https://github.com/shadowhecker/JiDianBaoHuMoNi" <<"   "<<"�п�ע����˺Ű��ҵ����"<<"лл����"<< endl;

	int opt = -1;
	while (opt != 0)
	{
		cout << "------------------------------------------\n";
		cout << "    0----�˳�����                         \n";
		cout << "    1----�����ݲ������(�Ի�)            \n";
		cout << "    2----�����ݲ������(����)            \n";
		cout << "    3----���뱣������                     \n";
		cout << "    4----���������������                  \n";
		cin >> opt;
		switch (opt)
		{
		case 0:
			cout << "�˳�����" << endl;
			break;
		case 1:
		{
			vector<Electric_Voltage> U_m;
			cout << "�������ѹ��(�Կո�ֿ�)��";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "�����������(�Կո�ֿ�)��";
			InputCurrent(I_m);
			CurrentDiff_Protection CP(U_m, I_m, 1, 1);
			cout << "�������" << CP.GetI_Diff() << "   " << "�ƶ�����" << CP.GetI_B() << endl;
			break;
		}
		case 2:
		{
			vector<Electric_Voltage> U_m;
			cout << "�����뱾�ౣ����ѹ��(�Կո�ֿ�)��";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "�����뱾�ౣ��������(�Կո�ֿ�)��";
			InputCurrent(I_m);
			cout << "�����뱾�࿪��λ��״̬��1/0����1����բ��0����բ��";
			int breaker_m;
			fflush(stdin);
			cin >> breaker_m;
			CurrentDiff_Protection CP_m(U_m, I_m, 0, breaker_m);
			
			vector<Electric_Voltage> U_n;
			cout << "������Բౣ����ѹ��(�Կո�ֿ�)��";
			InputVoltage(U_n);
			vector<Electric_Current> I_n;
			cout << "������Բౣ��������(�Կո�ֿ�)��";
			InputCurrent(I_n);
			cout << "������Բ࿪��λ��״̬��1/0����1����բ��0����բ��";
			int breaker_n;
			fflush(stdin);
			cin >> breaker_n;
			CurrentDiff_Protection CP_n(U_n, I_n, 0, breaker_n);
			cout << "���ౣ����";
			cout << "�������" << CP_m.GetI_Diff() << "   " << "�ƶ�����" << CP_m.GetI_B() << endl;
			cout << "�Բౣ����";
			cout << "�������" << CP_n.GetI_Diff() << "   " << "�ƶ�����" << CP_n.GetI_B() << endl;
			break;
		}
		case 3:
		{
			vector<Electric_Voltage> U_m;
			cout << "�����뱾�ౣ����ѹ��(�Կո�ֿ�)��";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "�����뱾�ౣ��������(�Կո�ֿ�)��";
			InputCurrent(I_m);
			Distance_Protection DP(U_m, I_m);
			StartTime = clock();
			break;
		}
		case 4:
		{
			vector<Electric_Voltage> U_m;
			cout << "�����뱾�ౣ����ѹ��(�Կո�ֿ�)��";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "�����뱾�ౣ��������(�Կո�ֿ�)��";
			InputCurrent(I_m);
			ZeroSeq_Protection ZP(U_m, I_m);
			StartTime = clock();
			break;
		}
		}
	}
	
}