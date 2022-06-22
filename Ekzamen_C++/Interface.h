#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <experimental/filesystem> 
#include <stdio.h>
#include <direct.h>
#include <io.h>
#include <Windows.h>
using namespace std;
using namespace std::experimental::filesystem::v1;
class Interface
{
public:
	~Interface();
	void Munyu();
};

