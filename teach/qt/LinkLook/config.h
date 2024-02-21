#ifndef CONFIG_H
#define CONFIG_H

//中文乱码处理
#define CZ(x) QString::fromLocal8Bit(x)

//游戏配置数据
#define ROW_COUNT   10                                //10行
#define COL_COUNT   16                                //16列
#define GAME_TITLE  "连连看 v1.0"                      //游戏标题
#define GAME_BG_PATH ":/res/res/background.png"       //游戏背景图片
#define BG_WIDTH    46                                //背景图的宽度
#define BG_HEIGHT   56                                //背景图的高度

static int gameMap[ROW_COUNT][COL_COUNT];

#endif // CONFIG_H
