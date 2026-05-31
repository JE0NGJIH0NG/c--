#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int>arr){
    int tmp = -1;
    vector<int> answer;
    for( int x : arr){
        if( tmp == x){
            continue;
        }
        else{
            answer.push_back(x);
            tmp = x;
        }
    }
    return answer;
}