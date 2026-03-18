#ifndef CALCULATOR_H /* 二重インクルード防止 */
#define CALCULATOR_H
// 全体の関数やグローバル変数の宣言
// 関数宣言
#define MAXNAME 50
int cal_value(int lsb_index, int bytes);
void get_data(void);
void rgb_to_ybr(void);
void black_whtite(void); // 白黒
void inversion(void);     // 左右反転
void zoom(void);         // 拡大縮小
void binarization(void); // 二値化
void smoothing(void);    // 平滑化
void ybr_to_rgb(void);
void put_data(void);

extern unsigned char header[54];
extern unsigned char imgin[3][512][512];
extern unsigned char imgout[3][512][512];
extern double dtemp[3][512][512];
extern int width;
extern int height;
extern int byte;
#endif