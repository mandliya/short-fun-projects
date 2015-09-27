#include <stdio.h>
#include <pthread.h>

void * do_something( void * arg )
{
  int * valuePtr = (int *) arg;
  ++( *valuePtr );
  printf("Thread incremented value %d\n",   *valuePtr);
  return NULL;
}


int main()
{
  pthread_t thread_id;
  int value;
  void * exit_status;
  value = 42;
  printf("Current value of value is %d \n", value);
  pthread_create(&thread_id, NULL , do_something, &value);
  value *= 2;
  pthread_join(thread_id, &exit_status);

  printf("Final value of value is %d \n", value);
}
