#include <stdio.h>
#include <stdlib.h>

#define BIT(n) (1 << (n))

int **custom_allocator(unsigned int n){
	//Allocate a 2d array such that it will contain 2n -1 rows.
	//n is between 1 and 10001
	//first n rows ith row contains i+1 columns
	//the remaining rows decrease from n-1 to 1
	int** arr = (int**) (malloc(sizeof(int*) * 2*n-1));
	int i;
	int cntr = n-1;
	for(i = n; i < 2*n-1 ; i++){
	for(i = 0; i < n; i++){
		arr[i] = (int*) (malloc(sizeof(int) * (i + 1)));
	}
	int cntr = n-1;
	for(i = n; i < 2*n-1 ; i++){
		arr[i] = (int*) (malloc(sizeof(int) * (cntr)));
		cntr--;
	}
}

unsigned char transition_vector(unsigned char v){
	unsigned char ansr = (unsigned char) 0;
	ansr |= (((BIT(2) & v) << 1) ^ (BIT(3)&v)) <<4;
	ansr |= (((BIT(0) & v) << 6));
	ansr |= (((BIT(1) & v) << 1) | (BIT(2) & v)) << 5;
	ansr |= (((BIT(4) & v) & ((BIT(7) & v)>>3) & (~((BIT(0)&v)<<4)))& BIT(4)); 
	ansr |= ((~((BIT(5) & v)>>2)) & BIT(5));
	unsigned char temp = (unsigned char) (0);
	for(int i = 0; i <8; i++){
		temp = temp ^ (((BIT(i) & v) >> i));
	}
	temp = temp << 2;
	ansr |= temp;
	ansr |= ((BIT(1) & v ) & ((BIT(2) & v) >> 1));
	ansr |= (((BIT(5) & v)>>5) | ((BIT(6) & v) >>6)); 
}

void paritize (void *p, unsigned int num_bytes){
	int cntr = 0;
	while(num_bytes > 0){
		unsigned char v = *(((unsigned char*) p )+ (num_bytes-1));
		unsigned char temp = v>>1;
		while(temp != (unsigned char) 0){
			temp = temp >>1;
			cntr++;
		}
		v = (cntr%2 == 2)? v | 1: v & -2;
		num_bytes--;
		cntr = 0;
	}
}
int main(){
	int** arr = custom_allocator(2);
	int i = 0;
	for(i = 0; i < 3; i++){
		arr[i][0] = 1;
	}
	int j = 0;
	for(i = 0; i < 3; i++){
		while(arr[i][j] != NULL){
			printf("%d ", arr[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
	}
	
}
