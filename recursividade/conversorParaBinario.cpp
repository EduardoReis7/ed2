#include <stdlib.h>
#include <stdio.h>

int converteParaBinario(int x) {
	
}

int main() {
	int x = 10, i, bin[10];
	
	for (i = 0; i < 10; i++) {
		bin[i] = 0;
	}

	i = 10;	
	while (x > 1) {
		bin[i] = x % 2;
		x = x / 2;
		i--;
	}
	for (i = 10; i > 0; i--) {
		printf("%d", bin[i]);
	}
}
