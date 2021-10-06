# Vigenere Cipher

Vigen`ere Cipher is a method of encrypting alphabetic text using a form of polyalphabetic substitution. A
polyalphabetic cipher is any cipher based on substitution, using multiple substitution alphabets.  Both the encryption and decryption is done using the **Vigenère square** or **Vigenere table.**  in which alphabets from A to Z are written in 26 rows.

### Approach 

Before performing any substitution, we first separated the
non alphabetic characters from the given text like punctuation and whitespace. Next, step is to expand the key cyclically to be equal to the length of the text. For example, if
text is BLOCKCHAIN and key is pink, the extended key will be
pinkpinkpi.

**Encryption** :  During encryption, a letter of the text is taken from
the row of the table and its paired letter from the key is taken
from the column. The resulting character is the substitution.
It can be defined as, *E<sub>i</sub> = (P<sub>i</sub> + K<sub>i</sub>) mod 26*, where *i* denotes the *i*
th character of plain-text *P*, key *K*,
and resulting encrypted character *E*. 26 is used for characters of the English alphabet. For the previous
BLOCKCHAIN example, B is paired with p. So we use row B and column p of the table resulting in Q. Final
ciphertext will be QTBMZKUKXV.

**Decryption** : : Decryption is performed by going to the row in the table corresponding to the key, finding the
position of the ciphertext letter in this row, and then using the column’s label as the plaintext. For example, in
row p (from pinkpinkpi), the ciphertext Q appears in column B, which is the first plaintext letter. Next we go to
row i (from pinkpinkpi), locate the ciphertext T which is found in column L, thus L is the second plaintext
letter. This can be defined as, *D<sub>i</sub> = (E<sub>i</sub> − K<sub>i</sub> + 26) mod 26*.                              
                                                        **Vigen`ere substitution table**

                | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
                |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
                | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A |
                | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B |
                | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C |
                | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D |
                | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E |
                | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F |
                | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G |
                | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H |
                | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I |
                | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J |
                | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K |
                | M | N | 0 | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L |
                | N | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M |
                | O | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N |
                | P | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O |
                | Q | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P |
                | R | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q |
                | S | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R |
                | T | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S |
                | U | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T |
                | V | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U |
                | W | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V |
                | X | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W |
                | Y | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X |
                | Z | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y |

### Vigenere Cipher Encryption ###

**Message Text:**  THECRAZYPROGRAMMER

**Key:** HELLO

Here we have to obtain a new key by repeating the given key till its length become equal to original message length.

**New Generated Key**: HELLOHELLOHELLOHEL

For encryption take first letter of message and new key i.e. T and H. Take the alphabet in Vigenere Cipher Table where T row and H column coincides i.e. A.

Repeat the same process for all remaining alphabets in message text. Finally the encrypted message text is:

**Encrypted Message**: ALPNFHDJAFVKCLATIC

The algorithm can be expressed in algebraic form as given below. The cipher text can be generated by below equation.

*E<sub>i</sub> = (P<sub>i</sub> + K<sub>i</sub>) mod 26*

Here P is plain text and K is key.

### Vigenere Cipher Decryption ###

**Encrypted Message:** ALPNFHDJAFVKCLATIC

**Key:** HELLO

**New Generated Key:** HELLOHELLOHELLOHEL

Take first alphabet of encrypted message and generated key i.e. A and H. Analyze Vigenere Cipher Table, look for alphabet A in column H, the corresponding row will be the first alphabet of original message i.e. T.

Repeat the same process for all the alphabets in encrypted message.

**Original Message:** THECRAZYPROGRAMMER

Above process can be represented in algebraic form by following equation.

*D<sub>i</sub> = (E<sub>i</sub> − K<sub>i</sub> + 26) mod 26*