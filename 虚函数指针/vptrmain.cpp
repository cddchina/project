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
using namespace std;

using FuncType = void (*)();

class dog  {
    public:
        dog() = default;
        virtual
        void print(){
            cout<<"func print"<<endl;
        }
        virtual
        void print2(){
            cout<<"func print2"<<endl;
        }
        virtual
        void print3(){
            cout<<"func print3"<<endl;
        }
        virtual
        void print4(){
            cout<<"func print3"<<endl;
        }
};

FuncType getFunc(dog * obj, uint64_t index) {
    uintptr_t** vptr  = reinterpret_cast<uintptr_t**>(obj);     
    uintptr_t*  vtbl  = *vptr;
    std::cout<<"  vtbl: "<<vtbl<<"  " <<(vtbl + index)<<"  "<< *(vtbl+index)<<std::endl;
    return reinterpret_cast<FuncType>(*(vtbl + index));
}

int main(int argc, char** argv) {

    dog *d = new dog();;
    auto f = getFunc(d, 0);
    f();
    auto f1 = getFunc(d, 1);
    f1();

    auto f2 = getFunc(d, 2);
    f2();
    auto f3 = getFunc(d, 3);
    f3();
    return 0;
}

//using FuncType = void (*)();  // print函数类型的 函数指针 


// class Base {
// public:
//   Base() = default;
//   virtual 
//   void print()       { std::cout <<"Actual Type:  Base" << std::endl; }
//   void PointerType() { std::cout <<"Pointer Type: Base" << std::endl;}
//   virtual ~Base()    { std::cout <<"base-dtor"<< std::endl;}
// };

// class Derived : public Base{
// public:
//   Derived() = default;
//   void print()       { std::cout <<"Actual Type:  Derived" << std::endl; }
//   void PointerType() { std::cout <<"Pointer Type: Derived" << std::endl;}
//   ~Derived()         { std::cout <<"derived-dtor ";}
// private:
//    int random_{0};
// };

// FuncType getVirutalFunc(Base* obj, uint64_t idx) { 

//   uintptr_t** vptr  = reinterpret_cast<uintptr_t**>(obj);     // 1）先取出vtpr
//   uintptr_t*  vtbl  = *vptr;                                  // 2）vptr指向的是vtbl，因此 vtbl 即 *vptr
//   uintptr_t   func  = *vtbl;                                  // vtbl存储的第一个虚函数

//   // 返回指定位置的虚函数
//   return reinterpret_cast<FuncType>(func + idx);      // 3）      
// }

// int main(int argc, char const *argv[]) {
//   Base* base = new Derived; 
//   // 编译器完成调用 
//   base->print();     
//   // 我们自己调用
//   auto print = getVirutalFunc(base, 0); // 指向print函数的函数指针
//   print();  // 调用print函数

//   delete base;
//   return 0;
// }
// g++ -std=c++11 main.cpp