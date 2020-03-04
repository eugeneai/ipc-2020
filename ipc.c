#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

typedef void f_t(int i, int xi);

void gen(int start, int diff, int num, f_t f) {
  for (int i=1;i<=num;i++) {
    f(i, start);
    start+=diff;
  }
}

void printer(int i, int xi) {
  printf("%i-th element is %i\n", i, xi);
}

void child_proc() {
  printf("Hello from child!\n");
}

void parent_proc() {
  printf("Hello from parent!\n");
  gen(1,2,20,printer);
}


int main(int argc, char *argv[])
{
  int cid;
  int pid=getpid();

  printf("Hello, World!\n");

  cid=fork();
  if (cid<0) {
    perror("fork");
    exit(EXIT_FAILURE);
  };
  if (cid==0) { child_proc(); }
  if (cid>0) { parent_proc(); }

  return 0;
}
