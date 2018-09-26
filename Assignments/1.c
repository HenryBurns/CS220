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
	for(i = 0; i < n; i++){
		arr[i] = (int*) (malloc(sizeof(int) * (i + 1)));
	}
	for(i = n; i < 2*n-1 ; i++){
		arr[i] = (int*) (malloc(sizeof(int) * (cntr)));
		cntr--;
	}
	return arr;
}
void printTransitionVector(unsigned char ansr){
	int j;
	for(j = 0; j < 8; j++)
		printf("%d", !!((ansr << j)& 0x80));
	printf("\n Transition Vector test is over");
}
unsigned char transition_vector(unsigned char v){
	unsigned char ansr = (unsigned char) 0;
	ansr |= (((BIT(2) & v) << 1) ^ (BIT(3)&v)) <<4;
	ansr |= (((BIT(0) & v) << 6));
	ansr |= (((BIT(1) & v) << 1) | (BIT(2) & v)) << 5;
	ansr |= ((BIT(4) & v) & ((BIT(7) & v)>>3) & (~((BIT(0)&v)<<4))& BIT(4)); 
	ansr |= ((~((BIT(5) & v)>>2)) & BIT(5));
	unsigned char temp = (((BIT(0) & v) >> 0));
	for(int i = 1; i <8; i++){
		temp = temp ^ (((BIT(i) & v) >> i));
	}
	temp = temp << 2;
	ansr |= temp;
	ansr |= ((BIT(1) & v ) & ((BIT(2) & v) >> 1));
	ansr |= (((BIT(5) & v)>>5) | ((BIT(6) & v) >>6)); 
	return ansr;
}

void paritize (void *p, unsigned int num_bytes){
	int cntr = 0;
	unsigned char temp;
	unsigned char v;
	int i;
	while(num_bytes > 0){
		v = *(((unsigned char*) p )+ (num_bytes-1));
		//printf("initial value: %d", v);
		temp = v;
		temp = temp >>1;
		for(int i = 0; i < 7; i++){
			if(temp % 2 == 1)
				cntr++;
		//	printf("temp: %d ", temp);
			temp = temp >>1;
		}
		//printf("cntr: %d \n", cntr);
		*(((unsigned char*) p )+ (num_bytes-1))= (cntr%2 == 1)? v | 1: v & -2;
		//printf(" Value: %d\n", (int)v);
		num_bytes--;
		cntr = 0;
	}
}
void testing_paratize(int num){
	int* pptr = &num;
	printf("intial number: %d", num);
	paritize((void*) pptr, sizeof(num));
	printf("\n ansr: %d\n\n\n", num);
}
int main(){
	//TESTING Custom Allocator
	printf("Starting code\n");
	int** arr = custom_allocator(2);
	printf("TEST\n");
	int i = 0;
	for(i = 0; i < 3; i++){
		arr[i][0] = 1;
	}
	arr[1][1] = 3;
	int j = 0;
	int rows = 1;
	for(i = 0; i < 3; i++){
			if( i == 1)
				rows = 2;
			else
				rows = 1;
			for(int j = 0; j < rows; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
	//TESTING Transition Vector
	unsigned char ansr = 0x65;
	ansr = transition_vector(ansr);
	for(j = 0; j < 8; j++)
		printf("%d", !!((ansr << j)& 0x80));
	printf("\n");
	//TESTING paratize
	int p = 2;
	for(p = 0; p < 10; p++){
		testing_paratize(p);
	}
}

