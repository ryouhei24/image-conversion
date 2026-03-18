#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void smoothing(void)
{
    int x, y, z, i, j, sum = 0;
    double temp = 0.0;
    double num[3][3] = {};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            num[i][j] = (double)1 / 9;
        }
    }
    printf("<フィルタ係数>\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%8.6lf ", num[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            for (z = 2; z >= 0; z--)
            {
                if (z == 0)
                {
                    if (x == 0 || x == height - 1 || y == 0 || y == width - 1)
                    {
                        imgout[z][x][y] = 0;
                    }
                    else
                    {
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 3; j++)
                            {
                                temp = temp + (imgin[z][j + x - 1][i + y - 1] * num[i][j]);
                            }
                        }
                        if (temp > 0.0)
                        {
                            sum = (int)(temp + 0.5);
                        }
                        else
                        {
                            sum = (int)(temp - 0.5);
                        }
                        imgout[z][x][y] = sum;
                        temp = 0.0;
                    }
                }
                else
                {
                    imgout[z][x][y] = 128;
                }
            }
        }
    }
    printf("\n");
}