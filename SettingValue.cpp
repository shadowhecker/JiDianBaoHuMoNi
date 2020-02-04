#include "SettingValue.h"

int SettingValue::LoadSettingValue(string cate_dir)
{
	string filename;
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(cate_dir.c_str(), &file)) == -1)
	{
		cout << cate_dir << " not found!!!" << endl;
		return 0;
	}
	else
	{
		while (_findnext(lf, &file) == 0)
		{
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			map<string, double> DeviceSettingValue;
			char current_address[100];
			memset(current_address, 0, 100);
			_getcwd(current_address, 100);
			cout << current_address << endl;
			strcat_s(current_address, "\\定值\\");
			string Path = current_address;
			Path += file.name;
			ifstream fin(Path, ios::in);
			char line[1024] = {0};
			string text = "";
			string value_s = "";
			double value;
			while (fin.getline(line, sizeof(line)))
			{
				stringstream word(line);
				word >> text;
				word >> value_s;
				value = atof(value_s.c_str());
				DeviceSettingValue.insert(make_pair(text, value));
			}
			AllSettingValue.insert(make_pair(file.name, DeviceSettingValue));
		}
	}
	cout << "定值初始化成功" << endl;
	_findclose(lf);
	return 1;
}

void SettingValue::InitializeSettingValue()
{
	char current_address[100];
	memset(current_address, 0, 100);
	_getcwd(current_address, 100);
	cout << current_address << endl;
	strcat_s(current_address, "\\定值\\*");
	LoadSettingValue(current_address);
}

double SettingValue::GetValue(string name, string value)
{
	return AllSettingValue[name][value];
}

void SettingValue::DisplayValue(string name)
{
	for (auto i = AllSettingValue[name].begin(); i != AllSettingValue[name].end(); ++i)
		cout << (*i).first << "   " << (*i).second << endl;
}

int SettingValue::IsEmpty()
{
	if (AllSettingValue.empty())
		return 0;
	else
		return 1;
}

