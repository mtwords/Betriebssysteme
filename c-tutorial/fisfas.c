#include <stdio.h>

void fisFas(int i) {
	if ((i % 3 == 0) && (i % 5 == 0)) {
		printf("%s\n", "fisfas");
	} else if (i % 3 == 0) {
		printf("%s\n", "fis");
	} else if (i % 5 == 0) {
		printf("%s\n", "fas");
	} else {
		printf("%d\n", i);
	}
}

int main() {
	int i;
	for (i = 1; i < 20; i++) {
		fisFas(i);
	}
}
