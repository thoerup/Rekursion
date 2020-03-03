#include <stdio.h>

int game[9][9] = {
                {5,3,0,0,7,0,0,0,0},
                {6,0,0,1,9,5,0,0,0},
                {0,9,8,0,0,0,0,6,0},
                {8,0,0,0,6,0,0,0,3},
                {4,0,0,8,0,3,0,0,1},
                {7,0,0,0,2,0,0,0,6},
                {0,6,0,0,0,0,2,8,0},
                {0,0,0,4,1,9,0,0,5},
                {0,0,0,0,8,0,0,7,9}};

int isPossible(int row, int column, int n)
{
    int i, c0, r0, j;
    for(i=0; i<9; i++)
        if(game[row][i] == n)
            return 0;
    for(i=0; i<9; i++)
        if(game[i][column] == n)
            return 0;
    c0 = 3*(column/3);
    r0 = 3*(row/3);
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(game[r0+i][c0+j] == n)
                return 0;
    return 1;

}

void solve()
{

    for(int row =0; row < 9; row++)
        for(int col = 0; col < 9; col++)
            if(game[row][col] == 0)
            {
                for(int n = 1; n < 10; n++)
                    if(isPossible(row, col, n))
                    {
                        game[row][col] = n;
                        solve();
                        game[row][col] = 0;
                    }
                return;
            }

    for(int j=0; j < 9 ; j++)
    {
        for(int k = 0; k < 9; k++)
            printf("%d\t",game[j][k]);
        printf("\n");
    }
    printf("\n\n");
}

int main(int argc, const char * argv[]) {
    {
        for(int j=0; j < 9 ; j++)
        {
            for(int k = 0; k < 9; k++)
                printf("%d\t",game[j][k]);
            printf("\n");
        }
         printf("\n\n");
        solve();
    }
    return 0;
}
