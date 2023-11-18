#include <stdio.h>
#include <assert.h>
#include <string.h>

int strcompare(char *string1, char *string2){
    for(int i = 0; string1[i] != '\0' && string2[i] != '\0'; ++i){
        if(string1[i] == string2[i]){
            continue;
        }
        else{
            return string1[i] - string2[i];
        }
    }
    return 0;
}

int main(){
    char string1[] = "Hello";
    char string2[] = "Hello";
    char string3[] = "Bro";
    char string4[] = "PROPRO";
    assert(strcompare(string1, string2) == strcmp(string1, string2));
    assert(strcompare(string1, string3) == strcmp(string1, string3));
    assert(strcompare(string1, string4) == strcmp(string1, string4));
    return 0;
}