#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

#define N 4  //N nodes

float DataBase[N][N] = {




};

float LengthDataBase[N+1][(1<<(N-1))-1] = {{0}};//[startpalce][visitplace]

float minlength(int start,int visit){
    float MIN = FLT_MAX;
    for(int i = 0; i < )

}

stack<int> SavenumberPlace;
bool used[N] = {false};

void slove(int startnode, int quantity){

    if(SavenumberPlace.size() == quantity){
        int visitedplace = 0;
        for(int i = 0; i < quantity; i++){
            visitedplace += (1<<SavenumberPlace.top());
            SavenumberPlace.pop();
        }
        LengthDataBase[startnode][SavenumberPlace] = minlenght(startnode,SavenumberPlace);
    }
    else{
        for(int i = 1; i <= N; i++){
            if(!used[i-1]){
                used[i-1] = true;
                SavenumberPlace.push(i);
                slove(startnode,quantity);
                used[i-1] = false;
            }
        }
    }

}

int main()
{
    for(int i = 1; i <= N; i++){
        LengthDataBase[i][1] = DataBase[i][0];
    }
    for(int startnode = 1; startnode <= N; startnode++){
        for(int quantity = 1; quantity <=N; quantity++){
            slove(startnode, quantity);
        }
    }


return 0;
}
