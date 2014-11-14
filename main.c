#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem_a;
sem_t wait1, wait2;

void* testRoutine(void* p)
{
  int q;q = *(int*)p; 
  printf("q = %d\n",q);
  while(1){
  if(q==10){
    printf("inside wait1\n"); 
    sem_wait(&wait1);
  }else{
    printf("inside wait2\n");
    sem_wait(&wait2);
  }
  
  int i;
  for(i=0;i<=q;i++){
    printf("inside testRoutine q=%d i=%d\n",q,i); 
  }
  }
  //int* ptr;
  //pthread_exit(&ptr);
}

int main()
{
  int i,j;
  int r;
  
  r = sem_init(&sem_a,0,0);
  r = sem_init(&wait1,0,0);
  r = sem_init(&wait2,0,0);
  
  static pthread_t thread1;
  static pthread_t thread2;
  i = 10; j = 20;

  r = pthread_create(&thread1,NULL,&testRoutine,&i);
  r = pthread_create(&thread2,NULL,&testRoutine,&j);
  
  //pthread_join(thread1, NULL);
  //pthread_join(thread2, NULL);
  char c;
  while(1){
    c = getchar();
    if (c == '1') {
      sem_post(&wait1);
    } else if (c == '2') {
      sem_post(&wait2);
    } esle if (c =='3') {
      sem_post(&sem_a); //Not use yet
      break;
    }
  }

  printf("Completely exit!!\n");
  exit(0);
}


