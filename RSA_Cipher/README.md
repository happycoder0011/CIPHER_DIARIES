# RSA Cryptosystem
 The RSA cryptosystem, is a particular variation of the public-key public-key cryptosystem which requires a public-secret key pair to perform encryption and decryption. 

## Principle 
In RSA cryptosystem, we treat plaintext and ciphertext message blocks as large numbers represented using thousands of bits. Encryption and decryption are done using `modular exponentiation`, and the correctness of these encryption and decryption algorithms is based on `Euler’s Theorem` and other properties of modular arithmetic.  

We can roughly divide the whole process into three phases:

### Setup :
 * At first, we choose two very large prime numbers (current standard 2048 bits), p and q and set `n = pq`.  The security of the RSA cryptosystem is closely tied to factoring n, which would reveal the values of p and q
 * Then a number e is chosen in such way so that e is relative prime to the totient function of n. That is `gcd(e , Φ(n)) = 1`.
 * d is the multiplicative inverse of e in Z<sub>Φ(n)</sub>. That is, `de mod Φ(n) = 1`. This is calculated using the extended *Euclidean algorithm*.

### Keys : 
Now, the public key is the pair `(e, n)` and the secret decryption key is `d`.

### Encryption : 
encrypting of plaintext,  `M` requires a single modular exponentiation. Given by, C = M<sup>e</sup> mod n. This calculation can be done using *the repeated squaring method*.

### Decryption : 
decrypting also requires *modular exponentiation*, when computing plaintext, M = C<sup>d</sup> mod n


<p>
<img src = "https://slideplayer.com/slide/5974035/20/images/16/Example+of+RSA+%281%29+Choose+p+%3D+7+and+q+%3D+17.+Compute+n+%3D+p%2Aq%3D+119..jpg">
<b>RSA example</b>
</p>
