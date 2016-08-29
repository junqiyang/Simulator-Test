#pragma once
#ifndef NETWORK_H
#define NETWORK_H
#include "agent.h"

struct edge{
	int relate;
	double weight;
	edge(int target, double w) :relate(target), weight(w) {};
};

class network {
public:
	vector<vector<edge>> networks;
	network() {};
	void add_relation(int ID, int relation_ID, double weight);
	vector<edge> find_relation_from(int target);
	vector<int> find_relation_to(int target);
};

#endif