#include "agent_table.h"

agent_table::agent_table() {
	T_ID = NULL;
}

agent_table::agent_table(string type, vector<attribute> attri) {
	T_ID = NULL;
	agent_type = type;
	agent_attribute = attri;
}

agent * agent_table::search_agent(int a_id) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i].A_ID == a_id) {
			return &table[i];
		}
	}
	return NULL;
}

void agent_table::add_agent(agent n_agent) {
	table.push_back(n_agent);
}

void agent_table::delete_entry(int index) {
	for (int i = 0; i < table.size(); i++) {
		if (table[i].A_ID == index) {
			table.erase(table.begin() + i);
		}
	}
}

void agent_table::print_table() {
	cout << "ID   ";
	for (int i = 0; i < agent_attribute.size(); i++) {
		cout << agent_attribute[i].attribute_name << "    ";
	}
	cout << endl;
	for (int i = 0; i < table.size(); i++) {
		cout << table[i].A_ID<< "    ";
		for (int j = 0; j < table[i].entry.size(); j++) {
			cout << any_cast<string>(table[i].entry[j]) << "    ";
		}
		cout << endl;
	}
}