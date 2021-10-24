#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Grid[26][26];

void genGrid(){
    int i,j,k;
    for(i=0;i<26;i++){
        k=0;
        for(j=i;j<26;j++){
            Grid[i][k++]=j+'a';
        }
        for(j=0;j<i;j++){
            Grid[i][k++]=j+'a';
        }
    }
}

char* encrypt(char* text, char* key){
    int tsize = strlen(text);
    int ksize = strlen(key);
    int i;
    
    char* enc = (char*)calloc(tsize+1,sizeof(char));
    enc[tsize] = '\0';
    for(i=0;i<tsize;i++){
        enc[i]=Grid[key[i%ksize]-'a'][text[i]-'a'];
    }
    return enc;
}

char* decrypt(char* enc, char* key){
    int tsize = strlen(enc);
    int ksize = strlen(key);
    int i;
    
    char* dec = (char*)calloc(tsize+1,sizeof(char));
    dec[tsize] = '\0';
    for(i=0;i<tsize;i++){
        dec[i] = Grid[0][((enc[i]-'a')-(key[i%ksize]-'a')+26)%26];
    }
    return dec;
}

int main()
{
    genGrid();
    
    char* text = "secretmessage";
    char* key = "secretkey";
    
    char* enc = encrypt(text,key);
    printf("Encrypted: %s\n",enc);
    char* dec = decrypt(enc,key);
    printf("Decrypted: %s", dec);

    return 0;
}

