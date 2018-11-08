#include <stdio.h>
#include <stdlib.h>

int main(){
int cntr = 0;
	cntr++;
	int*p = (int*) malloc(1000000000 * sizeof(int));
	free(p);
}

