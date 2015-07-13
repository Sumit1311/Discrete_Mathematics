#include <iostream>
#include "infinitePrimes.h"
#include "towerOfHanoiUsingFour.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    cout<<smallestNumberWithNoPrime()<<endl;
    cout<<buildTowerOfHanoi(8,0,1,2,3);
    return 0;
}
