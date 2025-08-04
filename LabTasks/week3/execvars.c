#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc != 2){
        printf("provide exec() variant to be used as an arg.");
        return 0;
    }

    // execl -
    if(strcmp(argv[1], "execl") == 0){
        execl("../week1/argcv.out", argv[1], NULL);
        printf("this wont print, unless exec fails\n");
        if(errno)
            perror("stat");
    }

    // execlp -
    else if(strcmp(argv[1], "execlp") == 0){
        execlp("../week1/argcv.out", argv[1], NULL);
        printf("this wont print, unless exec fails\n");
        if(errno)
            perror("stat");
    }

    // execvp -
    else if(strcmp(argv[1], "execvp") == 0){
        execvp("../week1/argcv.out", argv);
        printf("this wont print, unless exec fails\n");
        if(errno)
            perror("stat");
    }

    else
        printf("invalid arg.");

    return 0;
}