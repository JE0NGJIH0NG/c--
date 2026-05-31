#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution( vector<int> arr , vector<vector<int>> commands ){
    vector<int> answer;
    for( vector<int> part : commands ){
        int start = part[0]-1;
        int end = part[1];
        int idx = part[2]-1;
        vector<int> tmp( arr.begin()+start , arr.begin()+end );
        sort( tmp.begin() , tmp.end());
        answer.push_back(tmp[idx]);
    }
    return answer;
}