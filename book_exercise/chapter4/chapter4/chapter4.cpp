// chapter4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

/* 1. 解释public和private的作用，公有类型成员与私有类型成员有哪些区别
    public和private定义了类中的成员是公有还是私有，公有说明封装后，外界还可以看到public定义的
    成员，但是private定义的成员只能这个类内使用，外界看不到。
*/

/* 2. protected 关键字有什么作用？
    protected说明了这个成员函数是保护类型的，即也只能类内使用。与私有类型不同之处在于在继承时，
    派生类有不同的访问权限
*/

/* 3. 构造函数和析构函数有什么作用？
    构造函数用于初始化一个对象，析构函数用于删掉这个对象，并且清空相关内存
*/

/* 4. 数据成员可以为公有么？成员函数可以为私有的么？
    都可以
*/

/* 5. 已知class A 中有数据成员 int a，如果定义了A的两个对象 a1, a2，他们各自的数据成员a的值可
      以不同吗？
    可以
*/

/* 6. 什么叫做复制构造函数？复制构造函数何时被调用？
    复制构造函数是用某个类的一个对象来初始化另一个对象。复制构造函数在这样三种情况下被调用：
    a) 用类的一个对象来初始化类的另一个对象
    b) 一个成员函数的参数是类的对象，那么调用函数时会进行形实结合
    c) 一个成员函数的返回值是类的对象，函数执行完后会调用复制构造函数
*/

/* 7. 复制构造函数与赋值运算符（=）有什么不同？
    复制构造函数是用一个原有的对象来创造一个新的对象，并且初始化。而赋值运算符是将一个对象的
    值赋给另一个对象，即这个新对象必须先存在才能进行赋值运算
*/

// 8. 定义一个Dog类，包含age, weight等属性，以及对这些属性操作的方法。实现并测试这个类
//class Dog {
//private: 
//    int addon = 4;
//    int wei = 50;
//public:
//    int getage(int age);
//    int getweight(int weight);
//};
//
//int Dog::getage(int age) {
//    cout << "age is: " << age + addon << endl;
//    return 0;
//}
//
//int Dog::getweight(int weight) {
//    cout << "weight is: " << weight << endl;
//    cout << wei << endl;
//    return 0;
//}
//
//int main()
//{
//    Dog Monster;
//    Monster.getage(20);
//    Monster.getweight(40);
//}

// 9. 设计并测试一个名为Rectangle的矩形类，其属性为矩形的左下角与右上角两个点
//    的坐标，根据坐标能计算矩形的面积。
//class Rectangle {
//public:
//    int getarea(int width, int height);
//private:
//    int xaxis, yaxis;
//};
//
//int Rectangle::getarea(int width, int height) {
//    xaxis = width;
//    yaxis = height;
//    int area = width * height;
//}
//
//int main() {
//    int coord1[2] = { 1, 2 };
//    int coord2[2] = { 6, 3 };
//
//}

// 10. 设计一个用于人事管理的人员类。
//class People {
//public:
//    void record(int id, string name, bool gender, int personid);
//    People(int id = 0, string name = "a", bool gender = 1, int persoid = 0) {
//        id = id;
//        name = name;
//        gender = gender;
//        personid = personid;
//    }
//
//private:
//    int id;
//
//    string name;
//    bool gender;
//    int personid;
//    Date birthdate;
//};
//
//void People::record(int id, string name, bool genger, int personid){
//}
//
//
//
//class Date {
//public:
//    Date(int year, int month, int day) {
//        year = year;
//        month = month;
//        day = day;
//    }
//    int birthday(int year, int month, int day) {
//        int birthdaydate = year * 10000 + month * 100 + day;
//        cout << "birthday date is: " << birthdaydate << endl;
//        return birthdaydate;
//    }
//
//private:
//    int year, mounth, day;
//};
//
//int main() {
//    Date Amybirthdate(1992, 6, 4);
//    int amybirthday = Amybirthdate.birthday(1992, 6, 4);
//    People Amy(1, "Amy", false, 1111);
//    People Bob(2, "Bob", true, 2222);
//
//}

//