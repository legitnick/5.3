#include<iostream>
#include <fstream>
#include <math.h> 
using namespace std;
void delete2D(int** a,int rowCount){
    for (int i = 0; i < rowCount; i++)
{
    delete[] a[i];
}
delete[] a;
}
struct Link
{
    double data;
    Link *next;
};

int **readFromFile(const char *fileName, int &count,const int& n)
{
    Link *first = 0;
    Link *last = 0;
    Link *link;
    ifstream in(fileName);
    int d;
    count = 0;
    while (in >> d)
    {
        count++;
        link = new Link;
        link->data = d;
        cout<<"new link with "<<d<<endl;
        link->next = 0;
        if (last == 0)
        {
            first = last = link;
        }
        else
        {
            last->next = link;
        }
        last = link;
    }
    int rowCount = ceil(count/n);
        cout<<rowCount<<endl;
     int** a = new int*[rowCount];
 
    for (int i = 0; i < rowCount+1; i++) {
        a[i] = new int[n];
    }
    link = first;
    for (int i = 0; i <1+ rowCount; i++)
    {
        for(int j = 0;j<n;j++){
            if(i*n+j>=count){a[i][j]=0; cout<<"a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl;}
            else{
            a[i][j] = link->data;
            cout<<"a["<<i<<"]["<<j<<"] = "<<a[i][j]<<endl;
            link = link->next;
                }
        }
    }
    
    while (first)
    {
        link = first;
        first = first->next;
        delete link;
    }
    return a;
}

void outToFile(const char *filename, double *arr, int count,const int n)
{

    int rowCount = ceil((double)count/(double)n);
    ofstream out(filename);
    cout<<rowCount<<n<<count;
     for (int i = 0; i < rowCount; i++)
    {
       out<<arr[i]<<" ";
    }
}
double* individual(int** a,int count, const int n){
    int rowCount = ceil(count/n);
        
     double* arr = new double[rowCount];
    for (int i = 0; i <1+ rowCount; i++)
    {
        int max = 0;
        for(int j = 0;j<n;j++){
            if(a[i][j]>max)max = a[i][j];
        }
         arr[i]=log(max);
    }
    return arr;
}

int main()
{
    const int n = 8;//column count
    int count = 0;
    int **arr = readFromFile("data.txt", count,n);
    double* a = individual(arr,count,n);
    outToFile("results.txt", a, count,n);r
    delete2D(arr,ceil(count/n));
    delete[] a;
    system("pause");
    return 0;
}
