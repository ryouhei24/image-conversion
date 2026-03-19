#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void pixelization(void)
{
    int x, y, z, i, j, num = 0, ave_in = 0;
    double sum = 0.0, ave = 0.0;
    printf("ブッロクサイズを入力して下さい(2,4,8,16) : ");
    scanf("%d", &num);
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            sum = 0;
            for (z = 2; z >= 0; z--)
            {
                if (z == 0 && x % num == 0 && y % num == 0)
                {
                    for (i = 0; i < num; i++)
                    {
                        for (j = 0; j < num; j++)
                        {
                            sum += imgin[z][x + j][y + i];
                        }
                    }
                    ave = sum / ((double)num * (double)num);
                    if (ave > 0.0)
                    {
                        ave_in = (int)(ave + 0.5);
                    }
                    else
                    {
                        ave_in = (int)(ave - 0.5);
                    }
                    if (ave_in < 0.0)
                    {
                        ave_in = 0;
                    }
                    if (ave_in > 255.0)
                    {
                        ave_in = 255;
                    }
                    for (i = 0; i < num; i++)
                    {
                        for (j = 0; j < num; j++)
                        {
                            imgout[z][x + i][y + j] = ave_in;
                        }
                    }
                }
                if (z == 1)
                {
                    imgout[z][x][y] = 128;
                }
                else if (z == 2)
                {
                    imgout[z][x][y] = 128;
                }
            }
        }
    }
    printf("出力画像データを作成しました.¥n¥n");
}