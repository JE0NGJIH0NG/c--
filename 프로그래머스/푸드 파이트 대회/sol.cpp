#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution( vector<int> food );
int main(void){
    vector<int> food = {1,3,4,6};
    string ans = solution(food);
    cout<<ans;
    return 0;
}
string solution( vector<int> food){
    string answer="";
    for( int i=1 ; i<food.size() ; i++){
        if( food[i]==1){
            continue;
        }
        int mount = food[i]/2;
        answer.append(mount , i+48 );
    }
    string reversed = answer;
    reverse(reversed.begin() , reversed.end());
    return answer+'0'+reversed;
}