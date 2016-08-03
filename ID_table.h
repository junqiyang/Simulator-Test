#include <iostream>
using namespace std;

typedef struct ID_table_entry{
	int A_ID;
	int T_ID;	
} ID_table_entry;

class ID_table{
	std::list<ID_table_entry> table;
	
	ID_table();
	
	int generate_ID(int t_ID);
	void remove_ID(int a_ID);
};