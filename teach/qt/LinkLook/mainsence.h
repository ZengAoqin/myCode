#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QDebug>
#include <QVector>
#include <QSound>
#include <QTimer>
#include "config.h"
#include "fruit.h"

class MainSence : public QWidget
{
    Q_OBJECT
public:
    explicit MainSence(QWidget* parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent* event);   //��갴���¼�
    virtual void paintEvent(QPaintEvent* event);        //�����¼�
signals:

private slots:
    void on_timeout();
private:
    //�滭����ͼ
    void drawBackGroup();
    //�滭ˮ��ͼ
    void drawFruit();
    //��ʼ��ˮ������
    void initFruitData();
    //��������
    void randFruitData();
    //���ű�������
    void playBGM();
private:
    QVector<Fruit> m_fruit; //�����洢ˮ������
    //������������
    QPoint m_point1;
    QPoint m_point2;
    //�����ж��ǵڼ��ε��
    int m_nClickedCount;
    //���嶨ʱ������
    QTimer m_timer;
};

#endif // MAINSENCE_H
