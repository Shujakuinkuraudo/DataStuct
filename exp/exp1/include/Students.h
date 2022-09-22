#pragma once

#include "head.h"
class Students;
class Student
{
    string name;
    string code;
    string major;
    string birthday;
    bool sex;
    public:
    Student();
    Student(const Student& other);
    Student(string name,string code,string major,string birthday,bool sex);
    Student& operator =(const Student& another);
    string key() const;
    friend istream& operator>>(istream& in,Student& s)
    {
        cout << "name code major birthday sex" << endl;
        in >>s.name >> s.code >> s.major >> s.birthday >> s.sex;
        return in;
    }
    friend ostream& operator<<(ostream& out,const Student& s)
    {
        out << s.name << " " << s.code <<" "<<s.major << " "<<s.birthday << " "<<s.sex << endl;
        return out;
        
    }
    friend Students;
};

class Students
{
    LinkList<Student> data;
    public:
    Students();
    Students(Student arr[],int n);
    void Create(string name,string code,string major,string birthday,bool sex);
    void Create();
    int Query(string code);
    Student Delete(int index);
    void Modify(int index);
    void Menu();
};

