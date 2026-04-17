#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> arr);

int main(void){
    vector<string> arr = {
        "a","b","c"	
    };
    cout << solution(arr);
    return 0;
}

string solution(vector<string> arr){
    string answer="";
    for( int i=0 ; i<arr.size() ; i++){
        answer.append(arr[i]);
    }
    return answer;
}