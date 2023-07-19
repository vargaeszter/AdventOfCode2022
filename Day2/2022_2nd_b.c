#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{     
        int score = 0;
        char c1, c2, cin;  
        while(fscanf(fp, "%c %c",&c1 , &cin) >= 2){
            switch(cin){
                case 'X':  c2 = c1 - 1; break;
                case 'Y':  c2 = c1; break;
                case 'Z':  c2 = c1 + 1; break;
                default: break;
            }
            switch(c2 - c1){
                case 0: score += 3; break;
                case 1: score += 6; break;
                default: break;
            }
            if(c2 < 'A'){
                c2 += 3;
            }
            else if(c2 > 'C'){
                c2 -= 3;
            }
            score += c2 - 'A' + 1;
            fscanf(fp, "\n");
        }
        printf("The total expected score is: %d", score);
        fclose(fp);
    }
    return 0;
}