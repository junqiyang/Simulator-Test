#pragma once
#include "behavior.h"


class behavior_manager {
private:
	int ID;
	vector<behavior> behavior_table;
public:
	behavior_manager();
	behavior_manager(int id);
	
	void add_behavior(behavior n_behav);
	vector<behavior> create_active_list(int Timer);
	vector<job> create_job_list(int Timer, agent_manager *target);
	//vector<agent*> behavior_manager::create_job_list(int Timer, agent_manager *target);
};