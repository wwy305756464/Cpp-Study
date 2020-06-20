// chapter3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


/* prob1: c++中的函数是什么？什么叫主调函数？什么叫被调函数？两者之间有什么关系？如何调用一个函数？
    函数：将一个复杂的系统划分为若干子程序，c++中的子程序就是函数
    主调函数和被调函数：调用其他函数的函数是主调函数，被主调函数调用的函数叫做被调函数。实际情况中一个函数既可以调用其他函数也可以被其他函数调用。
    如何调用：调用函数之前要先声明函数原型：    
        类型标识符 函数名（带参数类型的形参表）;
            在声明完函数原型之后，可以调用函数：
        函数名（实参表）;
*/

//prob2: 
//int main()
//{
//    int intOne;
//    int& rSomeRef = intOne;
//
//    intOne = 5;
//    cout << "intOne:\t" << intOne << endl;
//    cout << "rSomeRef:\t" << rSomeRef << endl;
//
//    int intTwo = 10;
//    rSomeRef = intTwo;  // 引用本身不另外开辟空间来储存数据，所以rSomeReF在初始化的时候已经与intOne共享内存位置。
//                        // 在这里没有将引用绑定在别的对象上，而是对引用重新赋值。因为我们知道rSomeRef是intOne的一
//                        // 个别名。所以对引用重新赋值也就等于对intOne重新赋值。
//    cout << "intOne:\t" << intOne << endl;   // 
//    cout << "intTwo:\t" << intTwo << endl;
//    cout << "rSomeRef:\t" << rSomeRef << endl;
//}

/* prob3：比较值传递和引用传递的相同点和不同点
    值传递：将实参的值传递给形参，之后形参在函数中进行运算，无论形参的值发生怎么样的改变，实参都不会发生变化
    引用传递：函数的参数表中传进去的不是实参而是对实参的引用，即形参接受实参的时候进行了形实结合。这样函数内部形参发生的
             变化也会让实参发生改变。因为两者共享一个地址
*/

/* prob4：什么叫内联函数？它有哪些特点？
    内联函数：用inline修饰的函数，在调用这个函数的时候，编译器不会到这个函数里面进行调用，而是将函数体直接复制插入到调用位置
    特点：声明是内联函数之后并不保证编译器会执行
         内联函数体中一般不会使用循环或者递归调用
         内联函数的定义必须出现在第一次被调用之前
*/

/* prob5： 函数原型中的参数名与函数定义中的参数名以及函数调用中的参数名必须一致么？
    不必一致，因为调用参数时是根据参数的位置还有类型来区分的，而不是名字
*/

/* prob6： 调用被重载的函数时，通过什么来区分被调用的是哪个函数？   
    通过参数的类型和数量
*/

// prob7: 完成函数。参数是两个unsigned short int 型数，返回值为第一个参数除以第二个参数的结果，数据类型为short int。如果第
//        二个参数为0，则返回值为-1。在程序中实现输入输出
//short int calc(unsigned short int A, unsigned short int B) {
//    short int res = -1;
//    if (B != 0) {
//        res = A/B;
//    }
//    return res;
//}
//
//int main() {
//    cout << "Please enter values A and B:" << endl;
//    unsigned short int A, B;
//    cout << "enter A: ";
//    cin >> A;
//    cout << "enter B: ";
//    cin >> B;
//    short int res = calc(A, B);
//    cout << "res is: " << res << endl;
//    return 0;
//}


// prob8：编写函数把华氏温度转换为摄氏温度，公式为 C=5/9(F-32)。在主程序中提示用户输入一个华氏温度，转化后输出相应的摄氏温度
//double tempC(double tempF) {
//    double tempC = (tempF - 32) * 5 / 9;
//    return tempC;
//}
//
//int main() {
//    double tempF;
//    cout << "Enter temperature in F: ";
//    cin >> tempF;
//    double res = tempC(tempF);
//    cout << "Convert to temperature in C as: " << res << endl;
//    return 0;
//}

// prob9：编写一个函数判别一个数是否是质数，在主程序中实现输入输出
//bool judge(int num) {
//    int rest;
//    for (int i = 2; i <= num; ++i) {
//        rest = num % i;
//        if (rest == 0) {
//            return true;
//            break;
//        }
//        return false;
//    }
//}
//
//int main() {
//    int num;
//    cout << "Enter a number: ";
//    cin >> num;
//    bool res = judge(num);
//    if (res == true) {
//        cout << "It is not" << endl;
//    }
//    else {
//        cout << "It is" << endl;
//    }
//    return 0;
//}


// prob10：编写函数求两个整数的最大公约数和最小公倍数
//int GreatedCommonDivider(int a, int b) {
//    int small = (a <= b) ? a : b;
//    int large = (a <= b) ? b : a;
//    int res;
//    for (int i = small; i >= 1; --i) {
//        if (small % i == 0 && large % i == 0) {
//            res = i;
//            break;
//        }
//    }
//    return res;
//}
//
//int LeastCommonMultiple(int a, int b) {
//    int small = (a <= b) ? a : b;
//    int large = (a <= b) ? b : a;
//    int mult = small * large;
//    int res;
//    for (int i = large; i <= mult; ++i) {
//        if (i % large == 0 && i % small == 0) {
//            res = i;
//            break;
//        }
//    }
//    return res;
//}
//
//int main() {
//    cout << "enter two numbers: " << endl;
//    int a, b;
//    cout << "num1 is: ";
//    cin >> a;
//    cout << "num2 is: ";
//    cin >> b;
//    int divider = GreatedCommonDivider(a, b);
//    int multiple = LeastCommonMultiple(a, b);
//    cout << "Greated common diviser is: " << divider << endl;
//    cout << "Least Common Multiple is: " << multiple << endl;
//    return 0;
//}

/* prob11: 什么叫做嵌套调用？什么叫做递归？
    嵌套调用：函数A调用了函数B，函数B再调用函数C
    递归：函数直接或者间接地调用自身
*/

// prob12: 在主程序中提示输入整数n，编写函数用递归的方法求1+2+3+...+n的值
//int sum(int n) {
//    int res;
//    if (n == 1) return 1;
//    res = n + sum(n - 1);
//    return res;
//}
//
//int main() {
//    cout << "Enter a number: ";
//    int num;
//    cin >> num;
//    int res = sum(num);
//    cout << "sum is: " << res;
//}

// prob13: 用递归的方法编写函数求Fibonacci级数
//int Fibonacci(int n) {
//    int res;
//    if (n == 1 || n == 2) {
//        return 1;
//    }
//    res = Fibonacci(n - 1) + Fibonacci(n - 2);
//    return res;
//}
//
//int main() {
//        cout << "Enter a number: ";
//        int num;
//        cin >> num;
//        int res = Fibonacci(num);
//        cout << "Result of Fibonacci is: " << res;
//}

// prob14: 用递归地方法编写函数求n阶勒让德多项式的值，在主程序中实现输入输出。
//double Legendre(int n, double x) {
//    double p;
//    if (n == 0) return 1;
//    if (n == 1) return x;
//    p = ((2 * n - 1) * x * Legendre(n - 1, x) - (n - 1) * Legendre(n - 2, x)) / n;
//    return p;
//}
//
//int main() {
//        cout << "Enter n and x: ";
//        int n;
//        double x;
//        cout << "n is: ";
//        cin >> n;
//        cout << "x is: ";
//        cin >> x;
//        double res = Legendre(n, x);
//        cout << "Result of Legendre is: " << res;
//        return 0;
//}

// prob15: 编写递归函数getPower计算x^y，在同一个程序中针对整型和实型实现两个重载的函数
//int getPower(int x, int y) {
//    if (y == 0) return 1;
//    int res = x * getPower(x, y - 1);
//    return res;
//}
//
//double getPower(double x, int y) {
//    if (y == 0) return 1;
//    double res = x * getPower(x, y - 1);
//    return res;
//}
//
//int main() {
//    cout << "enter int x1, double x2, int y" << endl;
//    int x1, y;
//    double x2;
//    cout << "x1 is: ";
//    cin >> x1;
//    cout << "x2 is: ";
//    cin >> x2;
//    cout << "y is: ";
//    cin >> y;
//    int res1 = getPower(x1, y);
//    double res2 = getPower(x2, y);
//    cout << "int res is: " << res1 << "\ndouble res is: " << res2;
//}

// prob16: 当函数发生递归调用时，同一个局部变量在不同递归深度上可以同时存在不同的取值，这在底层是如何做到的？
// 因为对于同一个函数的多次调用，编译器会为每次调用的形参和局部变量分配不同的储存空间。所以在不同递归深度上时，
// 变量的取值并不受影响。