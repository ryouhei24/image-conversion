#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char header[54];
unsigned char imgin[3][512][512];
unsigned char imgout[3][512][512];
double dtemp[3][512][512];
int width;
int height;
int byte;

int main(void)
{
    int num;
    get_data();   // ファイル名の入力
    rgb_to_ybr(); // rgbからybrへ変換

    // 画像変換処理
    printf("画像の 1:白黒 , 2:左右反転 , 3:拡大縮小 , 4:二値化 , 5:平滑化 が可能\n");
    printf("処理の番号を入力してください ! ： ");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("白黒画像が作成されます");
        black_whtite();
        break;
    case 2:
        printf("左右反転画像が作成されます\n");
        inversion(); // 未処理
        break;
    case 3:
        printf("拡大縮小画像が作成されます\n");
        zoom();
        break;
    case 4:
        printf("二値化画像が作成されます\n");
        binarization();
        break;
    case 5:
        printf("平滑化画像が作成されます");
        smoothing();
        break;
    default:
        printf("正しい処理が選択されていません\n");
    }
    // processing(); //メインの処理
    ybr_to_rgb(); // ybrへ変換
    put_data();   // ファイルの出力

    return 0;
}