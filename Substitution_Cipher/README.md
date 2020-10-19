# Subsitution Cipher

A (general) substitution cipher is a method of encrypting by which units of plaintext are replaced with ciphertext, according to a fixed system. The receiver deciphers the text by performing the inverse substitution. We can compared this with transposition ciphers. In a transposition cipher, the units of the plaintext are rearranged in a different and usually quite complex order, but the units themselves are left unchanged. By contrast, in a substitution cipher, the units of the plaintext are retained in the same sequence in the ciphertext, but the units themselves are altered.

Here we implement a simple subsitution cipher, where each letter from the (plaintext) alphabet is replaced with a letter of the alphabet (note it can be the same letter), where the latter is called the **ciphertext alphabet**. A traditional way to generate the ciphertext alphabet is as follows:

1. Choose a word as the keyword. e.g. PROGRAMMING
2. Write out the word, removing any letters that at repeated later. e.g. PROGRAMMING -> PROGAMIN
3. Add letters to the above string in alphabetical order, ommiting letters that are already present. The result is our ciphertext alphabet. e.g. PROGAMIN -> PROGAMINBCDEFHJKLQSTUVWXYZ

### Example:

- **Keyword** : PROGRAMMING
    - Plaintext alphabet:	ABCDEFGHIJKLMNOPQRSTUVWXYZ
    - Ciphertext alphabet:	PROGAMINBCDEFHJKLQSTUVWXYZ
(Note that letters after R are mapped to themselves. This might seem like a problem but any outsider doesn't know this for sure!)
- **Plaintext** : THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
- **Ciphertext** : TNA LUBOD RQJWH MJX CUFKS JVAQ TNA EPZY GJI