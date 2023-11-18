#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

int strlenght(char *string){
    char counter = 0;
    
    for(int i = 0; string[i] != '\0'; ++i){
        counter++;
        if(counter == CHAR_MAX){
            return -1;
        }
    }
    return counter;
}

int main(){
    char max[CHAR_MAX];
    for(int i = 0; i < CHAR_MAX; ++i){
        max[i] = 'a';
    }
    assert(strlenght("Bye") == strlen("Bye"));
    assert(strlenght("Hello") == strlen("Hello"));
    assert(strlenght("4") == strlen("4"));
    assert(strlenght("") == strlen(""));
    assert(strlenght(max) == -1);
    return 0;
}