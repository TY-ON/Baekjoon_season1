#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int n;
    char table[1024][1024] = {0, };
    char base[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    scanf("%d", &n);
    
    //generate_table
    table[0][0] = 1;
    for (int i = 1; i < n/3; i<<=1)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                table[i+j][k] = table[j][k];
                table[i+j][i+k] = table[j][k];
            }   
        }
    }

    for (int i = 0; i < n/3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            for (int l = 0; l < n-(i*3)-3; l++)
            {
                printf(" ");
            }
            for (int j = 0; j < i+1; j++)
            {
                if (table[i][j]) {
                    for (int l = 0; l < 5; l++)
                    {
                        if (base[k][l])
                        {
                            printf("*");
                        } else{
                            printf(" ");
                        }
                    }
                } else{
                    printf("     ");
                }
                printf(" ");
            }
            
            for (int l = 0; l < n-(i*3)-3; l++)
            {
                printf(" ");
            }
            printf("\n");
        }
    }
    
    

    return 0;
}