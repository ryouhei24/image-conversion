#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void ybr_to_rgb(void)
{
  int x, y, ch, i, itemp;
  double ybr_to_rgb[3][3] =
      {
          {1.0000, 0.0000, 1.4020},
          {1.0000, -0.3441, -0.7141},
          {1.0000, 1.7720, 0.0000}};

  for (ch = 0; ch < 3; ch++)
  {
    for (y = 0; y < height; y++)
    {
      for (x = 0; x < width; x++)
      {
        dtemp[ch][x][y] = 0.0;
        for (i = 0; i < 3; i++)
        {
          if (i == 0)
          {
            dtemp[ch][x][y] += ybr_to_rgb[ch][i] * (double)imgout[i][x][y];
          }
          else
          {
            dtemp[ch][x][y] += ybr_to_rgb[ch][i] * (double)(imgout[i][x][y] - 128);
          }
        }
      }
    }
  }
  for (ch = 0; ch < 3; ch++)
  {
    for (y = 0; y < height; y++)
    {
      for (x = 0; x < width; x++)
      {
        if (dtemp[ch][x][y] > 0.0)
          itemp = (int)(dtemp[ch][x][y] + 0.5);
        else
          itemp = (int)(dtemp[ch][x][y] - 0.5);
        if (itemp > 255)
          itemp = 255;
        else if (itemp < 0)
          itemp = 0;
        imgout[ch][x][y] = itemp;
      }
    }
  }
}