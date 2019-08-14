#include<stdio.h>
#include<stdlib.h>

int subset_sum(int A[],int n,int sum);
int main()
{
    int n,i,sum;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int *A=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        printf("Enter A[%d] : ",i);
        scanf("%d",&A[i]);
    }
    printf("Enter sum : ");
    scanf("%d",&sum);
    int x=subset_sum(A,n,sum);
    if(x==1)
        printf("\nThe sum %d is possible\n",sum);
    else
        printf("\nThe sum %d is not possible\n",sum);
    return 0;
}
int subset_sum(int A[],int n,int sum)
{
    int i,j;
    int **ss=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        ss[i]=(int*)malloc((sum+1)*sizeof(int));
    for(i=0;i<=n;i++)
        ss[i][0]=1;
    for(i=1;i<=sum;i++)
        ss[0][i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(A[i]>j)
                ss[i][j]=ss[i-1][j];
            else
                ss[i][j]=ss[i-1][j-A[i]] || ss[i-1][j];
        }
    }
    return ss[n][sum];
}
