#include <iostream>
#include <vector>
#include <float.h>
#include <fstream>
#include <sstream>
#define N 18
using namespace std;

vector< vector< float > > graph = { N, vector< float >( N, -1 ) };
vector< vector< float > > dp = { ( 1 << N ), vector< float >( N, -1 ) };

float TSP( int visit, int now ) {
	if ( dp[ visit ][ now ] != -1 )
		return dp[ visit ][ now ];
	dp[ visit ][ now ] = FLT_MAX;
	for ( int i = 0; i < N; i++ )
		if ( i != now && ( visit & ( 1 << i ) ) )
			dp[ visit ][ now ] = min( dp[ visit ][ now ], TSP( visit - ( 1 << now ), i ) + graph[ now ][ i ] );
	return dp[ visit ][ now ];
}

int main() {
    ifstream infile;
    infile.open("route.txt");
    float t;
    string s;
    istringstream iss;
    for(int i = 0; i < N; i++){
        getline(infile, s);
        iss.clear();
        iss.str(s);
        for(int j = 0; j < N; j++){
            iss >> t;
            graph[i][j] = t;
        }
    }
    infile.close();

	for ( int i = 0; i < N; i++ )
		dp[ 1 << i ][ i ] = graph[ 0 ][ i ];
	cout<< TSP( ( 1 << N ) - 1, 0 ) << endl;

	int X = 0, XN, route = ( 1 << N ) - 1;
    for ( int i = 0; i < N; i++ ){
        float MIN = FLT_MAX;
        for ( int j = 0; j < N; j++ ){
            if( X != j && ( route & ( 1 << j ) ) && ( MIN >= dp[ route - ( 1 << X ) ][ j ] + graph[ X ][ j ] ) ){
                MIN = dp[ route - ( 1 << X ) ][ j ] + graph[ X ][ j ];
                XN = j;
            }
        }
        cout<< X <<" ";
        route -= (1<<X);
        X = XN;
    }

	return 0;
}
