#include<bits/stdc++.h>
using namespace std;

//COMPLEXITY : O(N^3)


int main()
{

    int n;
    cout<<"The number of variable : "<<endl;
    cin>>n;
    double arr[n][n+1];
    cout<<"input the coefficients and constant : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
            cin>>arr[i][j];
    }


    //making a upper triangular matrix from the given matrix


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i<=j) continue;

            double temp=arr[j][j]/arr[i][j];

            for(int k=0;k<n+1;k++)
            {
                arr[i][k]=arr[i][k]*temp-arr[j][k];
            }



        }
    }

    //printing the upper triangular matrix
    cout<<"The upper triangular matrix : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }


    double sol[n];
    sol[n-1]= arr[n-1][n]/arr[n-1][n-1];

    int f=n-2; //f will denote the f-th solution

    for(int i=n-2;i>=0;i--)  //back substitution i.e,using the previous solution to calculate the current solution
    {
        double temp=0;
        for(int j=0;j<n;j++)
        {
            if(j>f)
            {
               temp+= arr[i][j]*sol[j];
            }
        }

        temp=arr[i][n]-temp;
        temp/= arr[i][f];
        sol[f]=temp;
        f--;
    }

    cout<<"So the solutions are : "<<endl;
    for(int i=0;i<n;i++) cout<<sol[i]<<" ";
    cout<<endl;





    return 0;
}
