#include <stdio.h>
#include <assert.h>
#include <string.h>

int strcopy(char *source, char *destination){
    printf("%d", sizeof(source));
    
    if(strlen(source) > strlen(destination)){
        return -1;
    }
    else{
        int symCount = 0;
        for(; source[symCount] != '\0'; ++symCount){
            destination[symCount] = source[symCount];
        }
        destination[++symCount] = '\0';
    }
    return 0;
}

int main(){
    char first[20] = "Hellodase";
    char second[20];
    char third[1];
    strcopy(first, second);
    //printf("%x", sizeof(char *));

    //assert(strcopy(first, second) == 0);
    //strcopy(first, third);
    //printf("%d\n", sizeof(third));
    /*for(int i = 0; i < strlen(third); ++i){
        printf("%c", third[i]);
    }*/
    //printf("%s", third);
    //assert(strcopy(first, third) == -1);
    //printf("%d", strcopy(first, third));
    return 0;
}