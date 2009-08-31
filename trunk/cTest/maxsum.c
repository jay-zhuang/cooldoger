#include <stdio.h>

int max_sub_array(int a[], int n)
{
	int *flag = (int *)malloc(n*sizeof(int));
	int *sum = (int *)malloc(n*sizeof(int));
	int i;
	sum[0] = a[0];
	if( a[0] < a[1]) {
		flag[0] = 0;
		flag[1] = 1;
		sum[1] = a [1];
	}
	else {
		flag[0] = 1;
		flag[1] = 0;
		sum[1] = a[0];
	}
	for (i = 2; i < n; i++) flag[i] = 0;
	for (i = 2; i < n; i++) {
		if(flag[i-1]) {
			flag[i] = 1;
			sum[i] = sum[i-1] + a[i];
		}
		else {
			if (sum[i-2] + a[i] > sum[i-1]) {
				flag[i-1] = 0;
				flag[i] = 1;
				sum[i] = sum[i-2] + a[i];
			}
			else {
				sum[i] = sum[i-1];
			}
		}
	}
	return sum[n-1];
}

int max_sub_array2(int a[], int n)
{
	int *sum = (int *)malloc((n+1)*sizeof(int));
	int i;
	if ( n <= 0 ) return 0;
	sum[0] = 0;
	sum[1] = a[0];
	for (i=2; i <= n; i++)
		sum[i] = sum[i-2] + a[i-1] > sum[i-1] ? sum[i-2] + a[i-1] : sum[i-1];
	return sum[n];
}

int max_sub_array3(int a[], int n)
{
	int tmp, pre, cur, i;
	if ( n <= 0 ) return 0;
	pre = 0;
	cur = a[0];
	for (i = 1; i < n; i++)
	{
		tmp = cur;
		cur = a[i] + pre;
		pre = tmp > pre ? tmp : pre;
	}
	return cur > pre ? cur : pre;
}

int main(void){
	int arr[]={3,8,4,6,45,2,4,9,1,11};
	printf("answer1: %d\n", max_sub_array(arr, 9));
	printf("answer2: %d\n", max_sub_array2(arr, 9));
	printf("answer3: %d\n", max_sub_array3(arr, 9));
	return 0;	
}

