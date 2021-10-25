# Affine Cipher

The Affine Cipher is a type of substitution cipher, which means that, during encryption, each character is mapped to another one. This mapping is done by treating each character by its numeric value, applying a simple mathematical function and then converting the new value back to a character. The decryption follows a similar procedure and allows each character to be mapped to the original one.

## Encryption

Let's assume we are using an alphabet with $m$ letters (for the english alphabet, we have $m=26$). Each letter from the alphabet is assigned a number from $0$ to $m-1$, in the same order as they are present in the alphabet. A single letter that is assigned the number $x$ goes through the following mathematical function, where $E(x)$ is the number that corresponds to the new character obtained after encryption:

$$ E(x) = (ax + b) mod (m) $$

$a$ and $b$ are the keys of the cipher. And $a$ and $m$ must be coprime.

this new value, $E(x)$, is then converted to the corresponding character. This process is repeated for each character in the text until the entire text is encrypted.

## Decryption

We will assume $x$ as the number assigned for a character in the encrypted text. This number will go through the following function:

$$ D(x) = a^{-1}(x-b)mod(m) $$

Where $a^{-1}$ is the multiplicative inverse of $(a)mod(m)$, satisfying the following formula:

$$ (aa^{-1})mod(m) = 1 $$

The number $D(x)$ is then converted to the corresponding character, which is the original character, before the text being encrypted.

## Example

Let's encrypt and decrypt the text `cipher`, which uses the english alphabet ($m=26$). We will use $a=5$ and $b=8$.

### Encryption

| Original Text      | x | (5x + 8)mod(26) | Encrypted Text |
| :---: | :---: | :---: | :---: |
| c | 2 | 18 | s |
| i | 8 | 22 | w |
| o | 15 | 5 | f |
| h | 7 | 17 | r |
| e | 4 | 2 | c |
| r | 17 | 15 | p |

So, by encrypting the text `cipher` we get the text `swfrcp`.

### Decryption

From the formula shown before, we have $ a^{-1} = 21 $.

| Encrypted Text | x | 21(x - 8)mod(26) | Original text |
| :---: | :---: | :---: | :---: |
| s | 18 | 2 | c |
| w | 22 | 8 | i |
| f | 5 | 15 | p |
| r | 17 | 7 | h |
| c | 2 | 4 | e |
| p | 15 | 17 | r |
