# 画像変換プログラム

## 概要

左右反転 , モザイク化 , 拡大縮小 , 二値化 , 平滑化をc言語で行うプログラム

## 実行方法
コンパイル方法：mingw32-make

コード変更後：del *.o
再コンパイル：mingw32-make
実行コマンド：.\image.exe

## 機能ファイル説明

 pixelization.c : モザイク化
 inversion.c : 左右反転
 zoom.c : 拡大縮小
 binarization.c : 二値化
 smoothing.c : 平滑化

 ## 使用画像
 
 Parrots.bmp : 512×512サイズ