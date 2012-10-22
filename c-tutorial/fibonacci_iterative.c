#include <stdio.h>

int fibonacci(int n);

int main() {
	int result = 0;

	result = fib(60);
	printf("Resultat %d\n", result);
}

int fib(int n) {
	int i;
	int fib;
	int fib0 = 0;
	int fib1 = 1;

	if (n < 2) {
		return n;
	}
	for (i = 2; i <= n; i++) {
		fib = fib0 + fib1;
		fib0 = fib1;
		fib1 = fib;
	}
	return fib;
}
