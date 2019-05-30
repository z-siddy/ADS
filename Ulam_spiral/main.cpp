// Ulam Spiral Visualization task for ADS lecture of Vilnius University
// By Žygimantas Sideravičius ISI
// For the best user experience, 9 is the critical row count for console output alignment!
#include <iostream>
#include <iomanip>

using namespace std;

bool isPrime(int n){
    int i;
    bool isPrime = true;

    for(i = 2; i <= n / 2; ++i)
    {
        if(n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        return true;
    else
        return false;

    return 0;
}

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
            if(isPrime(z+i-c+1))
            cout<<setw(3)<<z+i-c+1;
            else cout << setw(3) << "*";
        }
        cout<<setw(3)<<tl[i];
        int p=tl[i]-1;
        for(int j=0;j<n-2*i-1;j++)
        {
            if(isPrime(p))
            cout<<setw(3)<<p;
            else cout << setw(3) << "*";
            p--;
        }
        k-=2;
        for(int m=0;m<i;m++)
        {
            if(isPrime(tr[n/2-i+m]))
            cout<<setw(3)<<tr[n/2-i+m];
            else cout << setw(3) << "*";
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
            if(isPrime(bl[j]-x))
            cout<<setw(3)<<bl[j]-x;
            else cout << setw(3) << "*";
            x--;
        }
        for(int a=0;a<2*(i+1);a++)
        {
            bl[n/2-i-1]++;
            if(isPrime(bl[n/2-i-1]))
            cout<<setw(3)<<bl[n/2-i-1];
            else cout << setw(3) << "*";
        }
        for(int c=0;c<n/2-i-1;c++)
        {
            int h=br[c+i]+c+1;
            if(isPrime(h))
            cout<<setw(3)<<h;
            else cout << setw(3) << "*";
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