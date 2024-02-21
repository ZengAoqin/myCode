#include "photo.h"
#include "ui_photo.h"

Photo::Photo(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Photo),
    m_pTimer(new QTimer)
{
    ui->setupUi(this);
    m_currentIndex = 0;
    m_pTimer->setInterval(3000);
    connect(m_pTimer, &QTimer::timeout, this, &Photo::on_btnNext_clicked);
}

Photo::~Photo()
{
    delete ui;
}

void Photo::on_btnOpen_clicked()
{
    //设置文件过滤器
    QString filter = "image(*bmp *.jpg *.png)";

    //获取图片的路径
    m_dirpathList = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("选择图片"), "./", filter);

    //获取图片路径
    int i = 0;
    for(i = 0; i < m_dirpathList.size(); ++i)
    {
        qDebug() << m_dirpathList[i];
    }
    //显示图片
    showPhoto(m_dirpathList[m_currentIndex]);
}

//上一张
void Photo::on_btnLast_clicked()
{
    int size = m_dirpathList.size();
    //当前图片的上一张
    m_currentIndex = (--m_currentIndex + size) % size;
    //显示图片
    showPhoto(m_dirpathList[m_currentIndex]);
}

//下一张
void Photo::on_btnNext_clicked()
{
    int size = m_dirpathList.size();
    //当前图片的下一张图片
    m_currentIndex = (++m_currentIndex) % size;
    //显示图片
    showPhoto(m_dirpathList[m_currentIndex]);
}

void Photo::showPhoto(QString filename)
{
    //实例化类对象
    QPixmap pix(filename);
    //获取label的size
    QSize size = ui->label->size();
    //将图片的size伸缩成label的大小
    pix = pix.scaled(size);
    //显示图片
    ui->label->setPixmap(pix);
    //在任务栏上显示图片路径
    ui->statusBar->showMessage(filename);
}

//自动
void Photo::on_btnAuto_clicked()
{
    //开启定时器
    m_pTimer->start();
}

//暂停
void Photo::on_btnStop_clicked()
{
    //停止定时器
    m_pTimer->stop();
}
