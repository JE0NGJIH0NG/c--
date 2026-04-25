#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution( vector<vector<int>> sizes);
vector<vector<int>> getReverse( vector<vector<int>> sizes );
pair<int , int> getMaxWidth( vector<vector<int>> input);

int main(void){

}

vector<vector<int>> getReverse( vector<vector<int>> sizes ){
    vector<vector<int>> rtn;
    rtn.reserve(sizes.size());
    for( vector<int> x : sizes ){
        vector<int> tmp{
            x[1] , x[0]
        };
        rtn.push_back(tmp);
    }
    return rtn;
}

pair<int , int> getMaxWidth( vector<vector<int>> input){
    int max = -1;
    int max_width = -1;
    for( vector<int> x : input){
        if( max < x[0]){
            max=x[0];
            max_width=x[1];
        }
        else if( max == x[0]){
            if( max_width < x[1] ){
                max_width = x[1];
            }
        }
    }
    return {max , max_width};
}
// 1-1. 가로 기준으로 가장 긴 거를 구하고 저장한다.
// 1-2. 가장 긴 가로 길이의 세로를 저장한다. 
// 1-3-1. 가장 긴 가로의 명함을 제외하고, 나머지를 순회한다.
// 1-3-2. 순회 대상 명함의 세로가 작으면 pass
// 1-3-3. 순회 대상 명함의 세로가 더 길다면, 해당 세로를 저장. 
// 1-3-4. 순회 대상의 가로 세로를 바꾸어서 검사.
int solution( vector<vector<int>> sizes){
    vector<vector<int>> sizes_reverse = getReverse(sizes);
    sizes.insert(sizes.end() , sizes_reverse.begin() , sizes_reverse.end() );
    auto [max_width , max_hight ]= getMaxWidth(sizes);
    
    for( vector<int> x : sizes ){
        if( x[1] > max_hight){
            if( x[0] > max_hight){
                max_hight = (x[0]<x[1])?x[0]:x[1];
            }
        }
    }
    return max_width * max_hight;

}