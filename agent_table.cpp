#include "agent_table.h"

agent_table::agent_table(string type, list<attribute> attri){
	T_ID = NULL;
	agent_type = type;		
	agent_attribute = attri;
	table = new list<agent_table_entry>;
}

void agent_table::add_entry(agent_table_entry n_entry){
	table.push_back(n_entry);	
}

void agent_table::delete_entry(int index){
	list<int>::iterator it1;
	it1 = table.begin();
	while(it1 != table.end()){
		if(it1.A_ID == index){
			mylist.erase(it1);
			break;
		}
		it1++;
	}
}





