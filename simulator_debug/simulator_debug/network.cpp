#include "network.h"

void network::add_relation(int ID, int relation_ID, double weight) {
	edge n_edge(relation_ID, weight);
	networks[ID].push_back(n_edge);
}

vector<edge> network::find_relation_from(int ID) {
	return networks[ID];
}

vector<int> network::find_relation_to(int ID) {
	vector<int> result;
	for (int i = 0; i < networks.size(); i++) {
		for (int j = 0; j < networks[i].size(); i++) {
			if (networks[i][j].relate == ID) {
				result.push_back(i);
				break;
			}
		}
	}
	return result;
}