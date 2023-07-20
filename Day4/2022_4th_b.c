#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{     
        int a1, a2, b1, b2, overleap = 0;
        while(fscanf(fp, "%d-%d,%d-%d",&a1 , &b1,&a2, &b2) >= 4){
            if(a1 <= a2 && b1 >= b2){
                overleap ++; //+= (b2-a2) + 1;
            }
            else if(a1 >= a2 && b1 <= b2){
                overleap ++; //+= (b1-a1) + 1;
            }
            else if(a1 <= b2 && b1 >= b2){
                overleap ++; //+= (b2-a1) + 1;
            }
            else if(a2 <= b1 && b2 >= b1){
                overleap ++; //+= (b1-a2) + 1;
            }
            fscanf(fp, "\n");
        }
        printf("The total number of overleaping arrangements is: %d", overleap);
        fclose(fp);
    }
    return 0;
}