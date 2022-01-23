#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<bool> net;
vector<vector<int>> temp;
int N = 0;

void dfs(int k){
    queue<int> tmp;
    net[k] = true;
    for(int i = 0; i< N;i++ ){
        if(temp[k][i] == 1 && net[i] == false && i!=k )    tmp.push(i);
    }
    while(!tmp.empty()){
        dfs(tmp.front());
        tmp.pop();
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    temp = computers;
    for(int i=0;i<n;i++)    net.push_back(false);
    for(int i=0;i<n;i++){
        if(net[i] == false){
            dfs(i);
            answer++;
        }
    }
    return answer;
}

int main(void){
    cout<< solution(3,{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});
    return 0;
}
