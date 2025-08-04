#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    close(1);
    int fd = open("test.txt", O_CREAT | O_RDWR, S_IRWXU);
    printf("fd: %d\n", fd);
    printf("Output redirected successfully!");
    return 0;
}