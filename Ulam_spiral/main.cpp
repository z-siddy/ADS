// Ulam Spiral Visualization task for ADS lecture of Vilnius University
// By Žygimantas Sideravičius ISI
// For the best user experience, 9 is the critical row count for console output alignment!
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout<<"Enter odd number for rows: ";
    cin>>n;
    
    if(n%2!=0)
    {
      int tl[n/2],k=n,tr[n/2];
    for(int i=0;i<(n+1)/2;i++)
    {
        tl[i]=k*k-2*(k-1);
        tr[n/2-i-1]=tl[i]-k;
        for(int c=1;c<i+1;c++)
        {
            int z=tl[c-1];
            cout<<setw(3)<<z+i-c+1;
        }
        cout<<setw(3)<<tl[i];
        int p=tl[i]-1;
        for(int j=0;j<n-2*i-1;j++)
        {
            cout<<setw(3)<<p;
            p--;
        }
        k-=2;
        for(int m=0;m<i;m++)
        {
            cout<<setw(3)<<tr[n/2-i+m];
            tr[n/2-i+m]--;
        }
        cout<<endl;
    }
    int bl[n/2],br[n/2],w=n;
    for(int i=0;i<n/2;i++)
    {
        bl[i]=w*w-2*(w-1)+2*(w/2);
        br[n/2-i-1]=w*w;
        w=w-2;
    }
    for(int i=0;i<n/2;i++)
    {
        int x=n/2-1-i;
        for(int j=0;j<n/2-i;j++)
        {
            cout<<setw(3)<<bl[j]-x;
            x--;
        }
        for(int a=0;a<2*(i+1);a++)
        {
            bl[n/2-i-1]++;
            cout<<setw(3)<<bl[n/2-i-1];
        }
        for(int c=0;c<n/2-i-1;c++)
        {
            int h=br[c+i]+c+1;
            cout<<setw(3)<<h;
        }
        cout<<endl;
    }
    }
    else
    {
        cout <<"Only odd numbers are allowed!" << endl;
    }
    return 0;
}