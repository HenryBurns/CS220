#include <stdio.h>
int main(int x, char** y){
	int i = 0;
	for(i = 0; i < x; i++){
		printf("%s", y[i]);
	}
	FILE* fp;
	fp = fopen("impl.c", "r");
	char arr[256];
	fgets(arr,256,  fp);
	printf("\n%s", arr);
	fclose(fp);
}

