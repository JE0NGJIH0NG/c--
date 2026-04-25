#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int solution( int n , vector<int> lost , vector<int> reserve );

int main(void){
    int n=5;
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};
    cout<<solution(n,lost,reserve);
    return 0;
}

// n은 전체 학생 수
// lost는 도난 당한 학생들의 번호
// reserve는 여벌 체육복 가져온 학생들 번호
int solution( int n , vector<int> lost , vector<int> reserve ){
    set<int> lost_set;
    set<int> reserve_set;
    for( int x : lost){
        lost_set.insert(x);
    }
    for( int x : reserve){
        reserve_set.insert(x);
    }
    for( int x : lost ){
        if( reserve_set.count(x) > 0 ){
            lost_set.erase(x);
            reserve_set.erase(x);
        }
    }

    for( int x : lost){
        if(lost_set.count(x)==0){
            continue;
        }
        if( reserve_set.count(x-1)){
            lost_set.erase(x);
            reserve_set.erase( x-1 );
        }
        else if( reserve_set.count(x+1)){
            lost_set.erase( x);
            reserve_set.erase(x+1 );
        }
    }
    return (n-lost_set.size());
}