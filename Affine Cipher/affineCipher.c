#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inverse(int n, int r){
    if((n*r)%26==1){
        return r;
    }else if((n*(-r))%26==1){
        return 26-r;
    }else{
        return inverse(n,r+1);
    }
}

char* encrypt(char* text, int a, int b){
    int length = strlen(text);
    char* enc = (char*)calloc(length+1, sizeof(char));
    enc[length] = '\0';
    for(int i=0; i<length; i++){
        enc[i] = ((a*(text[i]-'a')+b)%26)+'a';
    }
    return enc;
}

char* decrypt(char* enc, int a, int b){
    int length = strlen(enc);
    char* dec = (char*)calloc(length+1, sizeof(char));
    dec[length] = '\0';
    int _a=inverse(a,1);
    for(int i=0; i<length; i++){
        dec[i] = ((_a*(((enc[i]-'a')-b)+26))%26)+'a';
    }
    return dec;
}

int main()
{
    char* text = "secretmessage";
    char* enc = encrypt(text,5,3);
    
    printf("Encrypted: %s\n",enc);
    
    char* dec = decrypt(enc,5,3);
    
    printf("Decrypred: %s",dec);
    
    return 0;
}
