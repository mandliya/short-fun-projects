#include <stdio.h>
#include <pthread.h>
#include <limits.h>

long shared_data = 123456789;
pthread_mutex_t lock;
pthread_cond_t is_zero;

void * decrement( void * arg )
{
  while( shared_data > 0 ) {
    pthread_mutex_lock(&lock);
    --shared_data;
    pthread_mutex_unlock(&lock);
  }
  printf("Sending signal...\n");
  pthread_cond_signal(&is_zero);
  return NULL;
}

int main()
{
  pthread_t decrement_thread;
  void * exit_status;

  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&is_zero, NULL);

  printf("Waiting for signal!...\n");
  pthread_create(&decrement_thread, NULL, decrement, NULL);

  pthread_mutex_lock(&lock);
  while( shared_data != 0 ) {
    pthread_cond_wait(&is_zero, &lock);
  }
  pthread_mutex_unlock(&lock);
  printf("Signal received\n");

  pthread_join(decrement_thread, &exit_status);
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&is_zero);
  return 0;
}
