#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

void printHello(char *name) {
  printf("Hello! %s\n", name);
}

int main(void) {
  int a = 36;
  int b = 64;
  printf("a + b = %d\n", add(a, b));

  printHello("world");
}
