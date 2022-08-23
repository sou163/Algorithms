#include<stdio.h>
#include<stdlib.h>

float *pw, *p, *w;

int max(int n){
	int i, pos;
	float mx = 0;
	for(i=0; i<n; i++){
		if(pw[i] > mx){
			mx = pw[i];
			pos = i;	
		}
	}
	pw[pos] = 0;
	return pos;
} 

void knapsack(int n, int M){
	int i, wt = 0;
	float x[n];
	
	for(i=0; i<n; i++){
		x[i] = 0;		
		pw[i] = p[i]/w[i];
	}
	
	printf("Profit-weight ratio (p/w) values:\n");
	for(i=0; i<n; i++)
		printf("%.2f\t", pw[i]);
	
	//i=0;
	while(wt < M){
		i = max(n);		
		if((wt + w[i]) <= M){
			wt += w[i];
			x[i] = 1;
		}
		else{
			x[i] = (M-wt)/w[i];
			wt = M; 
		}
		//i++;
	}
	
	printf("\nObject vector:");
	for(i=0; i<n; i++)
		printf("\t%.2f", x[i]);
}

int main(){
	int n, i, max;
	
	printf("Enter no. of objects: ");
	scanf("%d", &n);
	p = (float*)calloc(0, n*sizeof(float));
	w = (float*)calloc(0, n*sizeof(float));
	pw = (float*)calloc(0, n*sizeof(float));
	
	printf("Enter the profit values: ");
	for(i=0; i<n; i++)
		scanf("%f", &p[i]);
		
	printf("Enter the weights: ");
	for(i=0; i<n; i++)
		scanf("%f", &w[i]);
		
	printf("Enter the max weight limit: ");
	scanf("%d", &max);
	
	knapsack(n, max);
	return 0;
}
