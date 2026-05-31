#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string slution( string s ){
    sort(s.begin() ,s.end() , greater<int>());
}