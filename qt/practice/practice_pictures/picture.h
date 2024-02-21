#ifndef PICTURE_H
#define PICTURE_H

#include <QMainWindow>

namespace Ui {
class Picture;
}

class Picture : public QMainWindow
{
    Q_OBJECT

public:
    explicit Picture(QWidget *parent = nullptr);
    ~Picture();

private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_prev_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    void showPic(QString filename);

private:
    Ui::Picture *ui;
    QStringList m_dirPicList;
    int m_currentIndex;
    QTimer* m_pTimer;
};

#endif // PICTURE_H
