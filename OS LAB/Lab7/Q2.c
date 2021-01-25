#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 4

void* registrations(void *threadid)
{

        printf("Volunteer %ld is Handling On Day Registrations\n",(long)threadid);
}

void* announcements(void *threadid)
{

        printf("Volunteer %ld is Handling Announcements\n",(long)threadid);
}

void* sponsors(void *threadid)
{

        printf("Volunteer %ld is Handling Sponsors\n",(long)threadid);
}

void* queries(void *threadid)
{

        printf("Volunteer %ld is Handling Queries\n",(long)threadid);
}


int main()
{
    pthread_t threads[100];
    int rc,i=1;
    long t;
    for (t=1; t <= 100;t++)
    {
        // printf("\nChoose For Volunteer %ld\n1-Registrations 2-Announcements 3-Sponsors 4-Queries:  ",t);
        // scanf("%d",&i);

        if (i==1)
        {
            rc = pthread_create(&threads[t], 0, registrations, (void *)t);
            // pthread_join(threads[t], 0);        
        }
        else if (i==2)
        {
            rc = pthread_create(&threads[t], 0, announcements, (void *)t);
            // pthread_join(threads[t], 0);        
        }
        else if (i==3)
        {
            rc = pthread_create(&threads[t], 0, sponsors, (void *)t);
            // pthread_join(threads[t], 0);        
        }
        else if (i==4)
        {
            rc = pthread_create(&threads[t], 0, queries, (void *)t);
            // pthread_join(threads[t], 0);        
        }
        i++;
        if (i==5){i=1;}
    }

    for (t=1;t<=10;t++)
    {
        pthread_join(threads[t], 0);
    }
    return 0;
}