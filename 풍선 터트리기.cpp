#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int solution(vector<int> vec) {
    int answer;
    int N = vec.size();
    int max = 2100000000;
    vector<int> temp;
    for(int i=0;i<N;i++){
        if(vec[i]<max){
            temp.push_back(vec[i]);
            max = vec[i];
        }
    }
    max = 2100000000;
    for(int i=N-1;i>-1;i--){
        if(vec[i]<max){
            temp.push_back(vec[i]);
            max = vec[i];
        }
    }
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    answer = temp.size();
    cout<<answer;
    return answer;
}