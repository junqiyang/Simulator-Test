#include "ID_table.h"

ID_table::ID_table(){
	table = new list<ID_table_entry>;
}

int ID_table::generate_ID(int t_ID){
	ID_table_entry new_entry = new ID_table_entry();
	new_entry.T_ID = t_ID;
	if(table.empty()){
		new_entry.A_ID = 0;
		table.push_back(new_entry);
	}
	for(int i = 0; i<table.size();i++){
		if(table[i] ==  NULL){
			new_entry.A_ID = i;
			table.push_back(new_entry);
			return i;
		}
	}	
	new_entry.A_ID = table.size();
	table.push_back(new_entry);
	return new_entry.A_ID;		
}
	
void remove_ID(int a_ID){
	if(a_ID > table.size()){
		cout<<"no such ID";
		return;
	}
	table[a_ID] = NULL;	
}