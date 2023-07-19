#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{     
        int score = 0;
        char c1, c2;  
        while(fscanf(fp, "%c %c",&c1 , &c2) >= 2){
            score += c2 - 'X' + 1;
            switch((c2 - 'X') - (c1 - 'A')){
                case 0: score += 3; break;
                case 1: score += 6; break;
                case -2: score += 6; break;
                default: break;
            }
            fscanf(fp, "\n");
        }
        printf("The total expected score is: %d", score);
        fclose(fp);
    }
    return 0;
}