#ifndef PHOTO_H
#define PHOTO_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

namespace Ui
{
class Photo;
}

class Photo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Photo(QWidget* parent = nullptr);
    ~Photo();

private slots:
    void on_btnOpen_clicked();

    void on_btnLast_clicked();

    void on_btnNext_clicked();
    void on_btnAuto_clicked();

    void on_btnStop_clicked();

private:
    void showPhoto(QString filename);   //��ʾͼƬ

private:
    Ui::Photo* ui;
    QStringList m_dirpathList;  //�洢ͼƬ·��
    int m_currentIndex;         //��ǰ��ʾͼƬ�ĽǱ�
    QTimer* m_pTimer;           //ʵ������ʱ������
};

#endif // PHOTO_H
