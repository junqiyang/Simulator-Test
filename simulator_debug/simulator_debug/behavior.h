#pragma once
#include<vector>
using namespace std;

struct behavior {
	int start_time;
	void * filter_function;
	void * logic_function;
};

