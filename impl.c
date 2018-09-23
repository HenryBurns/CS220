#include <stdio.h>
#define BIT(n) (1 << (n))
#define BIT_SET(v, mask) ( v |= (mask) )
#define BIT_CLEAR(v , mask) (v &= ~(mask) )
#define BIT_CLEAR2(v, mask) (v = (~(v) | ~(mask))
#define BIT_FLIP(v, mask) (v = ((mask) ^ 0xFFFFFFFF)
#define IS_SET_ANY(v, mask) (v & (mask))
#define BIT_MASK(len)	( BIT(len)-1)
#define BF_MASK(start, len) (BIT_MASK(len) <<start) 
#define BF_PREP(x, start, len) (  ~(BF_MASK(start, len) ) ) | ((x & BIT_MASK(len)) <<start)
struct bad_struct{
short s1 ;
long l1 ;
short s2 ;

};

struct good_struct{
short s1 ;
short s2 ;
long l1 ;
};

union unit{
char c;
int i;
long l;
};
unsigned int foo(int x[]){
return sizeof(x);
}
void print_in_binary(unsigned int x){
int i;
char nums[32];
for( i = 31; i>= 0; i-- ){
	if(x&1)
		nums[31-i] = '1';
	else
		nums[31-i] ='0';
	x = x>> 1;
}
for( i = 31; i >= 0; i--){
	printf("%c", nums[i]);
}
printf("\n");
}
int main()
{
struct good_struct gs;
printf("gs: %d\n",sizeof(gs));
printf("gs: %p\n",&gs.s1);
printf("gs: %p\n",&gs.s2);
printf("gs: %p\n",&gs.l1);
struct bad_struct bs;
printf("bs: %d\n",sizeof(bs));
printf("bs: %p\n",&bs.s1);
printf("bs: %p\n",&bs.l1);
printf("bs: %p\n",&bs.s2);
union unit u;
printf("union: %d\n",sizeof(u));
scanf("%lu" , &u.l);
printf("Union Values: %c, %lu, %d, %s \n", u.c, u.l, u.i, &u.l); 

int arr[10];
printf("Array Sizes: %d\n", sizeof(arr));
printf("%d\n", foo(arr));
int brr[20];
printf("%d\n", sizeof(brr));
printf("%d\n", foo(brr));
int crr[30];
printf("%d\n", sizeof(crr));
printf("%d\n Binary Printed: ", foo(crr));
 print_in_binary(2);
return 0;
}

