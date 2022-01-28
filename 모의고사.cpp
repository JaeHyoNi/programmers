#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer = {0,0,0},ans;
    vector<int> supo1 = {1,2,3,4,5} , supo2 = {2,1,2,3,2,4,2,5} , supo3 = {3,3,1,1,2,2,4,4,5,5};
    auto iter1 = supo1.begin() , iter2 = supo2.begin(), iter3 = supo3.begin();
    for(auto K:answers){
        printf("iter1 = %d  iter2 = %d  iter3 = %d\n",*iter1 , *iter2 , *iter3);
        if(*iter1 == K) answer[0]++;
        if(*iter2 == K) answer[1]++;
        if(*iter3 == K) answer[2]++;
        iter1++;iter2++;iter3++;
        if(iter1 == supo1.end()) iter1 = supo1.begin();
        if(iter2 == supo2.end()) iter2 = supo2.begin();
        if(iter2 == supo3.end()) iter3 = supo3.begin();
    }
    int max = *max_element(answer.begin(),answer.end());
    for(int i=0;i<3;i++){if(answer[i]==max) ans.push_back(i+1);}
    return ans;
}
