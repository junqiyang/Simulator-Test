#pragma once
#include "behavior.h"

class behavior_manager {
	int ID;
	vector<behavior> behavior_table;
public:
	behavior_manager();
	behavior_manager(int id);
	
	void add_behavior(behavior n_behav);

	vector<behavior> create_start_list(int Timer);

	
};