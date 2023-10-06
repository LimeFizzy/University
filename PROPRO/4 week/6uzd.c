#include <stdio.h>
#include <limits.h>

int MaxNum(int size[], int n);

int main(){
    int sequence[999]={0}, size[999]={0}, newNum=1, n=0;
    
    while(newNum>0){
        printf("Iveskite sveikaji skaiciu.\n");
        scanf("%d", &newNum);
        printf("Ivestis sekmingai issaugota.\n");
        sequence[n] = size[n] =newNum;
        ++n;
    }
    
    for(int i=0; i<n; ++i){
        int counter=0;
        while(size[i]!=0){
            size[i]/=10;
            counter++;
        }
        size[i]=counter;
    }

    printf("Skaicius(-iai) su didziausiu skaitmenu skaiciumi:\n");

    for(int i=0; i<n; ++i){
        if(size[i]==MaxNum(size, n)){
            printf("%d ", sequence[i]);
        }
    }
    return 0;
}

int MaxNum(int size[], int n){
    int max = INT_MIN;
    for(int i=0; i<n; ++i){
        if(size[i]>max)
            max = size[i];
    }
    return max;
}