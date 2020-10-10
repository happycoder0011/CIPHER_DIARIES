#include <stdio.h>
#include <string.h>

void key_stream(char* str, char* key){
    int strl = strlen(str);
    int keyl = strlen(key);
    if(keyl < strl)
        strncat(key, str, strl-keyl);
}

void encrypt_autokey(char* str, char* key){
    for(int i = 0; i < strlen(str); i++){
        str[i] = ((str[i] - 'a')+ (key[i] - 'a') % 26) + 'a';
    }
}

void decrypt_autokey(char* str, char* key){
    for(int i = 0; i < strlen(str); i++){
        str[i] = ((str[i] - 'a') - (key[i] - 'a') % 26) + 'a';
    }
}

int main(){
    char str[1024], key[1024];
    scanf("%s\n%s",str,key);
    key_stream(str,key);
    printf("\n=================\n\n");
    encrypt_autokey(str,key);
    printf(" Cipher text : %s\n",str);
    decrypt_autokey(str,key);
    printf(" Decoded plain text : %s\n",str);
    printf("\n=================\n\n");
    return 0;
}