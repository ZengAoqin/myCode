#ifndef CLOUDLOGIN_H
#define CLOUDLOGIN_H

#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>

#include "config.h"
#include "easycloud.h"


namespace Ui {
class CloudLogin;
}

class CloudLogin : public QWidget
{
    Q_OBJECT

//成员函数
public:
    explicit CloudLogin(QWidget *parent = nullptr);
    QString getUserName();
    ~CloudLogin();

protected:
    //鼠标拖动窗体移动
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_pushButtonCloseWindow_clicked();


//成员变量
    void on_pushButtonLogin_clicked();

protected:
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

private:
    Ui::CloudLogin *ui;
    EasyCloud easyCloudWindow;
};

#endif // CLOUDLOGIN_H
