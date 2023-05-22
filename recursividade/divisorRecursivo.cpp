#include <stdlib.h>
#include <stdio.h>

int divisor(int x, int y) {
	if (y == 1) {
		return 1;
	}
	if (x % y == 0) {
		return 1 + divisor(x, y - 1);
	} else {
		return 0 + divisor(x, y - 1);
	}
}

int main() {
	printf("Quantidade divisores de %d: %d", 9, divisor(9, 9));
}
