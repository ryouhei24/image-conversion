#include "calculator.h"

void rgb_to_ybr(void)
{
  int x,y,ch,i,itemp;
  //double dtemp[3][512][512];
  double rgb_to_ybr[3][3]=
    {
     { 0.2990, 0.5870, 0.1140},
     {-0.1687,-0.3313, 0.5000},
     { 0.5000,-0.4187,-0.0813}
    };
 
  for(ch=0;ch<3;ch++){
    for(y=0;y<height;y++){
      for(x=0;x<width;x++){
        dtemp[ch][x][y]=0.0;
        for(i=0;i<3;i++){
          dtemp[ch][x][y] += rgb_to_ybr[ch][i] * (double)imgin[i][x][y];
        }
      }
    }
  }
  for (ch = 0; ch < 3; ch++){
    for(y=0;y<height;y++){
      for(x=0;x<width;x++){
      if (dtemp[ch][x][y] > 0.0)
        itemp = (int)(dtemp[ch][x][y] + 0.5);
      else
        itemp = (int)(dtemp[ch][x][y]- 0.5);
      if (ch != 0)
        itemp += 128;
      if (itemp > 255)
        itemp = 255;
      else if (itemp < 0)
        itemp = 0;
      imgin[ch][x][y] = itemp;
      }
    }
  }
  
}
