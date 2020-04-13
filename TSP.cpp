#include <iostream>
#include <float.h>
using namespace std;
#define N 4  //N nodes

float MAP[N][N] = {




};
float SavePlace[N][(1<<N)-1] = {{0}};
float FindMinLength(int Start,int SumVisit){
    float MIN = FLT_MAX;
    int now = 0,sum = SumVisit;
    while(sum != 0){
        if(sum & 1){
            MIN = min(MIN,MAP[Start][now]+SavePlace[now][SumVisit-(1<<now)]);
        }
        SumVisit >>= 1;
        now++;
    }
    return MIN;
}
void BFS(int StartNode, int NodeQuantity ,int VisitNodeCount, int SumVisiNode, int NowVisit){

    if(NodeQuantity == VisitNodeCount)
        SavePlace[StartNode][SumVisiNode] = FindMinLength(StartNode,SumVisiNode);
    else if(NodeQuantity == VisitNodeCount && CountPlace <= N){
        if(CountPlace != StartNode){
            BFS(StartNode, NodeQuantity, VisitNodeCount, SumVisiNode, NowVisit)++);
            BFS(StartNode, NodeQuantity, VisitNodeCount++, SumVisiNode += (1<<NowVisit)), NowVisit)++);
        }
    }
    else
        return;
}
int main()
{
    for(int i = 1; i <= N; i++){
        SavePlace[i][0] = MAP[i][0];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= N; j++){
            BFS(j,i,0,0,1);
        }
    }
    int MIN = FLT_MAX:
    for(int i = 1; i <= N; i++)
        MIN = min(MIN,MAP[0][i] + ((1<<N)-1) - (1<<i));
    cout<<MIN<<endl;
    int fin = (1<<N) - 1,road = 0;
    for(int i = 1; i <= N; i++){
        int Min = FLT_MAX:
        for(int j = 1; j <= N; j++){
            if((fin & j) && (Min <= Map[road][j] + SavePlace[j][fin-(1<<j)])){
                road = j;
                fin -= (1<<j);
                cout<<road<<" ";
            }
        }
    }
return 0;
}
