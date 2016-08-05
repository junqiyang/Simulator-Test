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
		//constructor
		agent_table(string type,list<attribute> attri);
		
		//set	
		void set_ID(int ID){T_ID = ID;}
		void set_type(string type){agent_type = type;}
		void set_attribute(list<attribute> attri){agent_attribute = attri;}
		//get
		int get_ID(){return T_ID;}	
		string get_type(){return agent_type;}
		list<attribute> get_attribute(){return agent_attribute;}
		
		//member functions
		void add_entry(agent_table_entry n_entry);		
		void delete_entry(int index);//delete by A_ID
		//void sort_table(attribute sort_target, bool increase);
} agent_table;
//agent table, different agent have different table.