#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* crypt(char* input, char* key) {
  int inputLength = strlen(input);
  int keyLength = strlen(key);

  char* result = (char*) calloc(inputLength + 1, sizeof(char));
  result[inputLength] = '\0';

  for(int i = 0; i < inputLength; i++) {
    result[i] = input[i] ^ key[i%keyLength];
  }

  return result;
}

int main() {
  char key[] = "RandomString";
  char* encryptedString = crypt("this is a test string 123456", key);
  printf("Encrypted: %s\n", encryptedString);

  char* decryptedString = crypt(encryptedString, key);
  printf("Decrypted: %s\n", decryptedString);
}