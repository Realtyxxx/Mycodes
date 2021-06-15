#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define BUFF_SIZE 5

int g_buff[BUFF_SIZE];
int g_write_index = 0;
