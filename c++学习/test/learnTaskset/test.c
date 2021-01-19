#include <stdio.h>
#include <pthread.h>
#include <sched.h>

unsigned long g_a = 0;
unsigned long g_b = 0;

void* thread_routine(void* arg) {
    while(1) {
        (*((unsigned long*)arg))++;
    }
};

void test_cpu_ability() {
    pthread_t thread_a;
    pthread_create(&thread_a, NULL, thread_routine, &g_a);
    pthread_detach(thread_a);

    pthread_t thread_b;
    pthread_create(&thread_b, NULL, thread_routine, &g_b);
    pthread_detach(thread_b);

    sleep(3);
    printf("a:%lu\tb:%lu\n", g_a, g_b);
};