#include<bits/stdc++.h>

#define EPSILON 0.001
using namespace std;

double func(double x, int p, int q, int r, int s, int t, int u) {
    return p*exp((-1)*x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double derivFunc(double x, int p, int q, int r, int s, int t) {
    return (-1)*p*exp((-1)*x) + q*cos(x) - r*sin(x) + s*(1/cos(x)*cos(x)) + t*2*x;
}

void newtonRaphson(double x, int p, int q, int r, int s, int t, int u) {
    double h = func(x, p, q, r, s, t, u) / derivFunc(x, p, q, r, s, t);
    while (abs(h) >= EPSILON) {
        h = func(x, p, q, r, s, t, u) / derivFunc(x, p, q, r, s, t);

        x = x - h;
    }

    if (x < 0 || x > 1)
        cout << "No solution " << endl;
    else
        cout << fixed << setprecision(4)<< x;
}

int main() {
    int p,  q,  r,  s,  t,  u;
    double x = 0;

    cin >> p >> q >> r >> s >> t >> u;

    newtonRaphson(x , p , q , r , s , t , u);
    return 0;
}
