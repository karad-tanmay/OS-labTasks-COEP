#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]){
    if(argc < 4){
        printf("insufficient number of args.");
        return 0;
    }

    int fd[3];
    for(int i = 0; i < 3; i++) {
        errno = 0;
        fd[i] = open(argv[i+1], O_RDONLY);
        if(errno)
            perror("open failed");
        printf("%d\n", fd[i]);
    }

    return 0;
}
