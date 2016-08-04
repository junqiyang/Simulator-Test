#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>
using namespace std;
//define data format

typedef string data;

typedef struct attribute{
	int type;//1 for int, 2 for string, 3 for bool
	string attribute_name;
} attribute;
#endif
