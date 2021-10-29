#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_index(char code[],char char_to_find){
  for(int i = 0 ; i < 26; i ++){
    if(code[i] == char_to_find){
      return i;
    }
  }
  return -1;
}

char* encrypt(char *message,char code[]){
  int length = strlen(message);
  char *encrypted_message = (char *) malloc(sizeof(char)*length);

  for(int i = 0; i < length; i++){
    int encryption_index = tolower(message[i]) - 'a';
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_message[i] = code[encryption_index];
    }else{
      encrypted_message[i] = message[i];
    }
  }
  return encrypted_message;
}

char *decrypt(char *message,char code[]){
  int length = strlen(message);
  char *decrypted_message = (char *) malloc(sizeof(char)*length);
  for(int i = 0; i <length; i++){
    int decryption_index = tolower(message[i]) - 'a';
    if(decryption_index >= 0 && decryption_index < 26){
      int code_index = find_index(code,tolower(message[i]));
      decrypted_message[i] = 'a' + code_index;
    }else{
      decrypted_message[i] = message[i];
    }
  }
  return decrypted_message;
}

int main(){
  char *message = "test message";
  char code[26] = {'b','a','c','d','s','f','g','h','i','j','k','l','m','n','o','p','q','r','e','t','u','v','w','x','y','z'};

  char *encrypted_message = encrypt(message,code);
  printf("Original Message: %s\nEncrypted Message: %s\n",message,encrypted_message);
  char *decrypted_message = decrypt(encrypted_message,code);
  printf("Decrypted Message: %s\n",decrypted_message);
}