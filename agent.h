#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>
using namespace std;
//define data format
typedef struct attribute{
	int type;
	string attribute_name;
} attribute;

typedef struct data{
	int type;
	string info;
} data;

#endif
