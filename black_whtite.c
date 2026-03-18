// 白黒画像の処理
#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void black_whtite()
{
  int array[256] = {};
  int level = (512 * 512) / 256;
  int count = 0;
  int temp = 0;
  int temp1 = 0;
  int rank[256];
  for (int k = 0; k < height; k++)
  {
    for (int j = 0; j < width; j++)
    {
      for (int i = 0; i <= 2; i++)
      {
        imgout[i][j][k] = 128;
      }
    }
  }
}
