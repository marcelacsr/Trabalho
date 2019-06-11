#include <stdlib.h>
#include <stdio.h>

int clean_stdin(){
    while (getchar()!='\n');
    return 1;
}

int read_int(char* string){
    int tmp =0;  
    char c;
    do
    {  
        printf("%s",string);

    } while (((scanf("%d%c", &tmp, &c)!=2 || c!='\n') && clean_stdin()) || tmp<0 );
    return tmp;
}

float read_float(char* string){
    float tmp = 0;  
    char c;
    do{  
        printf("%s",string);
    } while (((scanf("%f%c", &tmp, &c)!=2 || c!='\n') && clean_stdin()) || tmp<0 );
    return tmp;
}