# Caesar Cipher

Caesar Cipher, also known as **Shift Cipher**, **Caesar's Code** or **Caesar Shift** is one of the simplest, widely known and used encryption technique or algorithm. It is a type of encryption algorithm in which the plain text shifts or changes to a different one when encrypted. 

### Principle 

During caesar **encryption**, each letter in the plain-text is replaced by a letter some fixed positions
down the alphabet. The alphabet is taken to be **cyclical**, i.e., the first character comes again after the last
character. The process needs to be reversed for decryption. 

Encryption of a letter x of the English alphabet
consisting of 26 characters can be described as, *E<sub>n</sub>(x) = (x + n)%26*. 

<p >

  <img src="https://higherlogicdownload.s3.amazonaws.com/IMWUC/UploadedImages/92757287-d116-4157-b004-c2a0aba1b048/Caesar_cipher_Encryption_Algorithm.png">

  *Caeser Encryption*

</p>
Similarly, decryption can be described as,
*D<sub>n</sub>(x) = (x − n)%26*.
<p >
<img src="https://higherlogicdownload.s3.amazonaws.com/IMWUC/UploadedImages/92757287-d116-4157-b004-c2a0aba1b048/Caesar_cipher_Decryption_Algorithm.png">

*Ceaser Decryption*
</p>
<!-- The number or level of shifts are fixed for all characters throughout the plain text which can be specified as per the requirement. The code above is dedicated towards the shift of 4 characters. -->

In our code, we demonstrate two methods of breaking this cipher −
1. **Brute-Force approach**, where the key is unknown. A decrypted code will be generated for each of the 26
different possible eys (for the english alphabet). User can pick the most meaningful one from there.
2. **Known-key decipher**, where the key is known to the user.
### Example:

- **Text** : THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
- **Shift** : 4
- **Cipher** : XLI UYMGO FVSAR JSB NYQTW SZIV XLI PEDC HSK

<hr />

 - **Cipher**: krclxrwrbxwnxocqnlxxunbcrwencrxwbrwanlnwccrvnb.
 - **Shift**: 9
 - **Text**: bitcoinisoneofthecoolestinvetionsinrecenttimes


***Note:*** *The shift can be set to follow the direction that the user desires for cipher conversion. **For Example:** The character **A** can be converted to either **E** or **W** depending on whether the shift is set to **4** or **-4**. While in case of decryption, the shift is in the exact opposite direction as that of encryption.*