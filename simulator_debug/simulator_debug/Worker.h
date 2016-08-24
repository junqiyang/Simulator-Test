#pragma once
//threadpool resource:http://threadpool.sourceforge.net/
//threadpool example:http://threadpool.sourceforge.net/tutorial/intro.html
#include "behavior.h"
#include <iostream>
#include <sstream>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <boost/threadpool.hpp>

using namespace std;
using namespace boost::threadpool;

class thread_factory {
public:
	prio_pool factory;
	vector<job> job_queue;

	thread_factory() ;
	thread_factory(int num);

	void dispatch_job(vector<job> job_queue);
};