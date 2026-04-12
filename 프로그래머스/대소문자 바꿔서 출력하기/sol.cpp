#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str;
    cin >> str;;
    for(int i=0 ; i<str.size() ; i++){
        if ( 'A'<= str[i] && str[i]<='Z'){
            cout<<(char)tolower(str[i]);
        }
        else{
            cout<<(char)toupper(str[i]);
        }
    }
    return 0;
}