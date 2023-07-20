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
        int eof, len = 0, sum = 0;
        element head;
        element *p1, *p2, *mid;
        setElement(&head, 0, NULL);

        p1 = &head;
        // read char
        char cin;
        while(eof = fscanf(fp, "%c", &cin)){
            // if char is \n or EOF find find prior
            if(cin == '\n' || eof == EOF){
                while(p1->next != NULL){
                    mid = p1->next;
                    p1->next = p1->next->next;
                    free(mid);
                }
                p1 = head.next;
                mid = head.next;
                for(int i = 0; i < len/2; i++){
                    mid = mid->next;
                }
                while(p1 != mid){
                    p2 = mid;
                    while(p2 != NULL){
                        if(p1->c == p2->c)
                            break;
                        p2 = p2->next;
                    }
                    if(p2 != NULL)
                        break;
                    p1 = p1->next;
                }
                if(p2 == NULL)
                    fprintf(stderr, "Invalid input format.\n");
                else{
                    //printf("%c", p2->c);
                    if(p2->c >= 'a' && p2->c <= 'z')
                        sum += p2->c - 'a' + 1;
                    else
                        sum += p2->c - 'A' + 27;
                }
                len = 0;
                p1 = &head;
            }
            else if((cin >= 'a' && cin <= 'z') || (cin >= 'A' && cin <= 'Z')){
                len++;
                if(p1->next == NULL){
                    p1->next = (element*) malloc(sizeof(element));
                    p1 = p1->next;
                    setElement(p1, cin, NULL);
                }
                else{
                    p1 = p1->next;
                    setElement(p1,cin,p1->next);
                }
                
            }
            if (eof == EOF) break;
        }

        // free list
        while(head.next != NULL){
            p1 = head.next;
            head.next = head.next->next;
            free(p1);
        }
        printf("Summa priority: %d\n", sum);
        fclose(fp);
    }
    return 0;
}