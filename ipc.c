#include <stdio.h>

typedef void f_t(int i, int xi);

void gen(int start, int diff, int num, f_t f) {
  for (int i=1;i<=num;i++) {
    f(i, start);
    start+=diff;
  }
}

void child_proc() {
  printf("Hello from child!\n");
}

void parent_proc() {
  printf("Hello from parent!\n");
}


void printer(int i, int xi) {
  printf("%i-th element is %i\n", i, xi);
}

int main(int argc, char *argv[])
{
  printf("Hello, World!\n");
  parent_proc();
  gen(1,2,20,printer);
  return 0;
}
