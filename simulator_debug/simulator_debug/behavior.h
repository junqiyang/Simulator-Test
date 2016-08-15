#pragma once
#include"agent_manager.h"
#include<vector>
#include<functional>
using namespace std;

struct behavior {
	int start_time;
	vector<agent*>  (*filter_function)(agent_manager *target);
	void (*logic_function)(agent *target);
};

struct job {
	void (*action)(agent *target);
	agent* target;
};

