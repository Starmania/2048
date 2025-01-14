#include <stdio.h>
#include <stdlib.h>
   
int main() {
    int i,j;
    int mat[3][3];
    for(i=0;i<3;i++){
        printf("|");
        for(j=0;j<3;j++){
            mat[i][j]=(i+1)*(j+1)*24;
            printf("%4d |",mat[i][j]);
        }
        
        
        printf("\n");
    }
    return 0;
}
