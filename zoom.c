#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void zoom(void)
{
  int x, y, z, x_after, y_after;
  double num, x_temp, y_temp;
  printf("拡大縮小率を入力して下さい! : ");
  scanf("%lf", &num);
  for (y = 0; y < height; y++)
  {
    for (x = 0; x < width; x++)
    {
      for (z = 2; z >= 0; z--)
      {
        x_temp = (double)(x / num);
        y_temp = (double)(y / num);
        if (x_temp > 0.0)
        {
          x_after = (int)(x_temp + 0.5);
        }
        else
        {
          x_after = (int)(x_temp - 0.5);
        }
        if (y_temp > 0.0)
        {
          y_after = (int)(y_temp + 0.5);
        }
        else
        {
          y_after = (int)(y_temp - 0.5);
        }
        if (0 <= x_after && x_after < width - 1 && 0 <= y_after && y_after < height - 1)
        {
          imgout[z][x][y] = imgin[z][x_after][y_after];
        }
        else
        {
          if (z == 0)
          {
            imgout[z][x][y] = 0;
          }
          else
          {
            imgout[z][x][y] = 128;
          }
        }
      }
    }
  }
  printf("\n");
}