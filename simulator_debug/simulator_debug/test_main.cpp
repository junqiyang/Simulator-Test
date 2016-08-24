#include "agent_manager.h"
#include "behavior_manager.h"
#include "Worker.h"
#include <algorithm>
#include <windows.h>
#include <ppl.h>
#include <iostream>
#include <random>
#include <concurrent_vector.h>
using namespace concurrency;
using namespace std;


string races[3] = { "black", "asian", "white" };
string genders[2] = { "male", "female" };

vector<agent*> find_woman(agent_manager *target){
	agent_table* target_table = target->search_table_type("human");	
	vector<agent*> result;
	for (int i = 0; i < target_table->table.size(); i++) {
		if (any_cast<std::string>(target_table->table[i].entry[1]) == "female") {
			agent * valid = &(target_table->table[i]);
			result.push_back(valid);
		}
	}
	return result;
}

void become_man(agent *target) {
	target->entry[1] = "male";
}


vector<agent*> find_asian(agent_manager *target) {
	agent_table* target_table = target->search_table_type("human");
	vector<agent*> result;
	for (int i = 0; i < target_table->table.size(); i++) {
		if (any_cast<std::string>(target_table->table[i].entry[2]) == "asian") {
			agent * valid = &(target_table->table[i]);
			result.push_back(valid);
		}
	}
	return result;
}

void action(agent *target) {
	target->entry[0] = "100";
}






int main() {
	agent_manager a_manager(1);
	attribute age("age", 1);
	attribute gender("gender", 3);
	attribute race("race", 2);
	vector<attribute> attrs = { age, gender, race };
	a_manager.create_agent_type("human", attrs);

	for (int i = 0; i < 50; i++) {
		int age_ = (rand() % 100);
		string gender_ = genders[rand() % 2];
		string race_ = races[rand() % 3];
		vector<boost::any> entries = {age_,gender_,race_ };
		a_manager.create_agent("human", entries);
	}

	a_manager.print_table_type("human");

	behavior_manager b_manager(1);
	behavior b,c;
	b.filter_function = find_woman;
	b.logic_function = become_man;
	b.start_time = 0;

	c.filter_function = find_asian;
	c.logic_function = action;
	c.start_time = 0;
	
	b_manager.add_behavior(b);
	b_manager.add_behavior(c);
	vector<job> j_list = b_manager.create_job_list(0 , &a_manager);


	vector<agent*> result = find_woman(&a_manager);
	for (int i = 0; i < j_list.size(); i++) {
		become_man(j_list[i].target);
	}

	thread_factory factory(10);
	factory.dispatch_job(j_list);

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	a_manager.print_table_type("human");
	/*
	
	vector<agent*> result = find_woman(&a_manager);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]->A_ID << " ";
		for (int j = 0; j < (result[i]->entry).size(); j++) {
			cout << result[i]->entry[j] << " ";
		}
		cout << endl;
	}*/
	

	return 0;




}
