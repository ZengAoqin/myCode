#ifndef FRUIT_H
#define FRUIT_H
#include <QPixmap>

class Fruit
{
public:
    //���캯��
    Fruit();
    //������ԴͼƬ
    bool loadResource(const QString& filename);
    //������Դ״̬
    void setFreeStatus(bool bFree);
    //��ȡ״̬
    bool getFreeStatus();

    QPixmap m_Res;          //��ԴͼƬ

    //����
    int m_X;                //x������
    int m_Y;                //y������

private:
    //״̬
    bool m_Free;            //�Ƿ����
};

#endif // FRUIT_H
