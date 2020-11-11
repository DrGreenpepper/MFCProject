#include "pch.h"
#include "MFCDataBase.h"
#include <fstream>
#include<iostream>
void MFCDataBase::getHistory(int num)
{
	int cnt = num;
	cnt /= 100;
	char str[30] = {".\\data\\0000.hty"};
	for (int i = 10; i >= 7; i--) {
		str[i] = cnt % 10 + '0';
		cnt /= 10;
	}
	historyin.open(str);
	history.clear();
	historyUnit tp;
	while (historyin >> tp.num >> tp.opt >> tp.info>>tp.clock) {
		if(tp.num==num)
			history.push_back(tp);
	}
	historyin.close();
}
void MFCDataBase::saveHistory(int num,int opt,CString info)
{
	int cnt = num;
	cnt /= 100;
	char str[30] = { ".\\data\\0000.hty" };
	for (int i = 10; i >= 7; i--) {
		str[i] = cnt % 10+'0';
		cnt /= 10;
	}
	
	historyout.open(str,std::ios::app);
	std::string tp = CT2A(info);
	historyout << num << " " << opt << " " << tp << " " << GetTime() << std::endl;
	historyout.close();
}


void MFCDataBase::searchTel(_int64 tel)
{
	List.clear();
	_int64 cnt = 1;
	while (cnt < tel)cnt *= 10;
	for (unsigned i = 0; i < idx.size(); i++) {
		if (idx[i].tel%cnt == tel) {
			List.push_back(idx[i].num);
		}
	}
}
void MFCDataBase::searchStr(int stu, CString info)
{
	List.clear();
	std::string str1= CT2A(info);
	if (stu == 2) {
		for (unsigned i = 0; i < idx.size(); i++) {
			std::string str2 = CT2A(idx[i].name);
			if (str1 == str2) {
				List.push_back(idx[i].num);
			}
		}
	}
	else {
		for (unsigned i = 0; i < idx.size(); i++) {
			std::string str2 = CT2A(idx[i].birth);
			if (str1 == str2) {
				List.push_back(idx[i].num);
			}
		}
	}
}
void MFCDataBase::UpdateIdx(int num)
{
	num--;
	std::string tpname, tpbirth;
	tpname = CT2A(idx[num].name); tpbirth = CT2A(idx[num].birth);
	fout <<num+1<<" "<< tpname <<" "<< idx[num].tel << " " << tpbirth <<" "<< idx[num].fund <<" "<< idx[num].times<<" " << idx[num].clock << std::endl;
}
void MFCDataBase::init()
{
	char str[50] = { "idx.idx" };
	fin.open(str);
	idxout.open(str, std::ios::app);
	dataIdx tp;
	std::string tpbirth, tpname;
	while (fin >> tp.num >> tpname >> tp.tel >> tpbirth >> tp.fund >> tp.times>>tp.clock) {
		tp.birth = tpbirth.c_str();
		tp.name = tpname.c_str();
		idx.push_back(tp);
	}
	fin.close();
}
