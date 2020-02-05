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
//                  佛祖保佑                  永无BUG
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
	cout << "本软件遵循GNU v3.0协议，仅供学习使用" << endl;
	cout << "源代码地址：" << "https://github.com/shadowhecker/JiDianBaoHuMoNi" <<"   "<<"有空注册个账号帮我点个赞"<<"谢谢！！"<< endl;

	int opt = -1;
	while (opt != 0)
	{
		cout << "------------------------------------------\n";
		cout << "    0----退出程序                         \n";
		cout << "    1----光纤纵差保护调试(自环)            \n";
		cout << "    2----光纤纵差保护调试(联调)            \n";
		cout << "    3----距离保护调试                     \n";
		cout << "    4----零序电流保护调试                  \n";
		cin >> opt;
		switch (opt)
		{
		case 0:
			cout << "退出程序" << endl;
			break;
		case 1:
		{
			vector<Electric_Voltage> U_m;
			cout << "请输入电压量(以空格分开)：";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "请输入电流量(以空格分开)：";
			InputCurrent(I_m);
			CurrentDiff_Protection CP(U_m, I_m, 1, 1);
			cout << "差动电流：" << CP.GetI_Diff() << "   " << "制动电流" << CP.GetI_B() << endl;
			break;
		}
		case 2:
		{
			vector<Electric_Voltage> U_m;
			cout << "请输入本侧保护电压量(以空格分开)：";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "请输入本侧保护电流量(以空格分开)：";
			InputCurrent(I_m);
			cout << "请输入本侧开关位置状态（1/0）（1：合闸，0：分闸）";
			int breaker_m;
			fflush(stdin);
			cin >> breaker_m;
			CurrentDiff_Protection CP_m(U_m, I_m, 0, breaker_m);
			
			vector<Electric_Voltage> U_n;
			cout << "请输入对侧保护电压量(以空格分开)：";
			InputVoltage(U_n);
			vector<Electric_Current> I_n;
			cout << "请输入对侧保护电流量(以空格分开)：";
			InputCurrent(I_n);
			cout << "请输入对侧开关位置状态（1/0）（1：合闸，0：分闸）";
			int breaker_n;
			fflush(stdin);
			cin >> breaker_n;
			CurrentDiff_Protection CP_n(U_n, I_n, 0, breaker_n);
			cout << "本侧保护：";
			cout << "差动电流：" << CP_m.GetI_Diff() << "   " << "制动电流" << CP_m.GetI_B() << endl;
			cout << "对侧保护：";
			cout << "差动电流：" << CP_n.GetI_Diff() << "   " << "制动电流" << CP_n.GetI_B() << endl;
			break;
		}
		case 3:
		{
			vector<Electric_Voltage> U_m;
			cout << "请输入本侧保护电压量(以空格分开)：";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "请输入本侧保护电流量(以空格分开)：";
			InputCurrent(I_m);
			Distance_Protection DP(U_m, I_m);
			StartTime = clock();
			break;
		}
		case 4:
		{
			vector<Electric_Voltage> U_m;
			cout << "请输入本侧保护电压量(以空格分开)：";
			InputVoltage(U_m);
			vector<Electric_Current> I_m;
			cout << "请输入本侧保护电流量(以空格分开)：";
			InputCurrent(I_m);
			ZeroSeq_Protection ZP(U_m, I_m);
			StartTime = clock();
			break;
		}
		}
	}
	
}