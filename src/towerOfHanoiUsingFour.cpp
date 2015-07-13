#include "towerOfHanoiUsingFour.h"
#include <iostream>

using namespace std;


/*int moveDisc(st from, st to){
    if(to.size() == 0 && from.size() ){
        cout<<"moving from "<<from<<"---- > "<<to;
        to.push_back(from[from.size() - 1]);
        from.pop_back();
        return 1;
    }else{
        if((int)(to[to.size()-1]) < (int)(from[from.size()-1])){
            cout<<"Can't move from "<<from<<" --- > "<<to;
            return -1;
        }else{
            cout<<"moving from "<<from<<"---- > "<<to;
            to.push_back(from[from.size() - 1]);
            from.pop_back();
            return 1;
        }
    }
}*/

/** @brief buildTowerOfHanoi
  *
  * @todo: document this function
  */
int buildTowerOfHanoi(int numberOfDiscs, int from, int to, int using1, int using2)
{
    if(numberOfDiscs==1){
        cout<<"Move disc "<<from<<" ----- >"<<to<<endl;
    }else{
        buildTowerOfHanoi(numberOfDiscs/2,from,using1,to,using2);
        buildTowerOfHanoi(numberOfDiscs/2,from,to,using2,using1);
        buildTowerOfHanoi(numberOfDiscs/2,using1,to,from,using2);

    }
}

