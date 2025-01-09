#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void){
    int tab[SIZE];
    for(int i = 0; i < SIZE; i++)
        tab[i] = i*7;
        
    printf("| ");
    for(int i = 0; i < SIZE; i++){
        printf("   joueur %d   | ", i+1);}
    printf("\n| ");
    
    for(int i = 0; i < SIZE; i++)
        printf("%10d    | ", tab[i]);
    
    return 0;
}
