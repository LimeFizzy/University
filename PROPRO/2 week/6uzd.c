#include <stdio.h>

int max(int x, int y, int z){
    int max;
    max = x>y ? x : y;
    max = max>z ? max : z;
    return max;
}

int min(int x, int y, int z){
    int min;
    min = x<y ? x : y;
    min = min<z ? min : z;
    return min;
}

int main(){
    /*int x, y, z;
    while(1>0){
        printf("Iveskite 1-aji sveikaji skaiciu: ");
        if((scanf("%d", &x)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis.\n");
            while(getchar() != '\n');
        }
    }
    while(1>0){
        printf("Iveskite 2-aji sveikaji skaiciu: ");
        if((scanf("%d", &y)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis.\n");
            while(getchar() != '\n');
        }
    }
    while(1>0){
        printf("Iveskite 3-aji sveikaji skaiciu: ");
        if((scanf("%d", &z)==1) && (getchar()=='\n'))break;
        else{
            printf("Neteisinga ivestis.\n");
            while(getchar() != '\n');
        }
    }*/
    
    //Maksimumo testavimas
    //Su raidem arba nesveikaisiai skaiciais netestuoju, kadangi kintamojo tipas yra int ir programa tiesiog neveiks.
    //Tuo atveju, kai vartotojas iveda skaicius veikia validavimas.
    printf("Maksimumo radimo funkcijos testavimas:\n");
    printf("1)\n Duomenys: x=1, y=2, z=3\n Gautas ats.: %d\n Teisingas ats.: 3\n", max(1, 2, 3));
    printf("2)\n Duomenys: x=99, y=99, z=99\n Gautas ats.: %d\n Teisingas ats.: 99\n", max(99, 99, 99));
    printf("3)\n Duomenys: x=-12, y=70, z=3\n Gautas ats.: %d\n Teisingas ats.: 70\n", max(-12, 70, 3));
    printf("4)\n Duomenys: x=345678, y=-2135364, z=0\n Gautas ats.: %d\n Teisingas ats.: 345678\n", max(345678, -2135364, 0));
    printf("5)\n Duomenys: x=56789876, y=1234567890, z=-1234\n Gautas ats.: %d\n Teisingas ats.: 1234567890\n", max(56789876, 1234567890, -1234));
    printf("6)\n Duomenys: x=9090909, y=808080, z=10010\n Gautas ats.: %d\n Teisingas ats.: 9090909\n", max(9090909, 808080, 10010));

    //Minimumo testavimas
    printf("\nMinimumo radimo funkcijos testavimas:\n");
    printf("1)\n Duomenys: x=1, y=2, z=3\n Gautas ats.: %d\n Teisingas ats.: 1\n", min(1, 2, 3));
    printf("2)\n Duomenys: x=99, y=99, z=99\n Gautas ats.: %d\n Teisingas ats.: 99\n", min(99, 99, 99));
    printf("3)\n Duomenys: x=-12, y=70, z=3\n Gautas ats.: %d\n Teisingas ats.: -12\n", min(-12, 70, 3));
    printf("4)\n Duomenys: x=345678, y=-2135364, z=0\n Gautas ats.: %d\n Teisingas ats.: -2135364\n", min(345678, -2135364, 0));
    printf("5)\n Duomenys: x=56789876, y=1234567890, z=-1234\n Gautas ats.: %d\n Teisingas ats.: -1234\n", min(56789876, 1234567890, -1234));
    printf("6)\n Duomenys: x=9090909, y=808080, z=10010\n Gautas ats.: %d\n Teisingas ats.: 10010\n", min(9090909, 808080, 10010));
    
    //Bendras testas
    printf("\nBendras dvieju funkciju testas: \n");
    printf(" Duomenys maksimumui: x=20, y=15, z=0\n Duomenys minimumui: x=-1, y=15, z=max\n Gautas ats.: %d\n Teisingas ats.: -1\n", min(-1, 15, max(20, 15, 0)));
    return 0;
}