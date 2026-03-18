#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void inversion(void)
{
    int x, y, z;
    for (y = height - 1; y >= 0; y--)
    {
        for (x = 0; x < width; x++)
        {
            for (z = 2; z >= 0; z--)
            {
                imgout[z][width - x - 1][y] = imgin[z][x][y];
            }
        }
    }
}