#include <bits/stdc++.h>
using namespace std;
void water(int ar[],int n) {
    int ans = INT_MIN;
    int ai = -1, aj = -1;
    int i = 0, j = n - 1;

    while (i < j) {
        int currentMin = min(ar[i], ar[j]);
        if (currentMin > ans) {
            ans = currentMin;
            ai = i;
            aj = j;
        }
        if (ar[i] < ar[j]) {
            i++;
        } else {
            j--;
        }
    }
    
    cout << ai << " " << aj << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        water(ar,n);
    }
    return 0;
}