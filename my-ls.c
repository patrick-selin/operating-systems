#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  struct dirent *entry;

  while ((entry = readdir(dir)) != NULL) {
    printf("%lu %s\n", entry->d_ino, entry->d_name);
  }
  
  closedir(dir);
  return EXIT_SUCCESS;
}
