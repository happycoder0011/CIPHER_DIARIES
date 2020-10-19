Simple Substitution Cipher
Introduction

The simple substitution cipher is a cipher that has been in use for many hundreds of years (an excellent history is given in Simon Singhs 'the Code Book').
It basically consists of substituting every plaintext character for a different ciphertext character.
It differs from the Caesar cipher in that the cipher alphabet is not simply the alphabet shifted, it is completely jumbled.

The simple substitution cipher offers very little communication security, and it will be shown that it can be easily broken even by hand, especially as the messages become longer (more than several hundred ciphertext characters).
Example 

Here is a quick example of the encryption and decryption steps involved with the simple substitution cipher.
The text we will encrypt is 'defend the east wall of the castle'.

Keys for the simple substitution cipher usually consist of 26 letters (compared to the caeser cipher's single number). An example key is:

plain alphabet : abcdefghijklmnopqrstuvwxyz
cipher alphabet: phqgiumeaylnofdxjkrcvstzwb

An example encryption using the above key:

plaintext : defend the east wall of the castle
ciphertext: giuifg cei iprc tpnn du cei qprcni

It is easy to see how each character in the plaintext is replaced with the corresponding letter in the cipher alphabet. 
Decryption is just as easy, by going from the cipher alphabet back to the plain alphabet. When generating keys it is popular to use a key word, 
e.g. 'zebra' to generate it, since it is much easier to remember a key word compared to a random jumble of 26 characters. Using the keyword 'zebra', 
the key would become:

cipher alphabet: zebracdfghijklmnopqstuvwxy

This key is then used identically to the example above. If your key word has repeated characters e.g. 'mammoth', 
be careful not to include the repeated characters in the cipher alphabet.
