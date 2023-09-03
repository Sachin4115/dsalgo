#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> words,vector<int> farr,vector<int> score,int i){
    if(i==words.size())
        return 0;
    int sno = solution(words,farr,score,i+1);
    int sword=0;
    bool flag=true;
    for(int j=0;j<words[i].length();j++){
        if(farr[words[i][j]-'a']==0){
            flag = false;
        }
        farr[words[i][j]-'a']--;
        sword+=score[words[i][j]-'a'];
    }
    int syes=0;
    if(flag){
        syes = sword + solution(words,farr,score,i+1);
    }
    for(int j=0;j<words[i].length();j++){
        farr[words[i][j]-'a']++;
    }
    return max(sno,syes);
}

int main()
{
    int noofwords,noofletters,element;
    vector <string> words = {"dog","cat","dad","good"};
    vector <char> letters = {'a','b','c','d','d','d','g','o','o'};
    vector <int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    vector <int> farr(26,0);
    string word;
    char ch;
    // cin>>noofwords;
    // for(int i=0;i<noofwords;i++){
    //     cin>>word;
    //     words.push_back(word);
    // }
    // cin>>noofletters;
    // for(int i=0;i<noofletters;i++){
    //     cin>>ch;
    //     letters.push_back(ch);
    // }
    // for(int i=0;i<26;i++){
    //     cin>>element;
    //     score.push_back(element);
    // }
    for(char ch : letters){
        int i=ch-'a';
        farr[i]++;
    }
    cout<<solution(words,farr,score,0);
    return 0;
}