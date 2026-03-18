#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void put_data(void)
{
  char filename[MAXNAME];
  FILE *fp;
  int x, y, z;
  int i, num;
  printf("入力してください\n");
  printf("出力ファイル名 : ");
  scanf("%s", filename);
  fp = fopen(filename, "wb");
  if (fp == NULL)
  {
    printf("%sをオープンできません.\n", filename);
    exit(1);
  }
  printf("%sをオープンしました.\n", filename);
  for (num = 0; num < 54; num++)
  {
    fputc(header[num], fp);
  }
  for (y = height - 1; y >= 0; y--)
  {
    for (x = 0; x < width; x++)
    {
      for (z = 2; z >= 0; z--)
      {
        fputc(imgout[z][x][y], fp);
      }
    }
  }
  for (i = 0; i < byte; i++)
  {
    fputc('\0', fp);
  }
  fclose(fp);
  printf("%sをクローズしました.\n\n", filename);
}
