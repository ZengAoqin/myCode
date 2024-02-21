#include "myprocess.h"
#include "ui_myprocess.h"

MyProcess::MyProcess(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MyProcess)
{
    ui->setupUi(this);
}

MyProcess::~MyProcess()
{
    delete ui;
}

void MyProcess::on_pushButton_clicked()
{
    //C:\Program Files\Notepad++
    /*
    QString program = "C:/Program Files/Notepad++/notepad++.exe";
    QStringList arguments;
    arguments << "file.txt";

    int exitCode = QProcess::execute(program, arguments);
    if(exitCode != 0)
    {
        qDebug() << QString::fromLocal8Bit("�ⲿ����ִ��ʧ��");
    }
    else
    {
        qDebug() << QString::fromLocal8Bit("�ⲿ����ִ�гɹ�");
    }
    */
    //m_process.start("calc");

    /*
    //C:\Users\RD\Desktop\Share\QT\day08\code\build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug\debug

    m_process.start("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/PlaneWar.exe");
    qDebug() << QString::fromLocal8Bit("ִ�������ɻ���ս����֮��");
    //�ȴ����̽������
    m_process.waitForFinished();
    qDebug() << QString::fromLocal8Bit("�ȴ��ɻ���սִ�����");
    */

    /*
    QString program = "C:/Program Files/Notepad++/notepad++.exe";
    QStringList arguments;
    arguments << "file.txt";
    m_process.start(program, arguments);
    QObject::connect(&m_process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(on_finished(int, QProcess::ExitStatus)));
    */

    QString command = "ping www.baidu.com";
    m_process.start(command);
    //�ȴ����̽������
    m_process.waitForFinished();

    QByteArray output = m_process.readAllStandardOutput();
    QString msg = QString::fromLocal8Bit(output);
    qDebug() << msg;
}

void MyProcess::on_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "exitCode = " << exitCode << ",exitStatus = " << exitStatus;
}
