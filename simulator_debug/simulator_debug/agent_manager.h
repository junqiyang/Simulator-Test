
#pragma once
#include "agent_table.h"
#include "ID_table.h"
#include "network.h"
#include <vector>
using namespace std;

struct link_type {
	int a_id;
	bool is_from;
};

struct condition {
	int attri_position;
	int data_type;
	string op;
	string value;
};


class agent_manager {
public:
	int id;
	vector<agent_table*> table_list;
	ID_table master_table;
//	network agent_network;


	agent_manager(int id) :id(id) {};
	void create_agent_type(string type_name, vector<attribute> a_attri);
	void delete_agent_type(string type_name);

	agent_table* search_table_type(string a_type);
	agent_table* search_table_ID(int t_id);

	//agent* search_agent_attribute();

	void create_agent(string a_type, vector<boost::any> n_entry);//->ID_table: generate_ID
	void delete_agent(int A_ID); 
	agent* search_agent_ID(int A_ID);
	
	vector<agent*> select_agent(string table_name, vector<string> condition, int rate);
	
	void print_table_id(int t_id);
	void print_table_type(string t_tp);

	vector<agent*> find_links(vector<link_type> target);
	vector<agent*> filt_agent();

};

