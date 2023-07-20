#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{     
        int a1, a2, b1, b2, fcontains = 0;
        while(fscanf(fp, "%d-%d,%d-%d",&a1 , &b1,&a2, &b2) >= 4){
            if((a1 <= a2 && b1 >= b2) || (a1 >= a2 && b1 <= b2)){
                fcontains++;
            }
            fscanf(fp, "\n");
        }
        printf("The number of fully overleaping intervals is: %d", fcontains);
        fclose(fp);
    }
    return 0;
}