#ifndef CONFIG_H
#define CONFIG_H

#define C_Z(x) QString::fromLocal8Bit(x)

//游戏场景数据
#define GAME_WIDTH  512                         //宽度
#define GAME_HEIGHT 768                         //高度
#define GAME_TITLE C_Z("飞机大战 v.1.0")         //标题
#define GAME_ICON ":/res/res/app.ico"           //图标
#define GAME_RATE   10                          //间隔
#define GAME_OVER ":/res/res/gameover.png"      //游戏结束

//地图配置数据
#define MAP_PATH ":/res/res/img_bg_level_1.jpg"     //地图路径
#define MAP_SCROLL_SPEED 2                          //地图滚动速度

//英雄飞机配置数据
#define HERO_PLANE_PATH ":/res/res/hero2.png"       //英雄飞机资源图片
#define HERO_SPEED 5                                //英雄飞机移动距离
#define HERO_INVI_PATH ":/res/res/invi.png"         //英雄飞机无敌资源图片

//敌机配置数据
#define ENEMY_PLANE_PATH ":/res/res/img-plane_5.png"    //敌机资源图片
#define ENEMY_SPEED 3                                   //敌机移动速度
#define ENEMY_NUM   20                                  //敌机的总数量
#define ENEMY_INTERVAL 30                               //敌机的出场间隔

//子弹配置数据
#define BULLET_PATH ":/res/res/bullet_10.png"           //子弹图片路径
#define BULLET_SPEED 6                                  //子弹速度
#define BULLET_NUM 30                                   //弹夹中子弹的总数
#define BULLET_INTERVAL 20                              //发送子弹时间间隔

//爆炸配置数据
#define BOMB_PATH ":res/res/bomb-%1.png"                //爆炸资源图片
#define BOMB_MAX 7                                      //爆炸图片最大索引
#define BOMB_INTERVAL 20                                //爆炸切图时间间隔
#define BOMB_NUM 20                                     //爆炸数量

//道具配置数据
#define PROP_PATH ":/res/res/prop_1.jpg"                //速度道具资源
#define PROP_SUPER ":/res/res/super_1.jpg"              //无敌道具资源
#define PROP_INTERVAL 300                               //道具出场间隔
#define PROP_CONTINUE 4                                 //道具续航时间
#endif // CONFIG_H
