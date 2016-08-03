#include "agent_table.h"

void create_agent_type(string a_type, list<attribute> a_attri){
	agent_table new_agent = new agent_table();
	new_agent.agent_type = a_type;
	new_agent.agent_attribute = a_attri;
	new_agent.table = NULL;
	for(int i=0; i<table_list->size();i++){
		if(table_list[i] == NULL){
			table_list[i] = new_agent;
			new_agent.T_ID = i;
			return;
		}
	}
	table_list.push_back(new_agent);
	new_agent.T_ID = table_list->size();	
}

void delete_agent_type(int index, list<agent_table> * table_list, list<ID_table_entry> * ID_table){
	table_list[index] == NULL;
	for(int i=0; i<ID_table->size();i++){
		if(ID_table[i]->T_ID == index){
			ID_table[i] = NULL;
		}
	}
	return;
}

void create_agent(string a_type, list<agent_table> * table_list, list<ID_table_entry> * ID_table, std::list<data> n_entry){
	bool ID_assigned = false;
	ID_table_entry new_ID_entry = new ID_table_entry;
	int Ag_ID;
	
	for(int i=0; i<ID_table->size();i++){
		if(ID_table[i] == NULL){
			Ag_ID = i;
			ID_assigned = true;
			break;
		}		
	}
	if(ID_assigned == false){
		Ag_ID = ID_table->size();
		ID_table->push_back(NULL);
	}
	new_ID_entry.A_ID = Ag_ID;
	
	for(int i=0; i<table_list->size();i++){
		if(table_list[i]->agent_type == a_type){
			new_ID_entry = table_list[i]->T_ID;
		}
	}
	
	ID_table[Ag_ID] = new_ID_entry;
	
	agent_table_entry new_ag = new new_ag;
	new_ag.A_ID = Ag_ID;
	new_ag.entry = n_entry;

	return;
}

