#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void get_data(void)
{
  char filename[MAXNAME];
  FILE *fp;
  int i = 0;
  int x, y, z;
  int filesize, offset, bits;
  printf("入力ファイル名 : ");
  scanf("%s", filename);
  fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    printf("%sをオープンできません.\n\n", filename);
    exit(1);
  }
  printf("%sをオープンしました.\n\n", filename);
  for (i = 0; i < 54; i++)
  {
    header[i] = getc(fp);
  }
  printf("<ファイルサイズ>\n");
  filesize = cal_value(2, 5);
  printf("%dバイト\n\n", filesize);

  printf("<オフセット>\n");
  offset = cal_value(10, 13);
  printf("%dバイト\n\n", offset);

  printf("<画像の幅>\n");
  width = cal_value(18, 21);
  printf("%d画素\n\n", width);

  printf("<画像の高さ>\n");
  height = cal_value(22, 25);
  printf("%dライン\n\n", height);

  printf("<1画素当たりのビット数>\n");
  bits = cal_value(28, 29);
  printf("%dビット\n\n", bits);

  printf("<挿入ビット数>\n");
  byte = filesize - offset - width * height * (bits / 8);
  printf("%dバイト\n\n", byte);
  for (y = height - 1; y >= 0; y--)
  {
    for (x = 0; x < width; x++)
    {
      for (z = 2; z >= 0; z--)
      {
        imgin[z][x][y] = getc(fp);
      }
    }
  }
  fclose(fp);
  printf("%sをクローズしました.\n\n", filename);
}
