#ifndef CONFIG_H
#define CONFIG_H

//�������봦��
#define CZ(x) QString::fromLocal8Bit(x)

//��Ϸ��������
#define ROW_COUNT   10                                //10��
#define COL_COUNT   16                                //16��
#define GAME_TITLE  "������ v1.0"                      //��Ϸ����
#define GAME_BG_PATH ":/res/res/background.png"       //��Ϸ����ͼƬ
#define BG_WIDTH    46                                //����ͼ�Ŀ��
#define BG_HEIGHT   56                                //����ͼ�ĸ߶�

static int gameMap[ROW_COUNT][COL_COUNT];

#endif // CONFIG_H
