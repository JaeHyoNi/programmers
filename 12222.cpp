#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int test_case;
    int T;
    string str,temp="",it="";
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case){
        int N = 0;
        cin>>str;
        for(auto iter: str){
            it.push_back(iter);
            if(temp == it) continue;
            else{
                N++;
                temp = it;
                it="";
            }
        }
        cout<<"#"<<test_case<<" "<<N<<endl;
        str = "";
    }
    return 0;
}