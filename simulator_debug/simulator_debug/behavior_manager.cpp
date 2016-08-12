#include "behavior_manager.h"

behavior_manager::behavior_manager() {
	ID = -9999;
}

behavior_manager::behavior_manager(int id) {
	ID = id;
}

void behavior_manager::add_behavior(behavior n_behav) {
	behavior_table.push_back(n_behav);
}

vector<behavior> behavior_manager::create_active_list(int Timer) {
	if (!behavior_table.empty()) {
		vector<behavior> active_list;
		for (int i = 0; i < behavior_table.size(); i++) {
			if (behavior_table[i].start_time == Timer) {
				active_list.push_back(behavior_table[i]);
			}
		}
		return active_list;
	}
	else return;
}

vector<job> behavior_manager::create_job_list(int Timer) {
	vector<behavior> act_list = create_active_list(Timer);
	vector<job> result;
	vector<agent*> tp_agents;
	for (int i = 0; i < act_list.size(); i++) {
		tp_agents = (act_list[i].filter_function());
		for (int j = 0; j < tp_agents.size(); j++) {
			job n_job;
			n_job.target = tp_agents[i];
			n_job.action = act_list[i].logic_function;
			result.push_back(n_job);
		}
	}
	return result;
}

