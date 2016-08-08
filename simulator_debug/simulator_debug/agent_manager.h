#pragma once
#include "agent_table.h"
#include "ID_table.h"

using namespace std;

class agent_manager {
public:
	int id;
	vector<agent_table*> table_list;
	ID_table master_table;

	agent_manager(int id) :id(id) {};
	void create_agent_type(string type_name, vector<attribute> a_attri);
	void delete_agent_type(string type_name);

	agent_table* search_table_type(string a_type);
	agent_table* search_table_ID(int t_id);
	agent* search_agent_ID(int A_ID);
	//agent* search_agent_attribute();

	void create_agent(string a_type, vector<string> n_entry);//->ID_table: generate_ID
	void delete_agent(int A_ID); 
	//keep simple for now, we will need more DB functions in the future.

	void print_table_id(int t_id);
	void print_table_type(string t_tp);
};