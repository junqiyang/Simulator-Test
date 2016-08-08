#pragma once
#ifndef ID_TABLE_H
#define ID_TABLE_H

#include <iostream>
#include <vector>
using namespace std;

typedef struct ID_table_entry {
	int A_ID;
	int T_ID;

	ID_table_entry(int id) {
		T_ID = id;
		A_ID = NULL;
	}
} ID_table_entry;

class ID_table{
	public:
		vector<ID_table_entry*> table;
		ID_table();
		int generate_ID(int t_ID);//generate a unique ID, t_ID is for creating a complete ID_table_entry.
		void remove_ID(int a_ID);//remove a ID record from the master table.
		void remove_table(int t_ID);//remove a table, by delete entries has this table's ID
};

#endif