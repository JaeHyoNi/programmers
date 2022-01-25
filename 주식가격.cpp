#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    int visit[10001] = {0,};
    int prices_size = prices.size();
    stack<pair<int,int>> stuck;
    for(int i=0;i<prices.size();i++){
        if(stuck.empty()){
            stuck.push({prices[i],i});
        }
        else{
            while(stuck.top().first >prices[i]){
                answer[stuck.top().second] = i-stuck.top().second;
                stuck.pop();
                if(stuck.empty()) break;
            }
            stuck.push({prices[i],i});
        }
    }
    if(!stuck.empty()){
        int tmp = stuck.top().second;
        stuck.pop();
        while(!stuck.empty()){
            answer[stuck.top().second] = tmp - stuck.top().second;
            stuck.pop();
        }
    }
    for(auto K:answer){
        cout<<K<<" ";
    }
    return answer;
}


int main(void){
    solution({10,9,8,7,6,5,4,3,2,1});
}
