#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *func(int n);
pthread_t philosopher[5];
pthread_mutex_t chopstick[5];
sem_t sem;

int main()
{
     int i;
     void *msg;
     for(i=0;i<5;i++)
     {
          pthread_mutex_init(&chopstick[i],NULL);
     }
      sem_init(&sem,0,4);
     for(i=0;i<5;i++)
     {
          pthread_create(&philosopher[i],NULL,(void *)func,(int* )(i+1));
     }
     for(i=0;i<5;i++)
     {
          pthread_join(philosopher[i],&msg);
     }
     printf("\n");
     for(i=0;i<5;i++)
      {
          pthread_mutex_destroy(&chopstick[i]);
      }
     sem_destroy(&sem);
     return 0;
}

void *func(int n)
{
     printf ("\nPhilosopher %d is thinking ",n);
     sem_wait(&sem);
     printf("\nPhilosopher %d is in the dining room ", n);
     pthread_mutex_lock(&chopstick[n-1]);
     	sleep(3);
     pthread_mutex_lock(&chopstick[(n)%5]);
     	printf ("\nPhilosopher %d is eating ",n);
     	sleep(2);
     pthread_mutex_unlock(&chopstick[n-1]);
     pthread_mutex_unlock(&chopstick[(n)%5]);
     printf ("\nPhilosopher %d finished eating ",n);
     sem_post(&sem);
}
