#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution( int n );

int main(void){
    int n=4;
    string ans = solution(n);
    cout<<ans<<endl;
    return 0;
}

string solution(int n){
    string answer="";
    for( int i=1 ; i<=n ; i++ )
    {
    if(i%2==1){
        answer.append("su");
    }
    else{
        answer.append("bak");
    }
    }
    return answer;
}