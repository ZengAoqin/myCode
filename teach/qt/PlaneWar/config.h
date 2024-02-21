#ifndef CONFIG_H
#define CONFIG_H

#define C_Z(x) QString::fromLocal8Bit(x)

//��Ϸ��������
#define GAME_WIDTH  512                         //���
#define GAME_HEIGHT 768                         //�߶�
#define GAME_TITLE C_Z("�ɻ���ս v.1.0")         //����
#define GAME_ICON ":/res/res/app.ico"           //ͼ��
#define GAME_RATE   10                          //���
#define GAME_OVER ":/res/res/gameover.png"      //��Ϸ����

//��ͼ��������
#define MAP_PATH ":/res/res/img_bg_level_1.jpg"     //��ͼ·��
#define MAP_SCROLL_SPEED 2                          //��ͼ�����ٶ�

//Ӣ�۷ɻ���������
#define HERO_PLANE_PATH ":/res/res/hero2.png"       //Ӣ�۷ɻ���ԴͼƬ
#define HERO_SPEED 5                                //Ӣ�۷ɻ��ƶ�����
#define HERO_INVI_PATH ":/res/res/invi.png"         //Ӣ�۷ɻ��޵���ԴͼƬ

//�л���������
#define ENEMY_PLANE_PATH ":/res/res/img-plane_5.png"    //�л���ԴͼƬ
#define ENEMY_SPEED 3                                   //�л��ƶ��ٶ�
#define ENEMY_NUM   20                                  //�л���������
#define ENEMY_INTERVAL 30                               //�л��ĳ������

//�ӵ���������
#define BULLET_PATH ":/res/res/bullet_10.png"           //�ӵ�ͼƬ·��
#define BULLET_SPEED 6                                  //�ӵ��ٶ�
#define BULLET_NUM 30                                   //�������ӵ�������
#define BULLET_INTERVAL 20                              //�����ӵ�ʱ����

//��ը��������
#define BOMB_PATH ":res/res/bomb-%1.png"                //��ը��ԴͼƬ
#define BOMB_MAX 7                                      //��ըͼƬ�������
#define BOMB_INTERVAL 20                                //��ը��ͼʱ����
#define BOMB_NUM 20                                     //��ը����

//������������
#define PROP_PATH ":/res/res/prop_1.jpg"                //�ٶȵ�����Դ
#define PROP_SUPER ":/res/res/super_1.jpg"              //�޵е�����Դ
#define PROP_INTERVAL 300                               //���߳������
#define PROP_CONTINUE 4                                 //��������ʱ��
#endif // CONFIG_H
