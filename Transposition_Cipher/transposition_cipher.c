/* Transposition Cipher in C */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Printing error messages*/
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
}

/* Filling the plaintext in an array */
void fill_array(int m, int n, char (*str)[n], char *p) {
    int i = 0, j;
    for(int i = 0; i < m; i++) {
        for(int j = 0; (j < n) && (*p != '\0'); j++) {
            str[i][j] = *p++;
        }
    }
}

int main(int argc, char **argv) {

    //checking command line arguments
    if(argc < 3) {
        printf("Usage : ./{binary} {plain_text} {key}\n");
        error("Improper number of arguments");
        exit(1);
    }

    //assigning command line arguments to variables
    char *plain_text = argv[1]; 
    int key = atoi(argv[2]);
    int len = strlen(plain_text);

    //key size check
    if(key > len) {
        error("Key cannot be greater than size of plaintext");
        exit(1);
    }

    int n = ((len % key) ? (len / key) + 1 : (len / key));
    char str[n][key];
    memset(str, 'x', sizeof(str[0][0]) * n *  key);

    //filling str with given plaintext
    fill_array(n, key, str, plain_text);

    //displaying the ciphertext
    for(int i = 0; i < key; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", str[j][i]);
        }
    }
    printf("\n");
}
