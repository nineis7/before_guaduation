#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "ordo_clock.h"
#include <time.h>
#include <sys/time.h>


float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

//线程函数
void *test(void *ptr)
{
    for(int i=0; i < 100000; ++i){
        struct timeval start;
        gettimeofday(&start, NULL);

    }
}


int main(void)
{
	struct timeval start;
    gettimeofday(&start, NULL);
    for(int i=0; i < 16000; ++i){
        pthread_t pId;
    	int ret;
    	//创建子线程，线程id为pId
    	ret = pthread_create(&pId,NULL,test,NULL);
	
    	if(ret != 0)
    	{
    		printf("create pthread error!\n");
    		exit(1);
    	}
//	    pthread_join(pId,NULL);
    }
	printf("main thread will exit when pthread is over\n");
	//等待线程pId的完成
	printf("main thread  exit\n");
    struct timeval end;
    gettimeofday(&end, NULL);
    printf("time spent: %0.8f sec\n", time_diff(&start, &end));


	return 0;

}

