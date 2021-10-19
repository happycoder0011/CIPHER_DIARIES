#include<bits/stdc++.h>
using namespace std;
 
const int a = 17;
const int b = 20;
 
string encryptMessage(string msg)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if(msg[i]!=' ')
            cipher = cipher +
                        (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
            cipher += msg[i];    
    }
    return cipher;
}
 
string decryptCipher(string cipher)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;
     
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
         
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')
            msg = msg +
                       (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else
            msg += cipher[i];
    }
 
    return msg;
}
 
int main(void)
{
    string msg;

    cout<<"Enter the text which you want to encrypt/ decrypt:"<<endl;
    
    getline(cin, msg);

    transform(msg.begin(), msg.end(), msg.begin(), ::toupper); 
     
    string cipherText = encryptMessage(msg);
    cout << "Encrypted Text is : " << cipherText<<endl;
     
    cout << "Decrypted Text is: " << decryptCipher(cipherText);
 
    return 0;
}