#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include "ordo_clock.h"
#include <time.h>
#include <sys/time.h>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;
mutex mu;							//互斥锁全局变量
condition_variable cond;           //全局条件变量

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

//线程函数
void *test(void *ptr)
{
    static int count = 24;
    if(count > 0){
        std::unique_lock<std::mutex> locker(mu);
        count--;
    }
    else {
        cond.notify_all();
    }
    struct timeval start;
    for(int i=0; i < 1e-9; ++i){
        //struct timeval start;
        gettimeofday(&start, NULL);
        start.tv_sec++;
    }
    cout << "start.tv_sec is " << start.tv_sec << endl;
}


int main(void)
{
	struct timeval start;
    gettimeofday(&start, NULL);
    for(int i=0; i < 24; ++i){
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

