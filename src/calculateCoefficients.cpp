#include "calculateCoefficients.h"
#include <iostream>

using namespace std;

void calculateRecursively(int a,int b,int count,int **memoize){
    if(b==0){
        return;
    }else{
        int q=a/b;
        int r=a%b;

        if(count == 0){
            memoize[count][0]=1;
            memoize[count][1]=-1*q;
            cout<<"Quetioent : "<<q<<", Rem : "<<r<<endl;
            cout<<memoize[count][0]<<endl;
            cout<<memoize[count][1]<<endl;
            count++;
        }else if(count==1){
            memoize[count][0]=-1*q;
            //cout<<memoize[count][1]<<endl;
            memoize[count][1]=1+(-1)*q*memoize[count-1][1];
            cout<<"Quetioent : "<<q<<", Rem : "<<r<<endl;
            cout<<memoize[count][0]<<endl;
            cout<<memoize[count][1]<<endl;
            count++;
        }else{
            memoize[count][0]=memoize[count-1][0]*q*-1+memoize[count-2][0];
            memoize[count][1]=memoize[count-1][1]*q*-1+memoize[count-2][1];
            cout<<"Quetioent : "<<q<<", Rem : "<<r<<endl;
            cout<<memoize[count][0]<<endl;
            cout<<memoize[count][1]<<endl;
            count++;
        }
        return calculateRecursively(b,r,count,memoize);
    }
}

/** @brief calculateCoefficients
  *
  * @todo: document this function
  */
void calculateCoefficients(int a, int b)
{
    int **mem;
    mem=new int*[100];
    for(int i=0;i<100;i++){
        mem[i]=new int[2];
    }
    calculateRecursively(a,b,0,mem);
    for(int i=0;i<100;i++){
        for(int j=0;j<2;j++){
            cout<<mem[i][j]<<",";
        }
        cout<<endl;
    }
}
