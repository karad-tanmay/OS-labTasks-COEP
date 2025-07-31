/*
    mygrep() will print the complete line which has the matching word/pattern.
    input req: <exec_name> <file_name>
    for word/pattern: single str (no whitespace in between).
*/

#include <stdio.h>
#include <fcntl.h> // open(), O_RDONLY
#include <errno.h> // perror(), errno
#include <unistd.h> // read(), write(), lseek()
#include <stdlib.h> // malloc()
#include <string.h> // strstr() (look for replacement later)

#define LINESIZE_LIMIT 512
#define PATTERNSIZE_LIMIT 128

void printLine(char *content, int len){
    write(1, content, len);
    return;
}

int myReadLine(int fd, char* line){
    errno = 0;
    if(line == NULL)
        line = (char*)malloc(sizeof(char) * LINESIZE_LIMIT);
    char buf = '\0';
    int i = 0;
    while(read(fd, &buf, 1) && (buf != '\n') && (i < LINESIZE_LIMIT-1)){
        line[i++] = buf;
    }
    if(buf == '\n')
        line[i++] = buf;
    line[i] = '\0';
    return i;
}

void mygrep(int fd, char *pattern){
    char line[LINESIZE_LIMIT];
    int lineLen = myReadLine(fd, line);
    while(lineLen > 0){
        if(strstr(line, pattern))
            printLine(line, lineLen);
        lineLen = myReadLine(fd, line);
    }
    return;
}

int main(int argc, char* argv[]){
    // check for proper ip
    if(argc != 2){
        write(1, "expected ip args: <exec_name> <file_name>\n", 41);
        return 0;
    }

    // check for file access, read its contents
    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    // ip pattern/word-
    char pattern[PATTERNSIZE_LIMIT];
    int patternLen = 0;
    char ch;
    write(1, "Enter pattern or word: ", 23);
    while(read(0, &ch, 1) && (ch != ' ') && (ch != '\n') && (patternLen < PATTERNSIZE_LIMIT - 1)){
        pattern[patternLen++] = ch;
    }
    pattern[patternLen] = '\0';

    mygrep(fd, pattern);

    return 0;
}
