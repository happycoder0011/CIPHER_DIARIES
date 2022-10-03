#include<bits/stdc++.h>
using namespace std;

string crypt(string input, string key) {
  int inputLength = input.length();
  int keyLength = key.length();

  string result = "";
  for(int i = 0; i < inputLength; i++) {
    result += input[i] ^ key[i%keyLength];
  }

  return result;
}

int main(){
  string key = "RandomString";
  string testString = "this is a test string 123456";
  string encryptedString = crypt(testString, key);
  cout << "Encrypted: " << encryptedString << endl;

  string decryptedString = crypt(encryptedString, key);
  cout << "Decrypted: " << decryptedString << endl;
}
