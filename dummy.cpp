#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    // cout<<"lollll\n";
    int count=0;

    for(int i=p;i<=q;i++){
        cout<<i<<endl;
        if(i==1){
            cout<<i<<" \n";
            continue;
        }
        unsigned long long temp = i*i;
        cout<<temp<<endl;
        long a;
        string first,last;
        int  len = to_string(i).length();
        string s = to_string(temp);
        if(s.length()==2*len){
            first = s.substr(0,len);
            last = s.substr(len,s.length());
        }else{
            first = s.substr(0,len-1);
            last = s.substr(len-1,s.length());            
        }
        long b = stol(last);
        if(len==s.length()){
            a=0;
        }else{
             a = stol(first);
        }
        if(b==0)
            continue;
        if(a+b == i){
            count++;
            cout<<i<<" \n";
        }
    }

    if(count==0)
        cout<<"INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
