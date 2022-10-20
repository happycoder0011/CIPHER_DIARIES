#include<bits/stdc++.h>
using namespace std;

pair<string, string> getInput(){
    string inputStr;
    string key;

    cout<<"Enter the key: ";
    cin.ignore();
    getline(cin, key);

    cout<<"Enter the text: ";
    getline(cin, inputStr);

    return {inputStr, key};
}

string encryption(string plainText, string key){
    int mod=key.size(), j=0, i, n=mod, m=plainText.size();
    cout<<"plainText: "<<plainText<<"	"<<"key: "<<key<<endl;
    for(i=n; i<m; ++i){
        key += key[j%mod];
        j++;
    }
    
    string cipherText="";
    for(i=0; i<m; i++){
        cipherText += (key[i]-'A'+ plainText[i]-'A')%26+'A';
    }

    return cipherText;
}

string decryption(string cipherText, string key){
    int mod = key.size(), j=0, n=key.size(), m=cipherText.size(), i;
    
    for(i=n; i<m; ++i){
        key += key[j%mod];
        j++;
    }
    
    string plainText="";
    for(i=0; i<m; ++i){
        plainText += (cipherText[i] - key[i]+26)%26+'A';
    }
    
    return plainText;
}

int main(){
    int choice;
    bool isRunning = true;

    cout<<"**********************RAIL FENCE TRANSPOSITION CIPHER**********************\n";

    while(isRunning){
        cout<<"Choose one of the below:\n";
        cout<<"1.Encryption\n";
        cout<<"2.Decryption\n";
        cout<<"3.QUIT\n";

        cin>>choice;

        switch(choice){
            case 1:
            	{
	                cout<<"***************ENCRYPTION***************\n";
	                pair<string, string> inputs = getInput();
	                string cipherText = encryption(inputs.first, inputs.second);
	                cout<<"The cipherText is: \n";
	                cout<<cipherText<<endl;
	                cout<<"***************************************\n";
	                break;
            	}

            case 2:
            	{
	                cout<<"***************DECRYPTION***************\n";
	                pair<string, string> inputs = getInput();
	                string plainText = decryption(inputs.first, inputs.second);
	                cout<<"The plainText is: \n";
	                cout<<plainText<<endl;
	                cout<<"***************************************\n";
	                break;
            	}

            case 3:
                isRunning = false;
                break;

            default:
                cout<<"No such option available\n";
                break;
        }
    }
}
