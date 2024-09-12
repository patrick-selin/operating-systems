# Take one command line argument: The number of megabytes of memory it will use.
# allocate an array and constantly loop through the array, accessing each entry.
# The program should do this indefinitely.

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )  {
  
  if (argc != 2) {
    printf("Usage %s" , argv[0]);

    return 1;
  }
  
  int size = atoi(argv[1]);
  int elements = size * 1000000 / 8;
  
  double *array;
  array = (double *) calloc(elements, sizeof(double));
  int i = 0;
  
  while(1) {
    printf("%f\n", array[i]);
    i++;
    if (i == elements) {
      i = 0;
    }
  }
}
