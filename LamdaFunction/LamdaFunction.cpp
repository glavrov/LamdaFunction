#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double findRoot(double (*f) (double), double x0, double eps)
{
    int count = 0;
    double x = x0;
    double x_prev;
    do
    {
        x_prev = x;
        x = f(x);
        count++;
        cout << count << ": " << x << endl;
    } while (fabs(x - x_prev) > eps);
    return 0;
}

double F(double x) { return sqrt(x + 6.); }

double G(double x) { return (x * x + 10.) / 11.; }

int main()
{
    double x0 = 9., y0 = 1., eps = .001;
    cout << "x=F(x):\n";
    double x = findRoot([](double x) { return sqrt(x + 6); }, x0, eps);
    cout << "\nx=G(x):\n";
    double y = findRoot([](double x) { return (x * x + 10.) / 11.; }, x0, eps);
    return 0;
}
