#include "calculator.h"
int cal_value(int lsb_index, int bytes)
{
  int i;
  int value = header[lsb_index + bytes - 1];

  for (i = bytes - 2; i >= 0; i--)
  {
    value <<= 8;
    value += header[lsb_index + i];
  }
  return (value);
}