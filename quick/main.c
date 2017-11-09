#include<stdio.h>
void quick(int arr[],int low,int high)
{
	if(low>=high)
      	  	return;
	int temp,pivot,i=low+1,j=high;
	pivot=arr[low];
	while(i<=j)
	{
		for(;(arr[i]<pivot)&&(i<=high);i++);
		for(;(arr[j]>pivot)&&(j>low);j--);
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		else if(arr[j]<=pivot)
		{
			arr[low]=arr[j];
			arr[j]=pivot;
		}
	}

	quick(arr,low,j-1);
	quick(arr,j+1,high);
return;

}
int main()
{
	int arr[20],a,i;
	printf("enter the size of array");
	scanf("%d",&a);

	printf("enter the %d elements to be sorted",a);
	for(i=0;i<a;i++)
		scanf("%d",&arr[i]);
	
	printf("given array is=");
	for(i=0;i<a;i++)
		printf("%d\t",arr[i]);
		
	quick(arr,0,a-1);	
	
	printf("\nsorted array is=");
	for(i=0;i<a;i++)
		printf("%d\t",arr[i]);

}
