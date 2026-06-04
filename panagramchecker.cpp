#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int flag=0;
    for(char ch: str){
        flag=flag|(1<<(ch-'a'));
    }
    if(flag==(1<<26)-1){
        cout<<"pangram";
    }
    else{
        cout<<"not pangram"; 
    }
}