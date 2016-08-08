#pragma once
#include "dispatcher.h"

class behavior_manager {
	int ID;
	vector<behavior> behavior_table;
public:
	behavior_manager();
	behavior_manager(int id);
	
	vector<behavior> create_start_list(int Timer);
	

};