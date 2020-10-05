#include<iostream>
#include<string>
using namespace std;

void encrypt_autokey(string &str, int key){
    for(int i=0;i<str.size();i++){
        int temp = str[i]-97;
        str[i] = (((str[i]-'a') + key)%26) + 'a';
        key = temp;
    }
}

void decrypt_autokey(string &str, int key){
    for(int i=0;i<str.size();i++){
        str[i] = (((str[i]-'a') - key + 26)%26) + 'a';
        key = str[i]-97;
    }
}

int main(){
    string text;
    int key;
    cout<<" Enter the text : ";
    getline(cin, text);
    cout<<" Enter key : ";
    cin>>key;
    cout<<"\n=================\n\n";

    encrypt_autokey(text, key);
    cout<<" Cipher text : "<<text<<"\n";
    decrypt_autokey(text, key);
    cout<<" Decoded plain text : "<<text<<"\n";
    cout<<"\n=================\n\n";

    return 0;
}

