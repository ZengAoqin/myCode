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
    void showPhoto(QString filename);   //显示图片

private:
    Ui::Photo* ui;
    QStringList m_dirpathList;  //存储图片路径
    int m_currentIndex;         //当前显示图片的角标
    QTimer* m_pTimer;           //实例化定时器对象
};

#endif // PHOTO_H
