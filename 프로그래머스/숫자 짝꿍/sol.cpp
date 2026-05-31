#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution( string X , string Y);

int main(void){
    string X = "100";
    string Y = "203045";
    string rst = solution(X,Y);
    cout<<rst;
    return 0;
}

string solution( string X , string Y){
    map<int,int> numbers_X;
    map<int,int> numbers_Y;
    map<int,int> numbers_subSet;
    string ans="";
    for( int i=0 ; i<X.size() ; i++){
        int tmp = X[i]-'0';
        numbers_X[tmp]++;
    }

    for( int i=0 ; i<Y.size() ; i++){
        int tmp = Y[i]-'0';
        numbers_Y[tmp]++;
    }

    for(int i=9 ; i>=0 ; i--){
        if( numbers_X.find(i) != numbers_X.end() ){
            if( numbers_Y.find(i) != numbers_Y.end()){
                int tmpX = numbers_X[i];
                int tmpY = numbers_Y[i];
                tmpX>tmpY ? numbers_subSet[i]=tmpY : numbers_subSet[i]=tmpX;
            }
        }
        cout<<numbers_subSet[i]<<"/"<<i<<endl;
        if( ( numbers_subSet[i])>0){
            for( int j=1 ; j<=numbers_subSet[i] ; j++ ){
                ans+=(i+'0');
                
            }
        }
    }

    if( (ans=="") ){
        return "-1";
    }
    else if(ans[0]=='0'){
        return "0";
    }

    return ans;
}

int x(string s) {
    int answer = 0;
    int x=1;
    int y=0;
    char start=s[0];
    for( int i=1 ; i<s.size() ; i++){
        if(s[i]==start){
            x+=1;
            continue;
        }
        else{
            y+=1;
            if(x==y){
                answer+=1;
                x=0;
                y=0;
            }
        }
    }
    
    return answer;
}