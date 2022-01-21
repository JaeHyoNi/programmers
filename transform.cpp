#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


vector<vector<int>> node;
vector<bool> visit;
int ssize,tar;
int Min = 999;
bool com(string a,string b){
    int n = a.size();
    int com = 1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) {
            com--;
            if(com<0)   return false;
        }
    }   
    return true;
}

void dfs(int n,int dep){
    if(n == tar){if(dep<Min){Min = dep;return;}}
    if(dep>=Min){return;}
    visit[n] = true;
    for(auto K:node[n]){if(visit[K] == false )  dfs(K,dep+1);}
    visit[n] = false;
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    ssize = words.size();
    bool is = true;
    for (int i=0;i<ssize;i++){
        if(target == words[i]){
            tar = i+1;
            is = false;
            break;
        }
    }
    if(is){return 0;}
    vector<int> temp;
    for(int i=0;i<ssize+1;i++)  {node.push_back(temp);visit.push_back(false);}
    for(int i=0;i<ssize;i++)    {if(com(begin,words[i]))    {node[0].push_back(i+1);}}
    for(int i=0; i<ssize;i++)   {for(int j=0;j<ssize;j++)   {if(com(words[i],words[j]) && i!=j) {node[i+1].push_back(j+1);}}}
    dfs(0,0);
    if(Min==999){Min = 0;}
    answer = Min;
    return answer;
}




int main(void){
    cout<<solution("hit","cog",{"hot", "dot", "dog", "lot", "log", "cog"});
    return 0;
}