# Affine Cipher

The affine cipher is a type of **monoalphabetic substitution cipher**, where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter.
The formula used means that **each letter encrypts to one other letter**, and back again, meaning the cipher is essentially a standard substitution cipher with a rule governing which letter goes to which.

### Principle

#### Encryption:

It uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another integer that correspond to a ciphertext letter. The **encryption function** for a single letter is:

```
E ( x ) = ( a x + b ) % m
```

- **modulus m**: size of the alphabet
- **a and b**: key of the cipher.
- **a** must be chosen such that **a** and **m** are coprime.

#### Decryption:

In deciphering the ciphertext, we must perform the opposite (or inverse) functions on the ciphertext to retrieve the plaintext. Once again, the first step is to convert each of the ciphertext letters into their integer values. The **decryption function** is:

```
D ( x ) = a^-1 ( x - b ) mod m
```

- **a^-1** : modular multiplicative inverse of a modulo m. i.e., it satisfies the equation
- **1 = a a^-1 % m**.

#### To find a multiplicative inverse:

We need to find a number x such that:
If we find the number x such that the below equation is true, then x is the inverse of a, and we call it a^-1. The easiest way to solve this equation is to search each of the numbers 1 to 25, and see which one satisfies the equation.

**Equation for multiplicative inverse:**

```
[g,x,d] = gcd(a,m);    % we can ignore g and d, we dont need them
x = mod(x,m);
```

If you now multiply x and a and reduce the result (mod 26), you will get the answer 1. Remember, this is just the definition of an inverse i.e. if a\*x = 1 (mod 26), then **x is an inverse of a (and a is an inverse of x)**.

#### Example:

<p>
<img src="https://i.imgur.com/Z85VX9u.png">

**_Affine Decryption_**

</p>
