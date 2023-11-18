#include <stdio.h>
#include <assert.h>
#include <string.h>

void *setmemory(void *pointer, int value, int bytesToFill){
    char *charPointer = (char *)pointer;
    
    for(int i = 0; i < bytesToFill; ++i){
        charPointer[i] = (char)value;
    }
    return pointer;
}

int main(){
    char stringptr1[] = "Blah blah blah";
    char stringptr2[] = "Blah blah blah";
    memset(stringptr1, '8', 5);
    setmemory(stringptr2, '8', 5);
    assert(memcmp(stringptr1, stringptr2, 5) == 0);
    memset(stringptr1, 0, sizeof(stringptr1));
    setmemory(stringptr2, 0, sizeof(stringptr2));
    assert(memcmp(stringptr1, stringptr2, 5) == 0);
    return 0;
}