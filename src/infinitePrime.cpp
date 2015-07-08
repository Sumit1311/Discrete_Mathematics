#include "infinitePrimes.h"

bool isPrime(int n) {
    int i=2;
    int isPrime=true;
    while(i<=n) {
        if(i == n) {
            break;
        } else {
            if(n%i == 0){
                isPrime=false;
                break;
            }else{
                i++;
            }
        }
    }
    return isPrime;
}

int smallestNumberWithNoPrime() {
    int euclidsProof=2;
    int i,count=1;
    for(i=3;;i++){
        if(isPrime(i)){
            euclidsProof*=i;
            count++;
            if(!isPrime(euclidsProof+1)){
                break;
            }
        }
    }
    return euclidsProof+1;
}
