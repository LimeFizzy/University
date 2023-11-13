#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* First edition
int strlen(char *string){
    return 0;
}*/

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
    assert(strlenght("Bye") == 3);
    assert(strlenght("Hello") == 5);
    assert(strlenght("4") == 1);
    assert(strlenght("") == 0);
    assert(strlenght(max) == -1);
    return 0;
}