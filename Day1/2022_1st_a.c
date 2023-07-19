#include <stdio.h>
#include <stdlib.h>

typedef struct elf{
    int id;
    int weight;
} elf;

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{
        //fprintf(stderr, "Success.\n");
        elf current;
        elf max;
        max.weight = 0;
        current.weight = 0;
        int weight = 0;
        char input;

        while((input = getc(fp)) >= 0){
            if(input >= '0' && input <= '9')
                weight = 10*weight + input - '0';
            else if(input = '\n' && weight > 0) {
                current.weight += weight;
                weight = 0;
            }
            else if(input == '\n' || input == '\0') {
                if(max.weight < current.weight){
                    max.id = current.id;
                    max.weight = current.weight;
                }
                current.id++;
                current.weight = 0;
                if(input == EOF){
                    printf("The number %d reindeer carries the most calories, namingly %d kcal.\n", max.id, max.weight);

                }
            }
            else{
                fprintf(stderr, "Invalid character.\n");
                break;
            }

        }
        current.weight += weight;
        if(max.weight < current.weight){
            max.id = current.id;
            max.weight = current.weight;
        }

        printf("The number %d reindeer carries the most calories, namingly %d kcal.\n", max.id, max.weight);
        fclose(fp);
    }
    return 0;
}