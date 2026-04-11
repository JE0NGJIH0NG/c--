#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> solution(vector<string> cpr){
    vector<int> answer={0,0,0,0,0};
    vector<string> basic_order = {"check", "call", "pressure", "respiration", "repeat"};

    for(int i=0 ; i<answer.size() ; i++){
        for( int j=0 ; j<basic_order.size();j++){
            if(cpr[i]==basic_order[j]){
                answer[i]=j+1;
                break;
            }
        }
    }
    return answer;
}

int main(void){
    vector<string> in;
    in.push_back("call");
    in.push_back("respiration");
    in.push_back( "repeat");
    in.push_back("check" );
    in.push_back("pressure");
    vector<int> rst;
    rst = solution(in);
    for(int i=0 ; i<rst.size();i++){
        cout<<rst[i];
    }
    return 0;
}