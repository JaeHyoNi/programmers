#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector<string> ans;
map< string, int > flag;
int siz;
bool success = false;
vector<queue<string>> temp;

bool dfs(string str) {
    ans.push_back(str);
    if (temp[flag[str]].empty() || flag[str] == 0) {
        if (ans.size() == siz + 1) { success = true;  return true; }
        else {
            ans.pop_back();
            return false;
        }
    }
    int s = temp[flag[str]].size();
    for (int i = 0; i < s; i++) {
        string t = temp[flag[str]].front();
        temp[flag[str]].pop();
        if (dfs(t))  break;
        else        temp[flag[str]].push(t);
    }
    if (!success) { ans.pop_back(); return false; }
    if (success) return true;;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    string tmp = tickets[0][0];
    siz = tickets.size();
    int iter = 1;
    queue<string> emp;
    flag[tickets[0][0]] = iter;
    temp.push_back(emp);
    temp.push_back(emp);
    for (int i = 0; i < siz; i++) {
        if (tmp != tickets[i][0]) {
            flag[tickets[i][0]] = ++iter;
            temp.push_back(emp);
            tmp = tickets[i][0];
        }
        temp[iter].push(tickets[i][1]);
    }
    dfs("ICN");
    vector<string> answer = ans;
    return answer;
}

int main(void) {
    vector<vector<string>> ticket = {{"ICN", "A"}, {"ICN", "B"}, {"B", "ICN"} };
    for (auto K : solution(ticket)) { cout << K << " -> "; }
    return 0;
}