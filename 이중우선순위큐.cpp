#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> task;
    char sw;
    int tmp,start = 0;
    for(auto K:operations){
        sw = K[0];
        tmp = stoi(K.substr(2));
        if(K[0] == 'I') {
            task.push_back(tmp);
            sort(task.begin(),task.end());
            for(int i=0;i<start;i++){task.pop_back();}
            start = 0;
        }
        else{
            if(K[2] == '1'){if(!task.empty()) task.pop_back();}
            else{
                if(task.size()>start){
                    task[start] = 210000000;
                    start++;
                }
            }
        }
    }
    if(task.empty()){
        return {0,0};
    }
    sort(task.begin(),task.end());
    for(int i=0;i<start;i++){task.pop_back();}
    return {task.back(),task[0]};
}
