#include <iostream>
#include <cstring>

using namespace std;


class Student
{
    private:
        int age;
        char name[20];

    public:
        //无参构造函数
        Student()
        {
            cout << "Object is being created" << endl;
        }

        //有参构造函数
        Student(int age, const char* name)
        {
            cout << "Object is being created" << endl;
            this->age = age;
            strcpy(this->name, name);
        }

        //拷贝构造函数
        Student(const Student& stu)
        {
            this->age = stu.age;
            strcpy(this->name, stu.name);
        }

        void set(int age, const char* name)
        {
            this->age = age;
            strcpy(this->name, name);
        }

        void get()
        {
            cout << this->age << endl;
            cout << this->name << endl;
        }

        void get(int& age, char*& name)
        {
            age = this->age;
            name = this->name;
        }

        // void get(int* age, char* name)
        // {
        //     *age = this->age;
        //     strcpy(name, this->name);
        // }

        int getAge();

        char* getName();

        //析构函数
        ~Student()
        {
            cout << "Object is being deleted" << endl;
        }
};

int Student::getAge()
{
    return age;
}

char* Student::getName()
{
    return name;
}

int main(int argc, char* argv[])
{
    int age;
    char *name;

    // Student* stu = new Student;
    // stu->set(16, "jack");
    Student* stu1 = new Student(24, "peter");
    Student* stu2(*stu1);

    // stu->get();
    stu1->get();
    stu2->get();

    // stu->get(age, name);
    // cout << "age=" << age << endl;
    // cout << "name=" << name << endl;

    // cout << "getAge()=" << stu->getAge() << endl;
    // cout << "getName()=" << stu->getName() << endl;

    delete stu1;
    delete stu2;

    stu1 = NULL;
    stu2 = NULL;

    return 0;
}