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

class Business:public enable_shared_from_this<Business>{
    public:
        static std::shared_ptr<Business> get_instance() {
            if (business_ == nullptr) {
                business_ = std::shared_ptr<Business>(new Business);
            }
            return business_;
        }

        void print(){
            cout<<"this is print"<<endl;
        }

        std::shared_ptr<Business> get_ptr(){
            // 安全低返回当前的指针 相当于this
            return shared_from_this();
        }
    private:
        static std::shared_ptr<Business> business_;
};

std::shared_ptr<Business> Business::business_ = nullptr;


int main(int argc, char** argv) {
    Business::get_instance()->print();

    Business::get_instance()->get_ptr()->print();
    return 0;
}

