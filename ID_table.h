#include <iostream>
using namespace std;

typedef struct ID_table_entry{
	int A_ID;
	int T_ID;	
} ID_table_entry;

class ID_table{
	std::list<ID_table_entry> table;	
	
	ID_table();	
	
	int generate_ID(int t_ID);//generate a unique ID, t_ID is for creating a complete ID_table_entry.
	void remove_ID(int a_ID);//remove a ID record from the master table.
	void remove_table(int t_ID);//remove a table, by delete entries has this table's ID
};