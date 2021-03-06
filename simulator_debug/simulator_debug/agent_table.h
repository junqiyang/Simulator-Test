#pragma once
#ifndef AGENT_TABLE_H
#define AGENT_TABLE_H
#include "agent.h"
//#include "behavior.h"
#include <vector>
using namespace std;



class agent_table {
private:
	int T_ID;//table ID, if -999 it means it is a temp table
	string agent_type;//what agent this table hold
	vector<attribute> agent_attribute;//define columns
	//vector<behavior*> possibe_actions;
 
public:
	vector<agent> table;//set of agents(set of rows)
	//constructor
	agent_table();
	agent_table(std::string type, vector<attribute> attri);

	//set	
	void set_ID(int ID) { T_ID = ID; }
	void set_type(string type) { agent_type = type; }
	void set_attribute(vector<attribute> attri) { agent_attribute = attri; }
	//get
	int get_ID() { return T_ID; }
	string get_type() { return agent_type; }
	vector<attribute> get_attribute() { return agent_attribute; }

	//member functions
	agent* search_agent(int a_id);
	void add_agent(agent n_agent);
	void delete_entry(int index);//delete by A_ID

	//only for testing purpose
	void print_table();
};
//agent table, different agent have different table.
#endif