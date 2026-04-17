#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int a , int b);
int main(void){
    int a=9;
    int b=91;
    cout<<solution(a,b);
    return 0;

}
int solution( int a , int b){
    string s_a = to_string(a);
    string s_b = to_string(b);
    string rst1 = s_a+s_b;
    string rst2 = s_b+s_a;
    if ( stoi(rst1) >= stoi(rst2)){
        return stoi(rst1);
    }
    else{
        return stoi(rst2);
    }
    
}