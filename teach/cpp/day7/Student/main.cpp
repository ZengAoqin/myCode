#include <iostream>

using namespace std;

//����Student��
class Student
{
    //����������Ԫ����
    friend void addScore(const Student* stu, int len);
public:
    Student(int score): score(score) {}
    //~Student() {}
private:
    int score; //����
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
    //��ʼ��5�������
    Student stu[5] = {95, 92, 99, 86, 79};
    addScore(stu, 5);
    return 0;
}
