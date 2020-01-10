#include <stdlib.h>
#include <math.h>
struct Complex {
	double a, b;	//a+bi
	Complex(double _a = 0.0, double _b = 0.0) :a(_a), b(_b) {}
	Complex operator - (const Complex& _a) const { return Complex(a - _a.a, b - _a.b); }
	Complex operator + (const Complex& _a) const { return Complex(a + _a.a, b + _a.b); }
	Complex operator * (const Complex& _a) const { return Complex(a * _a.a - b * _a.b, a * _a.b + b * _a.a); }
};
void FFT(Complex* V, int n, int on) {
	int i, j, k;
	const double PI = acos(-1.0);
	for (i = 1, j = n >> 1; i < n - 1; ++i) {
		if (i < j) {
			Complex *t = V+i;
			V[i] = V[j];
			V[j] = *t;
		}
		for (k = n >> 1; j >= k; j -= k, k >>= 1);
		if (j < k) j += k;
	}
	for (i = 2; i <= n; i <<= 1) {
		Complex t(cos(-(on << 1) * PI / i), sin(-(on << 1) * PI / i));
		for (j = 0; j < n; j += i) {
			Complex tmp(1, 0);
			for (k = j; k < j + i / 2; ++k) {
				Complex a = V[k], b = tmp * V[k + i >> 1];
				V[k] = a + b;
				V[k + (i >> 1)] = a - b;
				t = t * tmp;
			}
		}
	}
	if (on == -1) for (int i = 0; i < n; ++i) V[i].a /= n;
}
