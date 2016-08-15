#pragma once
#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>
#include <vector>
using namespace std;
//define data format



struct agent{
	int A_ID;
	vector<std::string> entry;
};
//indiviual agent information set(row of each table)

/*bool compare_int(std::string &d1, std::string &d2) {
	return (atoi(d1.c_str())>atoi(d2.c_str()));
}

bool compare_string(std::string &d1, std::string &d2) {
	return 	d1>d2;
}
*/
struct attribute {
	int type;//1 for int, 2 for string, 3 for bool
	std::string attribute_name;
	attribute(std::string name, int tp) {
		attribute_name = name;
		type = tp;
	};

	bool operator==(const string &other) {
		if (attribute_name.compare(other) != 0) {
			return false;
		}
		else
			return true;
	}
};


#endif
