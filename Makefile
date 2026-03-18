# コンパイラの指定
CC = gcc

# コンパイルオプション
CFLAGS = -Wall -g

# 実行ファイル名
TARGET = image

# ソースファイル
SRCS = main.c cal_value.c get_data.c rgb_to_ybr.c black_whtite.c inversion.c zoom.c binarization.c smoothing.c ybr_to_rgb.c put_data.c

# オブジェクトファイル
OBJS = $(SRCS:.c=.o)

HEADERS = calculator.h

# 実行ファイルの生成ルール
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# .c から .o を生成するルール
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# クリーンアップルール
clean:
	del	$(OBJS)	$(TARGET).exe