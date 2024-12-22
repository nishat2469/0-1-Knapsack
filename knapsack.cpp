#include<bits/stdc++.h>
using namespace std;

double knapsack(int p[], int wt[], int W, int n)
{

int mat[n+1][W+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i==0||j==0)
            {
                mat[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                mat[i][j]=mat[i-1][j];
            }
            else
            {
                mat[i][j]=  max(mat[i-1][j], p[i-1]+mat[i-1][j-wt[i-1]]);
            }

        }
    }
    return mat[n][W];


}

int main()
{

    int n=4;
//int p[n];
//for(int i=0;i<n;i++){
//    cin>>p[i];
//}
    int p[]= {2,4,7,10};
    int wt[]= {1, 3, 5, 7};
    int W=8;

    double ans= knapsack(p,wt,W,n);
    cout<<ans<<endl;
}

