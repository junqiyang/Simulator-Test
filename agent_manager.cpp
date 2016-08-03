#include "agent_manager.h"
using namespace std;

void agent_manager::create_agent_type(string type_name, list<attribute> a_attri){
	agent_table new_agent = new agent_table(type_name, a_attri);
	for(int i=0; i<table_list.size();i++){
		if(table_list[i] == NULL){
			table_list[i] = new_agent;
			new_agent.T_ID = i;
			return;
		}
	}
	new_agent.T_ID = table_list.size();
	table_list.push_back(new_agent);	
}

void agent_manager::delete_agent_type(string type_name){
	int tp_ID;
	for(int i=0; i<table_list.size();i++){
		if(table_list[i].agent_type == type_name){
			tp_ID = table_list[i].T_ID; 
			table_list[i] = NULL;
		}
	}
	for(int i=0; i<master_table.size();i++){
		if(master_table[i].T_ID == tp_id){
			master_table[i] = NULL;
		}
	}		
	//need error checking	
}

void agent_manger::create_agent(string a_type,std::list<data> n_entry){
	for(int i=0; i<table_list.size();i++){
		if(table_list[i].agent_type == type_name){
			tp_ID = table_list[i].T_ID;
			break;
		}
	}
	int a_ID = generate_ID(tp_ID);
	agent_table_entry new_entry = new agent_table_entry;
	new_entry.A_ID = a_ID;
	new_entry.entry = n_entry;				
}


void agent_manager::delete_agent(int ID){
	
	
}

