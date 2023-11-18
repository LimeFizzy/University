#include <stdio.h>
#include <assert.h>
#include <string.h>

int strncompare(char *string1, char *string2, unsigned num){
    for(unsigned i = 0; i < num; ++i){
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
    char string5[] = "Hell no";
    assert(strncompare(string1, string2, 2) == strncmp(string1, string2, 2));
    assert(strncompare(string1, string3, 2) == strncmp(string1, string3, 2));
    assert(strncompare(string1, string4, 2) == strncmp(string1, string4, 2));
    assert(strncompare(string1, string5, 6) == strncmp(string1, string5, 6));
    return 0;
}