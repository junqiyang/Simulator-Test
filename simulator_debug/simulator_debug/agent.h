#pragma once
#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>
#include <vector>
#include <boost/any.hpp>
using namespace std;
//define data format
using boost::any_cast;


struct agent{
	int A_ID;
	vector<boost::any> entry;
};
//indiviual agent information set(row of each table)
// A_ID  entry1  entry2  entry3


struct attribute {
	int type;//1 for int, 2 for string, 3 for bool
	string attribute_name;
	attribute(string name, int tp) {
		attribute_name = name;
		type = tp;
	};
	//example: ("gender",3),("name", 2), ("age",1)
	/*
	bool operator==(const string &other) { //overload to compare an attribute with a string, ex. gender == "gender";
		if (attribute_name.compare(other) != 0) {
			return false;
		}
		else
			return true;
	}*/
};


#endif
