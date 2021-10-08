#include <iostream>

using namespace std;

#define is_between(x,low,high) if(x >= low && x <= high)
#define isnt_between(x,low,high) if(x < low || x > high)

/*
 * Cipher function 
 *
 * @Params
 *
 * @text: The message that will be encrypted or decrypted
 * @key: The key used to encrypt or decrypt
 *
 * @cipher: The encrypted message
 * @rotate: A single letter of the key
 * @subtract: Subtract a value depending on uppercase or lowercase
 *
 * It will recieve @text and @key as parameters and will encrypt @text
 * with the @key.
 *
 * For each letter in @text the for loop will encrypt each letter using
 * a letter in key.
 *
 * If the letter in @text isn't an alphabet letter it will skip it and
 * add it into @cipher string.
 *
 * The @subtract will be set as 'a' or 'A' depending on the text letter.
 *
 * The @rotate is a letter of the key that will encrypt the text letter.
 *
 * Then we concatenate in @cipher.
 *
 */

string vigenere(string text, string key)
{
    string cipher = "";
    int char_value,
        rotate,
        subtract;

    for(int i=0; i<text.size(); i++)
    {
        char_value = text.at(i);

        is_between(char_value, 'A', 'Z') {
            subtract = 'A';
        } else is_between(char_value, 'a', 'z') {
            subtract = 'a';
        } else {
            cipher += char_value;
            continue;
        }

        char_value -= subtract;

        rotate = key.at(i % key.size());
        rotate = tolower(rotate) - 'a';

        char_value = (char_value + rotate) % 26;
        char_value += subtract;

        cipher += char_value;
    }

    return cipher;
}

/*
 * Check Key
 *
 * @Params
 *
 * @key: The key used to encrypt or decrypt.
 *
 * It will check if every letter is an alphabetic letter.
 *
 */

bool check_key(string key) 
{
    for(int i=0; i<key.size(); i++)
        isnt_between(key.at(i), 'A', 'z')
            return false;
    return true;
}

/*
 * Main function 
 *
 * @Params
 *
 * @text: The message that will be encrypted or decrypted.
 * @key: The key used to encrypt or decrypt.
 *
 * It will recieve the text and the key.
 *
 */

int main() {

    string text,
           key;

    cout << "Enter a text:" << endl;
    getline(cin, text);

    cout << "Enter a passphrase:" << endl;
    cin >> key;

    if(!check_key(key)) {
        cout << "The key can only contain letters" << endl;
        return 1;
    }

    cout << vigenere(text, key) << endl;

    return 0;
}

