#include <iostream>
#include <stack>
#include <float.h>
using namespace std;

#define N 18

float DataBase[N][N] = {
{0, 0.6, 1.3, 0.23, 0.75, 0.8, 1.2, 3.7, 3.4, 1.6, 0.4, 1.8, 2.3, 1.3, 1.9, 1.8, 3.2, 1.4},
{0.6, 0, 1.9, 0.85, 1.3, 1.4, 1.4, 4.2, 4.1, 1.5, 0.55, 2.8, 3, 0.9, 2.9, 2.8, 4.2, 1.3},
{1.3, 1.9, 0, 1.1, 0.7, 0.65, 1.1, 2.3, 2.3, 1.2, 1.4, 1.1, 1, 2.5, 1.4, 1.1, 2.2, 1.8},
{0.23, 0.8, 1.1, 0, 0.75, 0.8, 1, 3.4, 3.2, 1, 0.6, 1.6, 2, 1.6, 1.7, 1.6, 3, 1.7},
{0.75, 1.3, 0.7, 0.75, 0, 0.05, 1.2, 2.9, 2.8, 1.4, 0.8, 1.9, 2.1, 2.1, 1.9, 1.9, 2.8, 1},
{0.8, 1.4, 0.65, 0.8, 0.05, 0, 1.2, 2.9, 2.7, 1.3, 0.85, 1.8, 1.6, 2.1, 1.9, 1.9, 2.8, 1},
{1.2, 1.4, 1.1, 1, 1.2, 1.2, 0, 2.7, 2.7, 1.3, 1.5, 1.6, 1.2, 4.2, 2.2, 1.7, 1.9,  3.7},
{3.7, 4.2, 2.3, 3.4, 2.9, 2.9, 2.7, 0, 0.55, 2.6, 3.8, 1.6, 1.3, 4.2, 2.2, 1.7, 1.9, 3.7},
{3.4, 4.1, 2.4, 3.2, 2.8, 2.7, 2.7, 0.55, 0, 2.1, 3.7, 1.5, 1.1, 4.1, 2, 1.5, 2, 3.5},
{1.3, 1.5, 1.2, 1, 1.4, 1.3, 1.3, 2.6, 2.1, 0, 1.8, 1.1, 1.6, 2, 1.1, 1.1, 2.5, 1.6},
{0.4, 0.55, 1.4, 0.6, 0.8, 0.85, 1.5, 3.8, 3.7, 1.8, 0, 2.2, 2.5, 1.3, 2.3, 2.2, 3.6, 1},
{1.8, 2.8, 1.1, 1.6, 1.9, 1.8, 1.6, 1.6, 1.5, 1.1, 2.2, 0, 0.95, 2.8, 0.5, 0.02, 1.9, 2.8},
{2.3, 3, 1, 2, 2.1, 1.6, 1.2, 1.3, 1.1, 1.6, 2.5, 0.95, 0, 3.2, 1, 0.5, 1.2, 2.6},
{1.3, 0.9, 2.5, 1.6, 2.1, 2.1, 4.2, 4.2, 4.1, 2, 1.3, 2.8, 3.2, 0, 2.8, 2.7, 3.8, 2.1},
{1.9, 2.9, 1.4, 1.7, 1.9, 1.9, 2.1, 2.2, 2, 1.1, 2.3, 0.5, 1, 2.8, 0, 0.55, 1.3, 2.9},
{1.8, 2.8, 1.1, 1.6, 1.9, 1.9, 1.6, 1.7, 1.5, 1.1, 2.2, 0.02, 0.5, 2.7, 0.55, 0, 1.7, 2.8},
{3.2, 4.2, 2.2, 3, 2.8, 2.8, 2, 1.9, 2, 2.5, 3.6, 1.9, 1.2, 3.8, 1.3, 1.8, 0, 3.8},
{1.4, 1.3, 1.8, 1.7, 0.95, 1, 3.6, 3.7, 3.5, 2.6, 1, 2.8, 2.6, 2.1, 2.9, 2.8, 3.8, 0}
};

float LengthDataBase[N][ 1<<N-1 ] = {{0}};//[startpalce][visitplace]

float minlength(int startnode, int visitedplace){
    float MIN = FLT_MAX;
    for(int i = 1; i < N; i++){
        if(i != startnode && (visitedplace & i<<i) ){
            MIN = min(MIN , DataBase[startnode][i] + LengthDataBase[i][visitedplace - i<<i]);
        }
    }
    return MIN;
}

stack<int> ThroughPlaceNumber;
bool UsedNumber[N] = {false};

void slove(int startnode, int quantity){
    if(ThroughPlaceNumber.size() == quantity){
        int X10VisitedPlace = 1;
        for(int i = 0; i < quantity; i++){
            X10VisitedPlace += 1<<ThroughPlaceNumber.top();
            ThroughPlaceNumber.pop();
        }
        cout<<" "<<X10VisitedPlace<<endl;
        LengthDataBase[startnode][X10VisitedPlace] = minlength(startnode, X10VisitedPlace);
    }
    //when find enough place turn list to 2X number and turn to 10X number

    else{
        for(int i = 1; i < N; i++){
            if(!UsedNumber[i]){
                cout<<i;
                UsedNumber[i] = true;
                ThroughPlaceNumber.push(i);
                slove(startnode,quantity);
                UsedNumber[i] = false;
            }
        }
    }
    //if it doesn't have enough place, continue to find new place by BFS
}

int main()
{
    UsedNumber[0] = true;
    for(int i = 1; i < N; i++){
        LengthDataBase[i][ 1<<0 ] = DataBase[i][0];
    }
    //from node-i go trough node-0

    for(int startnode = 1; startnode < N; startnode++){
        for(int quantity = 1; quantity < N-1; quantity++){
            cout<<startnode<<" "<<quantity<<endl;
            UsedNumber[startnode] = true;
            slove(startnode, quantity);
            UsedNumber[startnode] = false;
        }
    }
    //from start-node go trough quantity-node and find shortest road

    float ANS = FLT_MAX;
    for(int i = 1; i < N; i++){
        ANS = min(ANS, DataBase[i][0] + LengthDataBase[i][(1<<N - 1) - (1<<i)] );
    }
    cout<<"MIN_ROAD = "<<ANS<<endl;
    //find min road complete

    int n = 1<<N - 1;
    cout<<"0-";
    for(int i = 1; i < N; i++){
        int MIN = FLT_MAX, x;
        for(int j = 1; j < N; j++){
            if( (n & 1<<j) && MIN >= LengthDataBase[j][n - 1<<j]){
                MIN = LengthDataBase[j][n - 1<<j];
                x = j;

            }
            n -= 1<<x;
            cout<<x<<"-";
        }
    }
    //find min road
}
