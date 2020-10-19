# Python program to demonstrate 
# Substitution Cipher 

import string
import re
  
  
# A list containing all characters 
all_letters = string.ascii_letters
   
      
"""  
create a dictionary to store the substitution  
for the given alphabet in the plain text  
based on the key 
"""

key = input("Enter a keyword: ")
key = key.strip()
ciph_alpha = ""
for c in key:
    if c in all_letters and not(c.lower() in ciph_alpha):
        ciph_alpha += c.lower()
for c in all_letters[:26]:
    if not(c in ciph_alpha):
        ciph_alpha += c
      
dict1 = {}
   
for i in range(26): 
    dict1[all_letters[i]] = ciph_alpha[i]
    dict1[all_letters[i+26]] = ciph_alpha[i].upper()

print("Plaintext alphabet:   "+all_letters[26:])
print("Ciphertext alphabet:  "+ciph_alpha.upper())

plain_txt = input("Enter your message:   ")
cipher_txt = ""
   
# loop to generate ciphertext 
   
for char in plain_txt: 
    if char in all_letters: 
        cipher_txt += dict1[char]
    else:
        cipher_txt += char
          
print("Ciphertext:          ",cipher_txt) 
      
"""  
create a dictionary to store the substitution 
for the given alphabet in the cipher  
text based on the key 
"""
   
      
dict2 = {}      
for i in range(26): 
    dict2[ciph_alpha[i]] = all_letters[i]
    dict2[ciph_alpha[i].upper()] = all_letters[i+26]
       
# loop to recover plain text 
decrypt_txt = ""
  
for char in cipher_txt: 
    if char in all_letters: 
        decrypt_txt += dict2[char]
    else: 
        decrypt_txt += char
          
print("Recovered plaintext :", decrypt_txt)  