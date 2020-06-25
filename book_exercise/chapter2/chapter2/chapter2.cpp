// chapter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//// problem 2-12
//int main() {
//    //int res = 0;
//    //for (int i = 100; i <= 200; i=i+2) {
//    //    res += i;
//    //}
//
//    //int i = 100, res = 0;
//    //while (i <= 200) {
//    //    res += i;
//    //    i += 2;
//    //}
//
//    int i = 100, res = 0;
//    do {
//        res += i;
//        i += 2;
//    } while (i <= 200);
//    cout << res;
//}

//// problem 2-14
//int x = 6, y = 23;
//int main() {
//	if (x <= y) y = x;
//	else x = y;
//
//	cout << x << " " << y;
//}

//// problem 2-26
//int main()
//{
//    while (1) {
//        cout << "is it raining now?" << endl;
//        char ans;
//        cin >> ans;
//        if (ans == 'Y') {
//            cout << "it is raining" << endl;
//            break;
//        }
//        else if (ans == 'N') {
//            cout << "it is not raining" << endl;
//            continue;
//        }
//        else {
//            continue;
//        }
//    }
//    return 1;
//}

//// problem 2-27
//int main() {
//	cout << "enter your grade:" << endl;
//	int grade;
//	cin >> grade;
//	int score = grade / 10;
//	switch (score) {
//	case (10):
//	case(9):
//		cout << "A" << endl;
//		break;
//	case(8):
//		cout << "B" << endl;
//		break;
//	case(7):
//		cout << "C" << endl;
//		break;
//	default:
//		cout << "F" << endl;
//		break;
//	
//	}
//}

//// problem 2-29
//int main() {
//	for (int i = 2; i <= 100; ++i) {
//		int j = 2;
//		for (; i > j; ++j) {
//			if (i % j == 0) {
//				break;
//			}
//		}
//		if (j >= i) {
//			cout << i << endl;
//		}
//	}
//}

// problem 2-33
enum Weekday{Sunday=7, Monday=1, Tuesday, Wednesday, Thursday, Friday, Sataurday};
int main() {
	cout << Tuesday << endl;
}