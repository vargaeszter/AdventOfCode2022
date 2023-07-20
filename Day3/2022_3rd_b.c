#include <stdio.h>
#include <stdlib.h>

/*ALGO
read a line to a chained list while counting the number of elements
set a pointer to the middle of the list
search every element of the first helf in the second half until finding one
add priority
restart
if EOF free list
*/

typedef struct element{
    char c;
    struct element * next;
} element;

int setElement(element* e, char c, element* next){
    if(e == NULL)
        return 1;
    e->c = c;
    e->next = next;
    return 0;
}

int main(){
    FILE* fp = fopen("input.txt", "r");
    if(fp == NULL){
        fprintf(stderr, "Unable to open file.\n");
    }
    else{     
        int eof, mod = 0, sum = 0;
        element head[3];
        element *p[3], *tmp;
        setElement(&head[0], 0, NULL);
        setElement(&head[1], 0, NULL);
        setElement(&head[2], 0, NULL);

        p[0] = &head[0];
        p[1] = &head[1];
        p[2] = &head[2]; 
        // read char
        char cin;
        while(eof = fscanf(fp, "%c", &cin)){
            // if char is \n or EOF find find prior
            if(cin == '\n' || eof == EOF){
                while(p[mod]->next != NULL){
                    tmp = p[mod]->next;
                    p[mod]->next = p[mod]->next->next;
                    free(tmp);
                }
                mod = (mod + 1) % 3;
                if(mod == 0){
                    p[0] = head[0].next;
                    p[1] = head[1].next;
                    p[2] = head[2].next; 
                    while(p[0] != NULL){
                        while(p[1] != NULL){
                            if(p[1]->c == p[0]->c)
                                break;
                            p[1] = p[1]->next;
                        }
                        while(p[2] != NULL){
                            
                            if(p[2]->c == p[0]->c || p[1] == NULL)
                                break;
                            p[2] = p[2]->next;
                        }
                        if(p[1] != NULL && p[2] != NULL){
                            if(p[2]->c >= 'a' && p[2]->c <= 'z')
                                sum += p[2]->c - 'a' + 1;
                            else
                                sum += p[2]->c - 'A' + 27;
                            break;
                        }
                        else{
                            p[0] = p[0]->next;
                            p[1] = head[1].next;
                            p[2] = head[2].next; 
                        }
                    }
                    p[0] = &head[0];
                    p[1] = &head[1];
                    p[2] = &head[2]; 
                }
            }
            else if((cin >= 'a' && cin <= 'z') || (cin >= 'A' && cin <= 'Z')){
                if(p[mod]->next == NULL){
                    p[mod]->next = (element*) malloc(sizeof(element));
                    p[mod] = p[mod]->next;
                    setElement(p[mod], cin, NULL);
                }
                else{
                    p[mod] = p[mod]->next;
                    setElement(p[mod],cin,p[mod]->next);
                }
            }
            if (eof == EOF) break;
        }

        // free lists
        for(int i = 0; i < 3; i++){
            while(head[i].next != NULL){
                tmp = head[i].next;
                head[i].next = head[i].next->next;
                free(tmp);
            }
        }
        printf("Summa priority: %d\n", sum);
        fclose(fp);
    }
    return 0;
}