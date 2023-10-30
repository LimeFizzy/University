#include <stdio.h>
#include <stdlib.h>

char *fileSize(char *argv[]);

int main(int argc, char *argv[]){
    argv[0] = 0;
    for(int i = 1; i <= argc; ++i){
        argv[i-1] = argv[i];
    }
    printf("%s", fileSize(argv));
    return 0;
}

char *fileSize(char *argv[]){
    int i = 0, maxSize = 0;
    int biggest;
    while(argv[i] != NULL){
        FILE *temp = fopen(argv[i], "r");
        fseek(temp, 7, SEEK_END);
        if(ftell(temp) > maxSize){
            maxSize = ftell(temp);
            biggest = i;
        }
        ++i;
    }
    return argv[biggest];
}