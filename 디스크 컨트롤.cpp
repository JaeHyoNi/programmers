#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0,now=0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> task ;
    auto iter = jobs.begin();
    while(iter!=jobs.end() || !task.empty()){
        while((iter!=jobs.end() && (*iter)[0] <= now) || task.empty()){
            task.push({(*iter)[1],(*iter)[0]});
            iter++;
        }
        if(now < task.top().second) now = task.top().second; 
        answer += (now - task.top().second + task.top().first);
        now += task.top().first;
        task.pop(); 
    }
    return answer = answer/jobs.size();
}
