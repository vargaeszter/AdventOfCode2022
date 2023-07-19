#include <stdio.h>
#include <stdlib.h>

typedef struct elf{
    int id;
    int weight;
} elf;

int copy (elf* src, elf* dest){
    if(src == NULL || dest == NULL)
        return 1;
    dest->id = src->id;
    dest->weight = src->weight;
    return 0;
}

int change(elf* src1, elf* src2){
    if(src1 == NULL || src2 == NULL)
        return 1;
    elf tmp;
    tmp.id = src1->id;
    tmp.weight = src1->weight;
    src1->id = src2->id;
    src1->weight = src2->weight;
    src2->id = tmp.id;
    src2->weight = tmp.weight;
    return 0;
}

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{
        //fprintf(stderr, "Success.\n");
        elf current;
        elf max[3];
        for(int i = 0; i < 3; i++){
            max[i].id = 0;
            max[i].weight = 0;
        }
        int weight = 0;
        char input;

        do{
            if(input >= '0' && input <= '9')
                weight = 10*weight + input - '0';
            else if(input = '\n' && weight > 0) {
                current.weight += weight;
                weight = 0;
            }
            else if(input == '\n' || input == '\0') {
                if(max[2].weight < current.weight){
                    copy(&current, &max[2]);
                    if(max[2].weight > max[1].weight){
                        change(&max[1], &max[2]);
                        if(max[1].weight > max[0].weight){
                            change(&max[0], &max[1]);
                        }
                    }
                }
                current.id++;
                current.weight = 0;
            }
            else{
                fprintf(stderr, "Invalid character.\n");
                break;
            }
        }
        while((input = getc(fp)) >= 0);

        printf("The number %d reindeer carries the most calories, namingly %d kcal.\n", max[0].id, max[0].weight);
        printf("The number %d reindeer carries the second most calories, namingly %d kcal.\n", max[1].id, max[1].weight);
        printf("The number %d reindeer carries the third most calories, namingly %d kcal.\n", max[2].id, max[2].weight);
        printf("Together they carry %d kcal in total.\n", max[0].weight + max[1].weight + max[2].weight);
        fclose(fp);
    }
    return 0;
}