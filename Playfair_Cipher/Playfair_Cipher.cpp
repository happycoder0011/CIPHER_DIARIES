// C++ program to implement Playfair Cipher 

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void) {
    cout<<"Plain Text: ";
    string plaintext;
    getline(cin,plaintext);
    cout<<"Key: ";
    string key;
    cin>>key;

    int i,j,k,n;
    string s;
    for(i=0;i<plaintext.size();i++){
        if(plaintext[i]!=' ')
            s+= plaintext[i];
    }

    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;
    map<char,int> mp;
    k=0;
    int pi,pj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            if(k<key.size()){
                a[i][j]=key[k];
                mp[key[k]]++;
                pi=i;
                pj=j;
            }
            if(k==key.size())
            break;
        }
        if(k==key.size())
            break;
    }
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            if(k<26){
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++;
            }
        }
        j=0;
    }

    string ciphertext;
    if(s.size()%2==1)
        s+="x";
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1])
            s[i+1]='x';
    }
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
        }
    }
    
    for(i=0;i<s.size()-1;i+=2){
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        if(y1==y2){
            ciphertext+=a[y1][(x1+1)%5];
            ciphertext+=a[y1][(x2+1)%5];
        }
        else if(x1==x2){
            ciphertext+=a[(y1+1)%5][x1];
            ciphertext+=a[(y2+1)%5][x2];    
        }
        else {
            ciphertext+=a[y1][x2];
            ciphertext+=a[y2][x1];
        }
    }
    cout<<"Encrypted Text: "<<ciphertext<<'\n';
}