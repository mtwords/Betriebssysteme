#include <stdio.h>

int fibonacci(int n);

int main() {
	int result = 0;

        result = fib(8);
	printf("Resultat %d\n", result);
}

int fib(int n) {
	return (n < 2) ? n : fib(n-1) + fib(n-2);
}
