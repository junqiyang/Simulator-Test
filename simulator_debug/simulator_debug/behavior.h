#pragma once
#include"agent.h"
#include<vector>
#include<functional>
using namespace std;

struct behavior {
	int start_time;
	vector<agent>  (*filter_function)();
	void (*logic_function)();
};

struct job {
	void (*action)();
	agent * target;
};

