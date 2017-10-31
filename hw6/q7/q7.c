#include <sys/mman.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PAGESIZE 4096
#define SIZE 3 * PAGESIZE

/*
 * PROT_NONE 
 * PROT_READ
 * PROT_WRITE
 */

void change_flag(void * addr, int size, int flag)
{
  addr = (void *)((int) addr & ~(PAGESIZE - 1));
  if (mprotect(addr, size, flag) < 0)
  { 
    exit(-1);
  }
}

void handler(int signum, siginfo_t *info, void *uarg)
{
  printf("Handler start\n");
  void *addr = info->si_addr;
  printf("Segfault at %p\n", addr);
  change_flag(addr, PAGESIZE, signum);
}

void Signal(int signum, void *handler_t)
{
  if(signal(signum, handler_t) == SIG_ERR)
    perror("Error signalling \n");
}

int main(void)
{
  int *arr;
  // we react to WRITE signal
  // because we donot expect it to write
  printf("Start listening to PROT_WRITE\n");
  Signal(PROT_WRITE, handler);
  printf("Listening setting done\n");
  arr = (int *)malloc(SIZE);
  // change flag of array to read only
  change_flag(arr, SIZE, PROT_READ);
  arr[3] = 20;
  printf("Success\n");
  return 0;
}

