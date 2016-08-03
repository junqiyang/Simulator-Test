#include "agent_table.h"
#include "ID_table.h"
using namespace std;

class agent_manager{
	int id;
	std::list<agent_table> table_list;
	ID_table master_table;
	
	agent_manager(int id);
	void create_agent_type(string type_name, list<attribute> a_attri);
	void delete_agent_type();
	void create_agent();
	void delete_agent();	
	
}agent_manager;