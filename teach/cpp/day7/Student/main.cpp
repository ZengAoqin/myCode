#include <iostream>

using namespace std;

//定义Student类
class Student
{
    //类中声明友元函数
    friend void addScore(const Student* stu, int len);
public:
    Student(int score): score(score) {}
    //~Student() {}
private:
    int score; //分数
};

void addScore(const Student* stu, int len)
{
    int scoreCount = 0;
    int i;
    for(i = 0; i < len; ++i)
    {
        //scoreCount += (stu + i)->score;
        scoreCount += stu[i].score;
    }
    cout << "scoreCount: " << scoreCount << endl;
}

int main()
{
    //初始化5个类对象
    Student stu[5] = {95, 92, 99, 86, 79};
    addScore(stu, 5);
    return 0;
}
