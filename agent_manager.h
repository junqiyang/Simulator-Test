#include "agent_table.h"
#include "ID_table.h"
using namespace std;

class agent_manager{
	int id;
	std::list<agent_table> table_list;
	ID_table master_table;
	
	agent_manager(int id);
	void create_agent_type(string type_name, list<attribute> a_attri);
	void delete_agent_type(string type_name);
	void create_agent(string a_type,std::list<data> n_entry);
	void delete_agent(int A_ID);	
	
	
	void search_by_ID();//search by agent ID
	void search_by_attribute(int T_ID);//search by attribute in a specific table
}agent_manager;