#pragma once
#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>

//define data format

typedef std::string info;

typedef struct agent{
	int A_ID;
	vector<info> entry;
} agent;
//indiviual agent information set(row of each table)

bool compare_int(info &d1, info &d2) {
	return (atoi(d1.c_str())>atoi(d2.c_str()));
}

bool compare_string(info &d1, info &d2) {
	return 	d1>d2;
}

typedef struct attribute {
	int type;//1 for int, 2 for string, 3 for bool
	std::string attribute_name;
} attribute;
#endif
