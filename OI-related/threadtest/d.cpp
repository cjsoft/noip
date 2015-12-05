/*
 * =====================================================================================
 *
 * Filename: pthread.c
 *
 * Description: 
 *
 * Version: 1.0
 * Created: 08/17/11 11:06:35
 * Revision: none
 * Compiler: gcc
 *
 * Author: YOUR NAME (), 
 * Company: 
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <pthread.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_cond_t qready;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

struct foo {
    int cnt;
    pthread_mutex_t f_lock;
};

void cleanup(void *arg)
{
    printf("clean up: %s\n", (char *)arg);
}

void printids(char *str)
{
    printf("%s pid = %u tid = %u / 0x%x\n", 
            str, (unsigned int)getpid(), (unsigned int)pthread_self(), (unsigned int)pthread_self());
}

void *thread1(void *arg)
{
    pthread_mutex_lock(&qlock);
    pthread_cond_wait(&qready, &qlock);
    pthread_mutex_unlock(&qlock);

    printids("thread1:");
    
    pthread_cleanup_push(cleanup, "thread 1 first cleanup handler");
    pthread_cleanup_push(cleanup, "thread 1 second cleanup handler");
    printf("thread 1 push complete!\n");
    
    pthread_mutex_lock(&((struct foo *)arg)->f_lock);
    ((struct foo *)arg)->cnt ;
    printf("thread1: cnt = %d\n", ((struct foo *)arg)->cnt);
    pthread_mutex_unlock(&((struct foo *)arg)->f_lock);

    if (arg) 
        return ((void *)0);
    
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);

    pthread_exit((void *)1);
}

void *thread2(void *arg)
{
    int exit_code = -1;
    printids("thread2:");
    
    printf("Now unlock thread1\n");

    pthread_mutex_lock(&qlock);
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);

    printf("Thread1 unlocked\n");

    pthread_cleanup_push(cleanup, "thread 2 first cleanup handler");
    pthread_cleanup_push(cleanup, "thread 2 second cleanup handler");
    printf("thread 2 push complete!\n");
    
    if (arg) 
        pthread_exit((void *)exit_code);

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    
    pthread_exit((void *)exit_code);
}

int main(int argc, char *argv[])
{
    int ret;
    pthread_t tid1, tid2;
    void *retval;
    struct foo *fp;

    ret = pthread_cond_init(&qready, NULL);
    if (ret != 0) {
        printf("pthread_cond_init error: %s\n", strerror(ret));
        return -1;
    }



    if ((fp = malloc(sizeof(struct foo))) == NULL) {
        printf("malloc failed!\n");
        return -1;
    }

    if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
        free(fp);
        printf("init mutex failed!\n");
    }

    pthread_mutex_lock(&fp->f_lock);

    ret = pthread_create(&tid1, NULL, thread1, (void *)fp);
    if (ret != 0) {
        printf("main thread error: %s\n", strerror(ret));
        return -1;
    }
    ret = pthread_create(&tid2, NULL, thread2, (void *)1);
    if (ret != 0) {
        printf("main thread error: %s\n", strerror(ret));
        return -1;
    }

    
    ret = pthread_join(tid2, &retval);
    if (ret != 0) {
        printf("pthread join falied!\n");
        return -1;
    }
    else
        printf("thread2 exit code %d\n", (int)retval);

    fp->cnt = 1;
    printf("main thread: cnt = %d\n",fp->cnt);

    pthread_mutex_unlock(&fp->f_lock);

    sleep(1);    //there is no guarantee the main thread will run before the newly created thread, so we wait for a while 
    printids("main thread:");

    printf("Press to exit\n");

    ret = pthread_cond_destroy(&qready);
    if (ret != 0) {
        printf("pthread_cond_destroy error: %s\n", strerror(ret));
        return -1;
    }

    getchar();
    return 0;
}