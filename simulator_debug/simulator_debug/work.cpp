#include "Worker.h"
void thread_factory::dispatch_job(vector<job> job_queue)
{
	for (int i = 0; i < job_queue.size(); i++) {
		schedule(factory, prio_task_func(1, boost::bind(job_queue[i].action, job_queue[i].target)));
	}
	factory.wait();
}