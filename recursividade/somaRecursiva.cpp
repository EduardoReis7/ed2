#include <stdlib.h>
#include <stdio.h>

int somaRecursiva(int x) {
	if (x == 1) {
		return 1;
	}
	return x + somaRecursiva(x - 1);
}

int main() {
	printf("%d", somaRecursiva(5));
}
