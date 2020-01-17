#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#pragma GCC optimize("3")
//<func_declaration> __attribute__((optimize("-O3")))

#include <stdlib.h>
#include <math.h>

//#pragma comment(linker, "STACK: 102400000, 102400000")

//Data type
#define LL long long int
#define ULL unsigned long long int
#define ST size_t

//Data flag
#define LLD %lld
//#define LLD %l64d

//Common constants
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INTMOD 1000000007

//Common number operations
#define MULTI10(a) (((a)<<3)+((a)<<1))
#define NEGA(a) (~(a)+1)

//Common logic operations
#define INTMIN(a, b) ((a)+(((b)-(a))&((b)-(a))>>31))
#define INTMAX(a, b) ((b)-(((b)-(a))&((b)-(a))>>31))
//#define INTMAX(a, b) ((b)&(((a)-(b))>>31)|(a)&~(((a)-(b))>>31))
#define INTEMAX(a, b) ((a)^((a)^(b))&-((a)<(b)))
#define INTEMIN(a, b) ((b)^((a)^(b))&-((a)<(b)))
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define INTABS(a) (((a)+((a)>>31))^((a)>>31))
#define AVG(a, b) ((a)&(b)+(((a)^(b))>>1))

//Code blocks
#define forn(i, st, en, buf) for((i)=(st);(i)<(en);(i)+=(buf))
#define fore(i, st, en, buf) for((i)=(st);(i)<=(en);(i)+=(buf))
//#define DOW(a) do{ f1(a); f2(a); } while(0)



struct Complex {
	double a, b;	//a+bi
	Complex(double _a = 0.0, double _b = 0.0) :a(_a), b(_b) {}
	Complex operator - (const Complex& _a) const { return Complex(a - _a.a, b - _a.b); }
	Complex operator + (const Complex& _a) const { return Complex(a + _a.a, b + _a.b); }
	Complex operator * (const Complex& _a) const { return Complex(a * _a.a - b * _a.b, a * _a.b + b * _a.a); }
};



//Number
	//Multiply
int multiply(int a, int b, int p=INTMOD) {	//LL: a*b%p
	int rst = 0;
	for (; b; b >>= 1) {
		if (b & 1) rst = (rst + a) % p;
		a = (a << 1) % p;
	}
	return rst;
}
	//GCD
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
	//Euler PHI
		//Euler Sieve
int* phi(int a) {
	int* phi = (int*)malloc(sizeof(int) * (a + 2)), i, j;
	for (i = 1; i <= a; ++i) phi[i] = i;
	for (i = 2; i <= a; i += 2) phi[i] /= 2;
	for (i = 3; i <= a; i += 2) if (phi[i] == i) for (j = i; i <= a; j += i) phi[j] /= i * (i - 1);
	return phi;
}
		//Single
int single_phi(int a) {
	int i, rst = a;
	for (i = 2; i < sqrt(a * 1.0) + 1; ++i) if (!(a % i)) for (rst /= i * (i - 1); !(a % i); a /= i);
	if (a > 1) rst /= a * (a - 1);
	return rst;
}
		//Linear Sieve
void linear_phi(int a, int* phi, int* prime, int &tot) {
	//a: upper limit
	//phi: euler phi with size of a
	//prime: # of primes with size of a
	//tot: # of primes, init with 0
	bool* check = (bool*)calloc(a + 2, sizeof(bool));
	int i = 2, j;
	for (phi[1] = 1; i <= a; ++i) {
		if (!check[i]) {
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for (j = 0; j < tot && i * prime[j] <= a; ++j) {
			check[i * prime[j]] = 1;
			if (!(i % prime[j])) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
	//FFT
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
	//Mobius Inversion
		//Linear Sieve
void linear_mobius(int n, int *prime, int *mu){
	//TODO
}
		//Single
int single_mobius() {
	//TODO
}


//Structure
