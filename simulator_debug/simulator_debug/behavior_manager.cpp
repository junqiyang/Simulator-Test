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

vector<behavior> behavior_manager::create_job_list(int Timer) {
	if (!behavior_table.empty()) {
		vector<behavior> active_list;
		for (int i = 0; i < behavior_table.size(); i++) {
			if (behavior_table[i].start_time == Timer) {
				active_list.push_back(behavior_table[i]);
			}
		}
	}
	else return;
}

