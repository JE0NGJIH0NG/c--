#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

string erase(string input , int start , int end );
string erase_words(string input, int start , int end);
set<string> stringToSet(string input);
int solution( string message , vector<vector<int>> spoiler_ranges );
int main(void){
    //string msg = "here is muzi here is a secret message";
    string msg="myy phone number is 01012345678 and may i have your phone number";
//    vector<vector<int>> spoilers= {{0,3},{23,28}};
    vector<vector<int>> spoilers ={
        {1,1},{25,28},{34,40},{53,59}
    };
    cout<<solution(msg,spoilers)<<endl;
    return 0;
}

string erase(string input , int start , int end ){
    string x = input;
    for( int i=start ; i<=end ; i++){
        if(x[i]!=' '){
            x[i] = '-';
        }
    }
    return x; 
}
string erase_words(string input, int start , int end){
    string x = input;
    int start_num = start;
    int end_num = end;
    // start지점에 대한 처리
    while(true){
        if( (start==0) || (start_num==0 )){
            break;
        }
        if( (x[start_num-1]==' ') || (x[start_num]==' ') ){
            break;
        }
        if(x[start_num-1]!=' '){
            x[start_num-1]='-';
            start_num-=1;
            continue;
        }
        break;
    }
    // end지점에 대한 처리
    while(true){
        if(end_num== ( input.size()-1)){
            break;
        }
        if( (x[end_num+1]==' ') || (x[end_num]==' ') ){
            break;
        }
        if(x[end_num+1]!=' '){
            x[end_num+1]='-';
            end_num+=1;
            continue;
        }
        break;
    }
    return x;
}

// 1.string을 순회하면서 tmp에 넣어두기
// 2. 만약 공백을 만나면, i++만 하고 다음 반복.
set<string> stringToSet(string input){
    set<string> rtn;
    string tmp="";
    int i=0;
    while( i<input.size() ){
        if(input[i]!=' '){
            tmp+=input[i];
            i+=1;
            if( (i)==input.size()){
               // tmp+=input[i];
             //   cout<<"insert string is "<<tmp<<"."<<endl;
                rtn.insert(tmp);
                tmp="";
                break;
            }
            continue;
        }
        else{
            i+=1;
            if( (tmp != "") && (tmp!=" ")){
                rtn.insert(tmp);
            }
            tmp="";
        }
    }
    return rtn;
}
// 1. message에서 일치하는 구간을 공백으로 지워
// 2. 지우고 난 문자열에서, spolier를 기준으로 앞뒤에 알파벳이면 쭉 공백으로 
// 1과 2를 거치면, 가려진 문자열을 얻을 수 있음 
// 3. 원본 문자열 set으로 저장
// 4. 지운 문자열 set으로 저장
// 5. 원본set - 지운set 
int solution( string message , vector<vector<int>> spoiler_ranges ){
    string erased_msg = message;
    set<string> originSet;
    set<string> erasedSet;
    for( vector<int> sub_spoiler_ranges : spoiler_ranges ){
        erased_msg = erase( erased_msg , sub_spoiler_ranges[0] , sub_spoiler_ranges[1]);
      //  cout<<erased_msg<<endl;
        erased_msg = erase_words( erased_msg , sub_spoiler_ranges[0] , sub_spoiler_ranges[1]);
      //  cout<<erased_msg<<endl;
    }

    erased_msg.erase( remove(erased_msg.begin() , erased_msg.end() , '-') , erased_msg.end() );
    cout<<erased_msg<<endl;

    originSet = stringToSet(message);
    erasedSet = stringToSet(erased_msg);
    cout<<"here "<<originSet.size()<<endl;
    for( string x : originSet ){
        cout<< x <<" ";
    }
    cout<<endl<<"here "<<erasedSet.size()<<endl;
    for( string x : erasedSet ){
        cout<< x <<" ";
    }
    cout<<endl;
    return originSet.size()-erasedSet.size();
}