# Autokey Cipher

Also know as ***Autoclave Cipher***, is a type of cipher that incorporates the
same message into the key. In this cipher, the key is a stream of subkeys which is used to encrypt the corresponding character in the plaintext.


### Formula 
---------------------

Encryption: C<sub>i</sub> = (P<sub>i</sub> + K<sub>i</sub>) mod 26

Decryption: P<sub>i</sub> = (C<sub>i</sub> - K<sub>i</sub>) mod 26

C<sub>i</sub> =	Cipher text stream

K<sub>i</sub> = 	Key stream

P<sub>i</sub> = 	Plain text stream

***NOTE***: Remember that the tabula recta starts at 0!!!


[Tabula Recta](https://upload.wikimedia.org/wikipedia/commons/9/9a/Vigen%C3%A8re_square_shading.svg)



##### Example 1


Label | Result
------------ | -------------
Plain Text (P)|    H  - E -  L -  L -  O
Tabula numbers | 7 -  4 -  11 - 11 - 14  
Key (K)| N -  H -  E -  L -  L	
Tabula numbers | 13 - 7 -  4 -  11 - 11  
After formula | 20 - 11 -  15 - 22 - 25  
Cipher| U  -  L -  P -  W -  Z

##### Example 2
- **Plain Text** : happycoder
- **Key** : supercoder
- **Cipher** : zuetpecgii
