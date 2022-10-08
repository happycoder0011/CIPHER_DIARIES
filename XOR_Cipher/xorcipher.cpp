#include<iostream>
#include<string.h>

using namespace std;

void XORChiper(char orignalString[]) {
   char xorKey = 'T';
   int len = strlen(orignalString);
   for (int i = 0; i < len; i++){
      orignalString[i] = orignalString[i] ^ xorKey;
      cout<<orignalString[i];
   }
}
int main(){
   char sampleString[] = "Hello!";
   cout<<"The string is: "<<sampleString<<endl;
   cout<<"Encrypted String: ";
   XORChiper(sampleString);
   return 0;
}