#include <iostream>
#include <vector>
using namespace std;

string solution(string my_string , string overwrite_string , int s);
int main(void){
    string my_string="He11oWor1d";
    string overwrite_string="lloWorl";
    int n=2;
    cout<<solution(my_string,overwrite_string,n);
    return 0;
}

string solution(string my_string , string overwrite_string , int s){
    string answer="";
    answer.append(my_string.substr(0,s));
    answer.append(overwrite_string);
    answer.append(my_string.substr(s+overwrite_string.size(),-1));
    return answer;
}