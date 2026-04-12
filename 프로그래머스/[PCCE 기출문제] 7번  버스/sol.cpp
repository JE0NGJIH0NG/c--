#include <string>
#include <vector>
#include <iostream>
using namespace std;

int func1(int num){
    if(0>num){
        return 0;
    }
    else{
        return num;
    }
}

int func2(int num){
    if(num>0){
        return 0;
    }
    else{
        return num;
    }
}

int func3(vector<string> station){
    int num=0;
    for(int i=0 ; i<station.size();i++){
        if(station[i]=="Off"){
            num+=1;
        }
    }
    return num;
}

int func4(vector<string>station){
    int num=0;
    for(int i=0 ; i<station.size();i++){
        if(station[i]=="On"){
            num+=1;
        }
    }
    return num;
}

int solution(int seat , vector<vector<string>> passengers){
    int num_passenser=0;
    for(int i=0 ; i<passengers.size();i++){
        num_passenser-=func3(passengers[i]);
        num_passenser+=func4(passengers[i]);
    }
    int answer=func1(seat-num_passenser);

    return answer;
}

int main(void){
    int seat=5;
    vector<vector<string>>passengers={
        {"On",  "On", "On"},
        {"Off", "On", "-"},
        {"Off", "-",  "-"}        
    };
    cout<<solution(seat,passengers);
    return 0;
}