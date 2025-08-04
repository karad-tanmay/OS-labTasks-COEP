#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// exec fails: permission denied, invalid file

int main(){
    // permission denied
    execl("test.out", "", NULL);
    if(errno)
        perror("exec failed");

    // invalid file
    errno = 0;
    execl("test.txt", "", NULL);
    if(errno)
        perror("exec failed");

    return 0;
}