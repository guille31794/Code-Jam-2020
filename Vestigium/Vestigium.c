#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void LatinSquare(int size, int m[][size], int caseCounter);

int main(int argc, char const *argv[])
{
    /*int nExec = 0;

    scanf("%d", &nExec);

    int size = 0, n = 0,
    caseCounter = 1;

    do
    {
        scanf("%d", &size);
        int m[size][size];

        for (size_t i = 0; i < size; i++)
            for (size_t j = 0; j < size; j++)
                scanf("%d", &m[i][j]);

        LatinSquare(size, m, caseCounter);            
        ++n;
        ++caseCounter;
    } while (n < nExec);*/
    int m[3][3] = {{3,5,2},{2,3,5},{5,2,3}};
    int m2[3][3] = {{1,2,3},{2,3,4},{3,2,4}};
    LatinSquare(3, m, 1);
    LatinSquare(3, m2, 2);

    return 0;
}

void LatinSquare(int s, int m[][s], int caseCounter)
{
    int diagonalSum = 0, rowCounter = 0,
    columCounter = 0, flag = 0;

    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = 0; j < s-1 && !flag; j++)
        {
            if (m[i][j] == m[i][j+1])
            {
                ++rowCounter;
                ++flag;
            }

            for (size_t k = j+1; k < s-1 && !flag; k++)
                if (m[i][j] == m[i][k])
                {
                    ++rowCounter;
                    ++flag;
                }                
        }

        flag = 0;
        diagonalSum += m[i][i];
    }

    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = 0; j < s - 1 && !flag; j++)  
            for (size_t k = j + 1; k < s && !flag; k++)
                if (m[j][i] == m[k][i])
                {
                    ++columCounter;
                    ++flag;
                }

        flag = 0;
    }

    printf("Case #%d: %d %d %d\n", caseCounter, diagonalSum, rowCounter, columCounter);
    }
