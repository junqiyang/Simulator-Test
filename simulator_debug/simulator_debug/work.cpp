#include "Worker.h"


thread_factory::thread_factory() {
	factory = prio_pool(5);
}
thread_factory::thread_factory(int num) {
	factory = prio_pool(num);
}

void thread_factory::dispatch_job(vector<job> job_queue)
{
	for (int i = 0; i < job_queue.size(); i++) {
		schedule(factory, prio_task_func(1, boost::bind(job_queue[i].action, job_queue[i].target)));
	}
	factory.wait();
}