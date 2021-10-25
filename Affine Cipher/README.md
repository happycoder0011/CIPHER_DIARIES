# Affine Cipher

The Affine Cipher is a type of substitution cipher, which means that, during encryption, each character is mapped to another one. This mapping is done by treating each character by its numeric value, applying a simple mathematical function and then converting the new value back to a character. The decryption follows a similar procedure and allows each character to be mapped to the original one.

## Encryption

Let's assume we are using an alphabet with <i>m</i> letters (for the english alphabet, we have <i>m=26</i>). Each letter from the alphabet is assigned a number from 0 to <i>m-1</i>, in the same order as they are present in the alphabet. A single letter that is assigned the number <i>x</i> goes through the following mathematical function, where <i>E(x)</i> is the number that corresponds to the new character obtained after encryption:

<i>E(x) = (ax + b) mod (m)</i>

<i>a</i> and <i>b</i> are the keys of the cipher. And $a$ and $m$ must be coprime.

this new value, <i>E(x)</i>, is then converted to the corresponding character. This process is repeated for each character in the text until the entire text is encrypted.

## Decryption

We will assume <i>x</i> as the number assigned for a character in the encrypted text. This number will go through the following function:

<i> D(x) = a<sup>-1</sup>(x-b)mod(m) </i>

Where <i>a<sup>-1</sup></i> is the multiplicative inverse of <i>(a)mod(m)</i>, satisfying the following formula:

<i> (aa<sup>-1</sup>)mod(m) = 1 </i>

The number <i>D(x)</i> is then converted to the corresponding character, which is the original character, before the text being encrypted.

## Example

Let's encrypt and decrypt the text `cipher`, which uses the english alphabet (<i>m=26</i>). We will use <i>a=5</i> and <i>b=8</i>.

### Encryption

| Original Text      | x | <i>(5x + 8)mod(26)</i> | Encrypted Text |
| :---: | :---: | :---: | :---: |
| c | 2 | 18 | s |
| i | 8 | 22 | w |
| o | 15 | 5 | f |
| h | 7 | 17 | r |
| e | 4 | 2 | c |
| r | 17 | 15 | p |

So, by encrypting the text `cipher` we get the text `swfrcp`.

### Decryption

From the formula shown before, we have <i> a<sup>-1</sup> = 21 </i>.

| Encrypted Text | x | <i>21(x - 8)mod(26)</i> | Original text |
| :---: | :---: | :---: | :---: |
| s | 18 | 2 | c |
| w | 22 | 8 | i |
| f | 5 | 15 | p |
| r | 17 | 7 | h |
| c | 2 | 4 | e |
| p | 15 | 17 | r |
