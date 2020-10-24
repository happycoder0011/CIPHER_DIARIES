# Tranposition Cipher 

## Encryption
The Transposition Cipher encrypts by rearranging the order of the letters in the ciphertext according to a predetermined method. This is done by picking a matrix of a fixed size, such as 8x10 and then writing the letters of the message across the rows of the matrix. The message is enciphered when the leters are written as one goes down the columns in the matrix. For example, if we want to encode: The Github repository has stopped working, we can choose a 4x10 matrix to hold the 36 letters in our message. The 4 extra spaces can befilled with dummy letters, which we will use "x" for. Here is an example below (4x10 matrix): 

| | | | | | | | | | | 
|-|-|-|-|-|-|-|-|-|-|
T | h | e | G | i | t | h | u | b | R |
e | p | o | s | i | t | o | r | y | h | 
a | s | s | t | o | p | p | e | d | w |
o | r | k | i | n | g | x | x | x | x |

When we read this out by column rather than row, we receive our encrypted message: TEAO HPSR EOSK GSTI IION TTPG HOPX UREX BYDX RHWX.

## Decryption
To crack a simple tranposition cipher, you must first count the number of letters in the ciphertext. Then you must determine all the possible matrices that would fit the number of characters, keeping in mind that the area of the matrix can be greater than the number of letters in the ciphertext if accounting for possible dummy letters. Use two of each size in the list of all possible matrices, and write out the ciphertext across by row on one copy while writing it down by column on the other. Repeat this for every single possible matrix until you find anything legible, in which case you most likely cracked the cipher. 


