#include "work_thread.h"
#include <iostream>
#include <memory>
#include <map>
#include <stack>
#include <list>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>
#include <string.h>
#include <stdint.h> 
#include <algorithm>
using namespace std;

class Person {
    public:
    virtual void learn() = 0;
    virtual void saodi() = 0;
};

class Student: public Person{
    public:
    void learn() override {
        cout<<"student is learning..."<<endl;
    }

    void saodi() override {
        cout<<"student start saodi..."<<endl;
    }
};

class Teacher: public Person{
    public:
    void set_callback(Person * person){
        person_ = person;
    }
    void learn() override {
        cout<<"teacher is learning..."<<endl;
    }

    void saodi() override {
        person_->saodi();
    }

    private:
        Person * person_;
};


int main(int argc, char** argv) {
    Person *p = new Student();
    p->learn();
    Teacher * teacher = new Teacher();
    teacher->set_callback(p);
    teacher->saodi();
    return 0;
}

