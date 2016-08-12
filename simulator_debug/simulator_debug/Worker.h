#pragma once
#include "behavior.h"
#include <iostream>
#include <sstream>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/threadpool.hpp>

using namespace std;
using namespace boost::threadpool;

class thread_factory {
	prio_pool factory;
	vector<job> job_queue;

	thread_factory();
	thread_factory(int num);

	void dispatch_job(vector<job> job_queue) 
};