#include "agent_manager.h"
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

int main() {
	agent_manager a_manager(1);
	attribute age("age", 1);
	attribute gender("gender", 3);
	attribute race("race", 2);
	vector<attribute> attrs = { age, gender, race };
	a_manager.create_agent_type("human", attrs);
	concurrent_vector<vector<string>> ent;
	/*
	parallel_for(int(0), 50000, [&](int i) {
		string age_ = to_string((rand() % 100));
		string gender_ = genders[rand() % 2];
		string race_ = races[rand() % 3];
		vector<string> entries = {age_,gender_,race_ };
		ent.push_back(entries);
	});
	for (int i = 0; i < ent.size(); i++) {
		a_manager.create_agent("human", ent[i]);
	}
	ent.clear();
	*/
	
	for (int i = 0; i < 50000; i++) {
		string age_ = to_string((rand() % 100));
		string gender_ = genders[rand() % 2];
		string race_ = races[rand() % 3];
		vector<string> entries = {age_,gender_,race_ };
		a_manager.create_agent("human", entries);
	}


	a_manager.print_table_type("human");

	return 0;




}