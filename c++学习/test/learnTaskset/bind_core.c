// build script:gcc -lpthread bind_core.c -o bind_core
#include <stdio.h>
#include <pthread.h>
#include <sched.h>

void* thread_routine(void* arg) { 
	int cpu = -1;
	while(1) {
		int cur_cpu = sched_getcpu();
		if (cur_cpu!=cpu) {
			printf("pre:%d, cur:%d", cpu, cur_cpu);
			cpu = cur_cpu;
		}
	}
};

void test_cpu_switch() {
	pthread_t thread;
	pthread_create(&thread, NULL, thread_routine, NULL);
	pthread_detach(thread);
	sleep(100);
}
