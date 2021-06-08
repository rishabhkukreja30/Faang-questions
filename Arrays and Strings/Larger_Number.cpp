
#include <bits/stdc++.h>
using namespace std;

int form_num(int* arr,int s){
        int p = 0;
        int i=31;
        int ans = 0;
        if(32-s>=10)
            return -1;
        while(i>=s){
            int s = arr[i]*pow(10,p);
            ans+=s;
            p++;
            i--;
        }
        return ans;
    }

    int nextGreaterElement(int n) {
        int* arr = new int[32];
        for(int i=0;i<32;i++)
            arr[i]=0;
        int N = 32;
        int j = 31;
        while(n>0){
            arr[j--] = n%10;
            n/=10;
        }
        int s = j + 1;
        int e = 31;
        while(e>s){
            if(arr[e-1]<arr[e])
                break;
            e--;
        }
        if(e==s)
            return -1;
        int pos1 = e - 1;
        int pos2 = e;
        while(e<N){
            if(arr[e]>arr[pos1] && arr[e]<arr[pos2]){
                pos2 = e;
            }
            e++;
        }
        swap(arr[pos1],arr[pos2]);
        // cout<<pos1<<" "<<pos2;
        //Sort from (pos1 + 1) to 31
        for(int i=pos1+1;i<N;i++){
            for(int j=pos1+1;j<N-1;j++){
                if(arr[j]>arr[j+1])
                    swap(arr[j],arr[j+1]);
            }
        }
        return form_num(arr,s);
    }

int main() {
    int n;   cin>>n;
    cout<<nextGreaterElement(n);
}




