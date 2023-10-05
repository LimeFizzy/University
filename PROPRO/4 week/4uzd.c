#include <stdio.h>

int MinNum(int a, int b, int c);
int MaxNum(int a, int b, int c);

int main(){
    int a, b, c, DBD=0, MBK=0;
    int min, max;
    printf("Programa apskaiciuoja 3 sveikuju skaiciu DBD ir MBK.\n");
    printf("Iveskite sveikuosius skaicius a, b ir c:\n");
    scanf("%d %d %d", &a, &b, &c);
    //Apakaiciujamas DBD
    min = MinNum(a, b, c);
    while (DBD==0){
        if(min==0) 
            break;
        if(a%min==0 && b%min==0 && c%min==0)
            DBD = min;
        --min;
    }
    //Apskaiciuojamas MBK
    max = MaxNum(a, b, c);
    while(MBK==0){
        if(a==0 || b==0 || c==0)
            break;
        if(max%a==0 && max%b==0 && max%c==0)
            MBK = max;
        ++max;
    }
    //Spausdinami rezultatai
    if(DBD != 0)
        printf("Ivestu skaiciu DBD yra %d\n", DBD);
    else
        printf("Ivesti skaiciai neturi DBD.\n");

    if(DBD != 0)
        printf("Ivestu skaiciu MBK yra %d\n", MBK);
    else
        printf("Ivesti skaiciai neturi MBK.\n");
    return 0;
}

int MinNum(int a, int b, int c){
    int min = a<b ? a : b;
    min = min<c ? min : c;
    return min;
}

int MaxNum(int a, int b, int c){
    int max = a>b ? a : b;
    max = max>c ? max : c;
    return max;
}