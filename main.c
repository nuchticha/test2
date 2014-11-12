#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_a;

void* testRoutine(void* p)
{
  int v;int w;
  v = (*(int*)p)*100; 
  int i;
  sem_getvalue(&sem_a,&w);
  w = w*100;
  for(i=0;i<=w;i++){
    printf("inside testRoutine %d %d %d\n",v++,i,w);  
  }
  int* ptr;
  pthread_exit(&ptr);
}

int main()
{
  int i,j;
  int r;
  
  r = sem_init(&sem_a,0,0);
  printf("r = %d\n",r);
  
  static pthread_t thread1;
  static pthread_t thread2;
  i = 1; j = 2;
  sem_post(&sem_a);
  r = pthread_create(&thread1,NULL,&testRoutine,&i);
  sem_post(&sem_a);
  r = pthread_create(&thread2,NULL,&testRoutine,&j);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  sem_destroy(&sem_a);
  exit(0);
  
  //printf("Result = %d\n",r);
/*
    pthread_exit(value_ptr);
    perror("pthread_create");
    exit(0);
*/

/*
  int k; int v;
  for(k=0;k<=10;k++){
    
    sem_getvalue(&sem_a,&v);
    printf("inside main %d %d\n",k,v);  
  }
*/
}




/*

void ethread_create(pthread_t *thread, const pthread_attr_t *attr, 
                    void (*start_routine)(void *), void *arg)
{
  if(pthread_create(thread,attr,(void *)start_routine,arg)){
    perror("pthread_create");
    exit(0);
  }
}

void ethread_exit(void *value_ptr)
{
  pthread_exit(value_ptr);
}


*/