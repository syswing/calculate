#include<iostream>
#include<string>
#include<vector>

using namespace std;

double f(double x, double y) {
    return -2 * x * y;
}

vector<double> LongGe(double x0, double y0, double h, int N) {
    vector<double> Y(N, 0);
    Y[0] = y0;
    double x = x0;
    double k1 = 0;
    double k2 = 0;
    for (int n = 1; n < N; n++) {
        //        p = Y[n - 1] + h * f(x, Y[n - 1]);
        //        x += h;
        //        c = Y[n - 1] + h * f(x, p);
        //        Y[n] = (p + c) / 2;
        k1 = f(x, Y[n - 1]);
        x +=  h/2;
        k2 = f(x, Y[n - 1] + (h / 2) * k1);
        Y[n] = Y[n - 1] + h * k2;
        x = x0 + n * h ;
    }
    return Y;
}

int main() {
    char a = 'n';
    do {
        cout << "请输入步长h和要计算的函数值的个数N： " << endl;
        double h;
        int N;
        cin >> h >> N;
        cout << "请输入要初始函数点（x0，y0）：" << endl;
        double x0;
        double y0;
        cin >> x0 >> y0;
        vector<double> Y = LongGe(x0, y0, h, N + 1);
        cout << "龙哥库塔计算结果为：  " << endl;
        for (int i = 0; i < N + 1; i++) {
            cout << x0 + i * h  << "     " << Y[i] << endl;
        }
        cout << "是否要继续？(y/n)" << endl;
        cin >> a;
    } while (a == 'y');
    return 0;
}
