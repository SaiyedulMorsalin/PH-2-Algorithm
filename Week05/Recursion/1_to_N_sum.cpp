#include <bits/stdc++.h>
using namespace std;
int sumN(int n){
    int sum;
    if(n ==1) return 1;
    else{
        sum =n+sumN(n-1);
    }
    
    

}
int main(){
    int n;
    cin>>n;
    cout<<sumN(n)<<endl;
    return 0;
}