#include <stdio.h>

long getFileSize(char *fileName);

int main(){
    char fileName[] = {0};
    printf("Iveskite failo pavadinima.\n");
    scanf("%s", fileName);
    int fileSize = getFileSize(fileName);
    printf("%d\n", fileSize);
    return 0;
}

long getFileSize(char *fileName){
    long fileSize;
    FILE* document = fopen(fileName, "rb");
    if(document == NULL){
        return -1;
    }
    else{
        fseek(document, 0, SEEK_END);
        fileSize = ftell(document);
        fclose(document);
    }
    return fileSize;
}