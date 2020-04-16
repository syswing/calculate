#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double f(double x) {
    return (4 / (1 + x * x));
}

double FuhuaTixing(int n, double a, double b) {
    double h = (b - a) / n;
    double x = a;
    double s = 0;
    for (int k = 0; k < n - 1; k++) {
        x += h;
        s += f(x);
    }
    double T = (f(a) + s * 2 + f(b)) * h / 2;
    return T;
}

double Xinfusheng(double a, double b, int n) {
    double h = (b - a) / n;
    double x = a + 1 / 2 * h;
    double s = 4 * f(x);
    for (int k = 1; k < n; k++) {
        x += 1 / 2 * h;
        s += 4 * f(x);
        x += 1 / 2 * h;
        s += 2 * f(x);
    }
    double T = (f(a) + s + f(b)) * h / 6;
    return T;
}

double cotes(double a, double b, double n) {
    double sum = 0;
    double h = (b - a) / n;
    double x;
    for (double k = 0; k <= n - 1; k++) {
        x = a + k * h;
        sum += 32 * (f(x + (double) (1 / 4) * h) + f(x + (double) (3 / 4) * h)) + 12 * f(x + (double) (1 / 2) * h) +
               7 * (f(x) + f(x + 1));
    }
    double T = sum * h / 90;
    return T;
}

int main() {
    char ans = 'n';
    do {
        cout << "请输入积分区间(a,b)：" << endl;
        double a;
        double b;
        cin >> a >> b;
        cout << "请输入等分份数n： " << endl;
        int n;
        cin >> n;
        cout << "结果：" << cotes(a, b, n) << endl;
        cout << "是否要继续？(y/n)";
        cin >> ans;
    } while (ans == 'y');
    return 0;
}