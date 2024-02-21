#include "cloudlogin.h"
#include "ui_cloudlogin.h"


CloudLogin::CloudLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloudLogin)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);   //去掉标题栏 任务栏图标最小化
}

CloudLogin::~CloudLogin()
{
    delete ui;
}

//点击关闭窗口按钮
void CloudLogin::on_pushButtonCloseWindow_clicked()
{
    this->close();
}

//点击登录按钮
void CloudLogin::on_pushButtonLogin_clicked()
{
    //若未勾选checkBox
    if(ui->checkBox->checkState() != Qt::Checked)
    {
        QMessageBox::information(this, "提示", "请先勾选同意《服务条款》《隐私政策》《儿童保护条款》");
        return;
    }

    //判断密码是否正确
    if(PASSWORD == ui->lineEditPassword->text())
    {
        QMessageBox::information(this, "提示", "登录成功！");
        easyCloudWindow.setUserName(ui->lineEditUsername->text());
        easyCloudWindow.show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "提示", "密码错误！");
        ui->lineEditPassword->clear();
    }
}


//实现鼠标拖拽移动
void CloudLogin::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

//鼠标移动事件
void CloudLogin::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {	//这里if语句判断，让鼠标在特定控件上进行拖动才有效，比如自绘标题栏控件
        if(!ui->label->underMouse()){
            return;
        }
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

//鼠标释放事件
void CloudLogin::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}
