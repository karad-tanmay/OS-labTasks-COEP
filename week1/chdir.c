#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    char dir[512];
    int result = 0;

    if(argc > 1)
        result = chdir(argv[1]);
    else
        result = chdir("..");

    if(result < 0)
        printf("invalid dir");
    else{
        if(getcwd(dir, sizeof(dir)) != NULL)
            printf("getcwd: %s\n", dir);
        else
            printf("couldnt run getcwd()");
    }

    return 0;
}