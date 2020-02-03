#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
  int n;
  printf("please enter the number n\n");
  scanf("%d",&n);
  if (n<=0) 
    {
      printf("moron!\n");
      return 1;
    }
  pid_t pid = fork();
  if (pid == 0)
    {
      /*child process*/
      /*here we print out the fibonacci numbers, which i would do like this*/
      printf("fibonacci-numbers up to %d:\n",n);
      int *fib_array = (int*)malloc(sizeof(int)*n);
      int i;
      for (i=0;i<n;i++)
    {
      if (i<=1)
        fib_array[i] = 1;
      else
        fib_array[i] = fib_array[i-1]+fib_array[i-2];
      printf("%d\n",fib_array[i]);
    }
      free(fib_array); /*not really neccessary, but anyway*/
      exit(0);
    }
  if (pid < 0)
    {
      printf("error forking child\n");
      return 1;
    }
  if (pid > 0)
    {
      /*parent process*/
      int status;
      wait(&status);
      printf("now the child process has exited with the status %d\n",status);
      return 0;
    }
}
