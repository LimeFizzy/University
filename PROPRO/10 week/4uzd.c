#include <stdio.h>
#include <assert.h>
#include <string.h>

char *strchar(char *string, int symbol){
    for(int i = 0; string[i] != '\0'; ++i){
        if(string[i] == symbol){
            return (string+i);
        }
    }
    return NULL;
}

int main(){
    char string1[] = "Hello";
    assert(strchar(string1, 'l') == strchr(string1, 'l'));
    assert(strchar(string1, 'd') == strchr(string1, 'd'));
    assert(strchar(string1, 'H') == strchr(string1, 'H'));
    assert(strchar(string1, 'o') == strchr(string1, 'o'));
    return 0;
}