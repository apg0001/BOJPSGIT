#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cout.precision(10);
	long double v, a, b, count;
	cin >> a >> b >> v;
	count = (v - a) / (a - b);
	count = ceil(count);
	cout << count + 1;
	return 0;
}