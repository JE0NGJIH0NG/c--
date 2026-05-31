#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution( vector<int> arr );

int main(void){
    vector<int> arr = {4,3,2,1};
    arr = solution(arr);
    cout<<arr.size();
    return 0;
}

vector<int> solution( vector<int> arr ){
    if(arr.size()==1){
        vector<int> tmp = {-1};
        return tmp;
    }
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end() );
    arr.erase( remove( arr.begin() , arr.end() , sorted[0] ) );
    return arr;
}