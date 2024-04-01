#include <bits/stdc++.h>
using namespace std;
void walkHome(int src,int des){
    if(src == des){
        cout<<"Okay"<<endl;
        return;
    }
    walkHome(src+1,des);
}
int main(){
    int src,des;
    cin>>src>>des;
    walkHome(src,des);
    return 0;
}