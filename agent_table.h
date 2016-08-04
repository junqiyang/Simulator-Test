#include "agent.h"
using namespace std;

typedef struct agent_table_entry{
	int A_ID;
	std::list<data> entry;
} agent_table_entry;
//indiviual agent information set(row of each table)

class agent_table{
	private:
		int T_ID;//table ID
		string agent_type;//what agent this table hold
		std::list<attribute> agent_attribute;//define columns
		std::list<agent_table_entry> table;//set of agents(set of rows)
	public:
		agent_table(string type, agent_attribute);
		//utility functions
		int get_ID(){
			return T_ID;
		}
		
		void set_ID(int ID){
			T_ID = ID;
		}
	
		string get_type(){
			return agent_type;
		}
		
		void set_type(string type){
			agent_type = type;
		}
		
		void add_entry(agent_table_entry n_entry);		
		void delete_entry(int index);
		void sort_table(attribute sort_target, bool increase);

} agent_table;
//agent table, different agent have different table.