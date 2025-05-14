#include <stdio.h>
#include <stdlib.h>
void Merge(int a[], int low, int mid, int high)
{
int i, j, k, b[2000];
i=low; j=mid+1; k=low;
while ( i<=mid && j<=high )
{
if( a[i] <= a[j] )
b[k++] = a[i++] ;
else
b[k++] = a[j++] ;
}
while (i<=mid) b[k++] = a[i++] ;
while (j<=high) b[k++] = a[j++] ;
for(k=low; k<=high; k++)
a[k] = b[k];
}
void MergeSort(int a[], int low, int high)
{
int mid;
if(low >= high)
return;
mid = (low+high)/2 ;
MergeSort(a, low, mid);
MergeSort(a, mid+1, high);
Merge(a, low, mid, high);
}
int main()
{
int n, a[2000],k;
printf("no. of CPU=%d\n",n);
printf("\n Enter How many Numbers:");
scanf("%d", &n);
printf("\nThe Random Numbers are:\n");
for(k=1; k<=n; k++)
{
a[k]=rand();
printf("%d\t", a[k]);
}
MergeSort(a, 1, n);
printf("\n Sorted Numbers are : \n ");
for(k=1; k<=n; k++)
printf("%d\t", a[k]);
}