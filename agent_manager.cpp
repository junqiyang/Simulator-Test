#include "agent_manager.h"
using namespace std;

void agent_manager::create_agent_type(string type_name, list<attribute> a_attri){
	agent_table new_agent = new agent_table(type_name, a_attri);
	for(int i=0; i<table_list->size();i++){
		if(table_list[i] == NULL){
			table_list[i] = new_agent;
			new_agent.T_ID = i;
			return;
		}
	}
	new_agent.T_ID = table_list.size();
	table_list.push_back(new_agent);	
}

void delete_agent_type(string type_name);
	void create_agent();
	void delete_agent();