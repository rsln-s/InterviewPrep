#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 10;
	int m = 15;
	double** a = malloc(n*sizeof(double*));
	for (int i = 0; i < n; i++){
		a[i] =  malloc(m*sizeof(double*));
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			a[i][j] = (double) i*j;
		}
	}
	printf("a[5][14] = %lf", a[5][14]);
	for (int i = 0; i < n; i++){
		free(a[i]);
	}
	free(a);
	return 0;
}
