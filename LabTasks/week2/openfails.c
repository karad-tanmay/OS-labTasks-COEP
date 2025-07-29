#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

/*
open fails when-
    1. file does not exist/incorrect pathname
    2. access to file is denied
    3. exceed limit of fd
*/

int main(){
    // file does not exist
    if (open("./nonExistentFile.txt", O_RDONLY) == -1){
        printf("errno: %d\n", errno);
        perror("open failed");
        // fprintf(stderr, "open failed");
    }
    // access denied (change the file permissions for threefds.c before execution)
    if (open("./threefds.c", O_RDONLY) == -1){
        printf("errno: %d\n", errno);
        perror("open failed");
    }
    // try reaching fd count limit by opening same file repeatedly (chatgpt cooked this)
    errno = 0;
    while(open("./openfails.c", O_RDONLY) != -1);
    if(errno){
        printf("errno: %d\n", errno);
        perror("open failed");
    }
    return 0;
}