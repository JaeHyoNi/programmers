
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

bool visit[8],vvisit[10000000];
vector<int> ans;
string number,temp;
bool isprime(int num){
    if(num==1 || num == 0) return false;
    if(num == 2) return true;
    int t = sqrt(num);
    for(int i=2;i<t+1;i++){if(num % i == 0)  return false;}
    return true;
}

void dfs(int dep){
    if(dep == number.size()+1) return;
    int i = 0,tmp;
    for(auto K:number){
        if(visit[i] == false) {
            visit[i] = true;
            temp.push_back(number[i]);
            tmp = stoi(temp);
            if(isprime(tmp)){
                if(vvisit[tmp]== false){
                    vvisit[tmp] = true;
                    ans.push_back(tmp);
                }
            }
            dfs(dep+1);
            visit[i] = false;
            temp.pop_back();
        }
        i++;
    }
}

int solution(string numbers) {
    int answer = 0;
    number = numbers;
    dfs(0);
    answer = ans.size();
    return answer;
}
