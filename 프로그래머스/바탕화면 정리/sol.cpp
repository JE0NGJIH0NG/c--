#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution( vector<string> wallpaper );
int main(void){
    vector<string> wallpaper={".#...", "..#..", "...#."};
    solution(wallpaper);
    return 0;
}
vector<int> solution( vector<string> wallpaper ){
    vector<int> answer;
    int lux = 51;
    int luy = 51;
    int rux = 0;
    int ruy = 0;

    for( int i=0 ; i<wallpaper.size() ; i++ ){
        for( int j=0 ; j<wallpaper[i].size() ; j++){
            if(wallpaper[i][j] == '#'){
                if(lux>i){
                    lux=i;
                }
                if(luy>j){
                    luy=j;
                }
                if(rux < (i+1)){
                    rux=i+1;
                }
                if( ruy < (j+1)){
                    ruy=j+1;
                }
            }
        }
    }

    answer={lux,luy,rux,ruy};
    cout<< lux << " , " << luy << " , " << rux << " , "<< ruy <<endl;
    return  answer;
}