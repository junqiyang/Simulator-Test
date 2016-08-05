#ifndef AGENT_H
#define AGENT_H

#include<iostream>
#include <string>
using namespace std;
//define data format

typedef string data;

void compare_int(data d1, data d2){
	return (atoi(d1.c_str())>atoi(d2.c_str()));	
}

void compare_string(data d1, data d2){
	return 	d1>d2;
}


typedef struct attribute{
	int type;//1 for int, 2 for string, 3 for bool
	string attribute_name;
} attribute;
#endif
