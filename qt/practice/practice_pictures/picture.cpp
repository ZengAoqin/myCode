#include "picture.h"
#include "ui_picture.h"
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

Picture::Picture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Picture),
    m_pTimer(new QTimer)
{
    ui->setupUi(this);
    m_currentIndex = 0;
    m_pTimer->setInterval(3000);
    connect(m_pTimer, &QTimer::timeout, this, &Picture::on_pushButton_next_clicked);
}

Picture::~Picture()
{
    delete ui;
}

void Picture::on_pushButton_open_clicked()
{
    QString filter = "image(*.jpg *.png)";
    m_dirPicList = QFileDialog::getOpenFileNames(this, "选择图片", "./", filter);

    if(m_dirPicList.size() == 0)
    {
        return;
    }

    for (int i = 0; i < m_dirPicList.size(); ++i)
    {
        qDebug() << m_dirPicList[i];
    }
    //显示图片
    showPic(m_dirPicList[m_currentIndex]);
}

void Picture::on_pushButton_next_clicked()
{
    int size = m_dirPicList.size();
    m_currentIndex = (++m_currentIndex) % size;
    showPic(m_dirPicList[m_currentIndex]);
}

void Picture::on_pushButton_prev_clicked()
{
    int size = m_dirPicList.size();
    m_currentIndex = (--m_currentIndex + size) % size;
    showPic(m_dirPicList[m_currentIndex]);
}

void Picture::showPic(QString filename)
{
    QPixmap pix(filename);
    //获取label的size
    QSize size = ui->label->size();
    pix = pix.scaled(size);
    ui->label->setPixmap(pix);
    ui->statusBar->showMessage(filename);
}

void Picture::on_pushButton_start_clicked()
{
    m_pTimer->start();
}

void Picture::on_pushButton_stop_clicked()
{
    m_pTimer->stop();
}
