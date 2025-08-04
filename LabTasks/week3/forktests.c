#include <stdio.h>
#include <unistd.h>

int main(){
    int i = 0;
    fork();
    i++;
    if(i == 1)
        fork();
    i++;
    if(i == 2)
        fork();
    printf("%d\n", i);
    return 0;
}