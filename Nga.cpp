#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Nhap(int a[][100],int m,int n);
void Xuat(int a[][100],int m,int n);
int tinhtong(int a[][100],int m,int n);
void doicho(int a[][100],int m,int n);
int main(int argc, char** argv) {
	int a[100][100];
	int m,n;
	cout<<"Nhap so hang :";
	cin>>m;
	cout<<"Nhap so cot :";
	cin>>n;
	cout<<"Ma tran la : "<<endl;
	Nhap(a,m,n);
	Xuat(a,m,n);
	tinhtong(a,m,n);
	return 0;
}
void Nhap(int a[][100], int m, int n)
{
	int i, j;
    srand(time(NULL));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
        	int dau = rand()&1 ?  -1 : 1;
            a[i][j]= dau * rand()%99 +1;
            
        }
}
void Xuat(int a[][100], int m, int n)
{
	int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        cout<<a[i][j]<<setw(9);
        cout<<"\n";
    }
}
int tinhtong(int a[][100],int m,int n)
{
	int i,j,indexMinElem = 0, minElem = 0,indexMaxElem = 0, maxElem = 0;
    for (i = 0; i < m; i++)
    {
    	indexMaxElem = 0;           
        maxElem = a[i][indexMaxElem];
 
        indexMinElem = n-1;  
        minElem = a[i][indexMinElem];
 
       for (int j = 0; j < n; j++)
        {
            if (a[i][j] <= minElem)   
            {
                indexMinElem = j; 
				minElem = a[i][indexMinElem];   
            }
 
            if (a[i][j] >= maxElem)   
            {
                indexMaxElem = j;  
                maxElem = a[i][indexMaxElem];
            }	
        }
        //doi thanh 0 cac so o giua
        if(indexMaxElem > indexMinElem)
        {
        	for(int j = 0 ; j < n ; j++)
        	{
        		if(j < indexMaxElem && j > indexMinElem)
        		{
        			a[i][j] = 0;
				}
			}
		}
		if(indexMaxElem < indexMinElem)
        {
        	for(int j = 0 ; j < n ; j++)
        	{
        		if(j > indexMaxElem && j < indexMinElem)
        		{
        			a[i][j] = 0;
				}
			}
		}
    }
    cout<<"\nMa tran sau la :\n";
        for (i = 0; i < m; i++)
         {
            for (j = 0; j < n; j++)
            cout<<a[i][j]<<setw(9);
            cout<<"\n";
         }
}

