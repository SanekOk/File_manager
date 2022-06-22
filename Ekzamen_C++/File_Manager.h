#pragma once
#include "Interface.h"

class File_Manager: public Interface
{
	string name;
	string Way;
public:
	File_Manager();
	File_Manager(const string &val);
	~File_Manager();
	string getName()const;
	void setName(const string& val);
	string getWay()const;
	void setWay(const string& val);

	void Content()const;
	void Create()const;
	void Delete()const;
	void Rename()const;
	void Copy_File(string val,string next);
	void Size()const;
	bool t_if(string val);
	bool t_compare(string jnior);
	string Search();
};

