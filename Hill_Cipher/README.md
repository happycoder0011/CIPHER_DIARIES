
# Hill Cipher

Hill cipher is a polygraphic substitution cipher based on linear algebra.Each letter is represented by a number modulo 26. Often the simple scheme A = 0, B = 1, …, Z = 25 is used, but this is not an essential feature of the cipher. To encrypt a message, each block of n letters (considered as an n-component vector) is multiplied by an invertible n × n matrix, against modulus 26. To decrypt the message, each block is multiplied by the inverse of the matrix used for encryption.

The matrix used for encryption is the cipher key, and it should be chosen randomly from the set of invertible n × n matrices (modulo 26).
### EXAMPLE
Input  : Plaintext: ACT
         Key: GYBNQKURP
Output : Ciphertext: POH

Input  : Plaintext: GFG
         Key: HILLMAGIC 
Output : Ciphertext: SWK

                                             ## Encryption

We have to encrypt the message ‘ACT’ (n=3).The key is ‘GYBNQKURP’ which can be written as the nxn matrix: 

                       A=  keyMatrix[3][3] = {(6,24,1),(13,16,10),(20,17,15)}

Since 'A' is 0, 'C' is 2 and 'T' is 19, the message is the vector:    

                        B=   messageMatrix[1][3]= {(0),(2),(9)}
           
The enciphered vector is given as:

       C = (A*B)mod 26
       c ={(15),(14),(7)}
   which correspond to ciphertext of 'POH'   
                                
                                
                                                  ## Decryption
  In order to decrypt, we turn the ciphertext back into a vector, then simply multiply by the inverse matrix of the key matrix mod 26.This will provide matrix
  of our meassage.
