#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution( string code );
int main(void){
    string input = "abc1abc1abc";
    cout<<solution(input);
    return 0;
}
string solution(string code){
    int mode =0; // 0이면 짝수일때만 글자 추가. 1이면 홀수일때만 글자 추가
    string answer="";

    for( int i=0 ; i<code.size() ; i++){
        
        if((int)code[i]=='1' && mode==0){
            mode=1;

        }
        else if( (int)(code[i])=='1' && mode==1){
            mode=0;
        }
        else{
            if(mode==0 && i%2==0){
                answer.push_back(code[i]);
            }
            else if(mode ==1 && i%2==1){
                answer.push_back(code[i]);
            }
        }
    }
    if(answer.size()==0){
        return "EMPTY";
    }
    else{
        return answer;
    }
}