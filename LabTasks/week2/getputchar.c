#include <stdio.h>
#include <unistd.h>
#include <errno.h>

// (from: man errno) For  some  system calls and library functions (e.g., getpriority(2)), -1 is a valid return on success.  In such cases, a successful return can be distinguished from an error return by setting errno to zero before the call, and then, if the call returns a status that indicates that an  error may have occurred, checking to see if errno has a nonzero value.
int mygetchar(){
    errno = 0;
    char ch[1];
    ch[0] = '\0';
    while(read(0, ch, 1) == 0);
    if(errno)
        perror("mygetchar() failed");
    return ch[0];
}

void myputchar(int c){ // return type can be made int (as per man page of putchar, but i dont think it is necessary, since it returns the exact same char as unsigned int (or EOF in case of error, but i'll print the error, and can be accessed thrugh errno))
    errno = 0;
    char ch[1];
    ch[0] = c;
    write(1, ch, 1);
    if(errno)
        perror("myputchar() failed");
    return;
}

int main(){
    // close(0);
    char ch = mygetchar();
    // printf("%c\n", ch);
    myputchar(ch);
    return 0;
}
