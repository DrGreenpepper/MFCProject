#pragma once
#ifndef MFCDATABASE_H
#define MFCDATABASE_H
#include<string>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<Windows.h>
struct dataIdx {
	int num;//唯一序号
	long long tel;//电话号
	double fund;//剩余资金
	int times;//剩余次数
	CString birth;//生日
	CString name;//姓名
	_int64 clock;
};
//修改时间，序号，操作类型，新信息
struct historyUnit {
	int num;//序号
	int opt;//操作类型
	std::string info;//修改的信息
	_int64 clock;
};
class MFCDataBase
{
public:
	MFCDataBase::MFCDataBase() {
	}
	std::vector <int>List;

	SYSTEMTIME sys;
	_int64 GetTime(){
		GetLocalTime(&sys);
		return _int64(sys.wYear) * 100000000 + _int64(sys.wMonth) * 1000000 + _int64(sys.wDay) * 10000 + _int64(sys.wHour) * 100 + _int64(sys.wMinute);
	}
	void SearchTel(_int64 tel) { searchTel(tel); };
	void SearchStr(int stu, CString info) { searchStr(stu, info); }
	void SaveHistory(int num, int opt, CString info) { saveHistory(num,opt,info); };
	void GetHistory(int num) { getHistory(num); };
	void UpdateIdx(int num);
	void init();
	std::vector<dataIdx> idx;//所有人的信息索引
	std::vector<historyUnit>history;//当前读取的人的历史
	std::ifstream fin;//读入idx
	std::ofstream fout;//输出swp
	std::ifstream historyin;
	std::ofstream historyout;//输出历史
	std::ofstream idxout;//idx输出
private:
	void getHistory(int);
	void saveHistory(int num, int opt, CString info);
	//读取当前用户历史更改记录
	void searchTel(_int64);
	void searchStr(int, CString);
	//opt=0 creat
	
};


#endif // !MFCDATABASE_H

