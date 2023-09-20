#include <stdio.h>
#include <math.h>

int main(){
    //a) BIN to DEC 11011, 10010100, 11001011010101
    printf("a)\n");
    long int num = 11011; 
    int dec[16]={0}, i = 0, decnum=0;
    while(num>0){
        dec[i]=num%10;
        num/=10;
        i++;
    }
    for(i = 0; i<16; i++){
        decnum+= dec[i]*pow(2, i);
    }
    printf(" 11011 in DEC = %d\n", decnum);
    i = 0;
    decnum = 0;

    num = 10010100;
    while(num>0){
        dec[i]=num%10;
        num/=10;
        i++;
    }
    for(i = 0; i<16; i++){
        decnum+= dec[i]*pow(2, i);
    }
    printf(" 10010100 in DEC = %d\n", decnum);
    i = 0;
    decnum = 0;
    num = 11001011010101;
    while(num>0){
        dec[i]=num%10;
        num/=10;
        i++;
    }
    for(i = 0; i<16; i++){
        decnum += dec[i]*pow(2, i);
    }
    printf(" 11001011010101 in DEC = %d\n", decnum);
    i = 0;
    //b) DEC to BIN 37, 241, 2487
    printf("b)\n");
    int bin[16]={0};
    num = 37;
    while(num>=1){
        bin[i]=num%2;
        num/=2;
        i++;
    }
    printf(" 37 in bin = ");
    for(; i>0; i--) printf("%d", bin[i-1]);
    
    num = 241;
    while(num>=1){
        bin[i]=num%2;
        num/=2;
        i++;
    }
    printf("\n 241 in bin = ");
    for(; i>0; i--) printf("%d", bin[i-1]);
    
    num = 2487;
    while(num>=1){
        bin[i]=num%2;
        num/=2;
        i++;
    }
    printf("\n 2487 in bin = ");
    for(; i>0; i--) printf("%d", bin[i-1]);
    //c) HEX to DEC 6E2, ED33, 123456
    printf("\nc)\n");
    printf(" 0x6E2 = %d\n", 0x6E2);
    printf(" 0xED33 = %d\n", 0xED33);
    printf(" 0x123456 = %d\n", 0x123456);
    //d) DEC to HEX 243, 2483, 4612
    printf("d)\n");
    printf(" 243 = 0x%x\n", 243);
    printf(" 2483 = 0x%x\n", 2483);
    printf(" 4612 = 0x%x\n", 4612);
    return 0;
}