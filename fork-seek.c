#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    int fd = open("essay.txt", O_CREAT | O_RDONLY);
    assert(fd >= 0);
    int rc = fork();  
  
    if (rc == 0) {
        rc = lseek(fd, 10, SEEK_SET);
        printf("child offset = %d\n", rc);
    } else if (rc > 0) {
        (void) wait(NULL);
        printf("parent offset = %d\n",
               (int) lseek(fd, 0, SEEK_CUR));
 }
  
return 0; 
}
