#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 4
void* message(void *threadid)
{
    long i;
    for (i=1;i<=10;i++)
    {
        printf("%ld * %ld = %ld\n",(long)threadid,i,(long)threadid*i);
    }
    // printf("\n\n");
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc,i;
    long t;
    for (t=5,i=0; t < 5 + NUM_THREADS; i++,t++)
    {
        printf("IN:main creating thread %ld\n", t);
        rc = pthread_create(&threads[i], 0, message, (void *)t);
        // sleep(1);
    }
    pthread_join(threads[0], 0);
    pthread_join(threads[1], 0);
    pthread_join(threads[2], 0);
    pthread_join(threads[3], 0);
    return 0;
}