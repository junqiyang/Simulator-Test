#include "agent_manager.h"
using namespace std;

void agent_manager::create_agent_type(string type_name, vector<attribute> a_attri) {
	//first we create a new table for the new type of agent
	agent_table* new_agent = new agent_table(type_name, a_attri);
	//then we assign a new id for agent table
	for (int i = 0; i<table_list.size(); i++) {
		if (table_list[i] == NULL) {
			table_list[i] = new_agent;
			new_agent->set_ID(i);
			return;
		}
	}
	new_agent->set_ID(table_list.size());
	table_list.push_back(new_agent);
}

void agent_manager::delete_agent_type(string type_name) {
	int tp_ID;
	//first we let the table_list entry pointer to nothing
	for (int i = 0; i<table_list.size(); i++) {
		if (table_list[i]->get_type() == type_name) {
			tp_ID = table_list[i]->get_ID;
			table_list[i] = NULL;
		}
	}
	//for every agent in the ID table we delete them
	for (int i = 0; i<master_table.table.size(); i++) {
		if (master_table.table[i]->T_ID == tp_ID) {
			master_table.table[i] = NULL;
		}
	}
	//need error checking	
}

agent_table* agent_manager::search_table_type(string a_type) {
	for (int i = 0; i<table_list.size(); i++) {
		if (table_list[i]->get_type == a_type) {
			return table_list[i];
		}
	}
}

agent_table* agent_manager::search_table_ID(int t_id) {
	for (int i = 0; i<table_list.size(); i++) {
		if (table_list[i]->get_ID == t_id) {
			return table_list[i];
		}
	}
}


agent* agent_manager::search_agent_ID(int a_ID) {
	int tp_ID;
	for (int i = 0; i<master_table.table.size(); i++) {
		if (master_table.table[i]->A_ID == a_ID) {
			tp_ID = master_table.table[i]->T_ID;
			break;
		}
	}
	agent_table *tp_Table = search_table_ID(tp_ID);
	return tp_Table->search_agent(a_ID);
}

void agent_manager::create_agent(string a_type, vector<info> n_entry) {
	agent_table *tp_Table = search_table_type(a_type);
	int tp_ID = tp_Table->get_ID;
	int a_ID = master_table.generate_ID(tp_ID);
	agent n_agent;
	n_agent.A_ID = a_ID;
	n_agent.entry = n_entry;
	tp_Table->add_agent(n_agent);
}

void agent_manager::delete_agent(int ID) {
	agent * target = search_agent_ID(ID);
	target = NULL;
}
