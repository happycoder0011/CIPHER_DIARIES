#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encode(char* input, int shift) {
	int stringLength = strlen(input);
	char* out = (char*) calloc(sizeof(char), stringLength);
	for(int pos = 0; pos < stringLength; pos++) {
		if(input[pos] == toupper(input[pos])) {
			out[pos] = (input[pos] + shift - 65) % 26 + 65;
		} else {
			out[pos] = (input[pos] + shift - 97) % 26 + 97;
		}
	}
	return out;
}

int main() {
	char string[1024];
	int shift;
	printf("Input text: ");
	scanf("%s", &string);
	printf("Shift ammount: ");
	scanf("%d", &shift);
	printf("Output: %s\n", encode(string, shift));
}