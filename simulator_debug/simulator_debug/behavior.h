#pragma once
#include"agent.h"
#include<vector>
#include<functional>
using namespace std;

struct behavior {
	int start_time;
	std::function<vector<agent>()>  (*filter_function);
	void * logic_function;

	void set_filter(std::function<vector<agent>()> call_back){
		filter_function = &call_back;
	}
};
