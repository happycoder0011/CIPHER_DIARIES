/**     Author: Ajaysinh Rajput       **/

//      Substitution Cipher in C++          // 

/*

        SAMPLE TESTCASE
Message           : THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
Key               : PROGRAMMING
Encrypted Message : TNA LUBOD RQJWH MJX CUFKS JVAQ TNA EPZY GJI 
Decrypted Message : THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG

*/


#include<bits/stdc++.h>
using namespace std;

unordered_map<char,char> mapping,unmapping;


string SubstitutionCipher_encryption(string message, string key)
{
    // Remove ruplicate characters from key
    string unique_key="";
    unordered_map<char,int> presence;
    for(auto c:key)
    {
        if(!presence[c])
        {
            presence[c]++;
            unique_key.push_back(c);
        }
    }
    
    // Add letters to the unique_key in alphabetical order, ommiting letters that are already present.
    string text="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char c: key) {
        text.erase(remove(text.begin(), text.end(), c), text.end());
    }
    string ciphertext_alpha = unique_key+text;

    // Mapping chars for encryption and Unmapping them for decryption
    for(int i=0;i<26;i++)
    {
        mapping[char('A'+i)]=ciphertext_alpha[i];
        unmapping[ciphertext_alpha[i]]=char('A'+i);
    }

    // Encrypt the message
    string cipher="";
    for(char c:message)
    {
        if(isalpha(c))
            cipher.push_back(mapping[c]);
        else
            cipher.push_back(c);
    }

    return cipher;
}


string SubstitutionCipher_decryption(string cipher, string key)
{
    // Decrypt the encrypted message
    string Decrypted="";
    for(char c:cipher)
    {
        if(isalpha(c))
            Decrypted.push_back(unmapping[c]);
        else
            Decrypted.push_back(c);
    }

    return Decrypted;
}


int main()
{
    string s,key;
    cout<<"\nEnter message : ";
    getline(cin,s);
    cout<<"\nEnter key : ";
    cin>>key;
    
    // Convert strings to uppercase
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Encryption Part
    string Cipher = SubstitutionCipher_encryption(s,key);
    cout<<"\nEncrypted message: "<<Cipher<<'\n';

    // Decryption Part
    string Decrypted = SubstitutionCipher_decryption(Cipher,key);
    cout<<"\nDecrypted message: "<<Decrypted<<'\n';

    return 0;

}