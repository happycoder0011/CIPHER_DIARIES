import string

#Encryption of Text
'''
Text : ATTACKATONCE
Shift: 4
Cipher: EXXEGOEXSRGI
'''
#Decryptiopn of Cipher
'''
Cipher: krclxrwrbxwnxocqnlxxunbcrwencrxwbrwanlnwccrvnb.
Shift: 9
Text:: bitcoinisoneofthecoolestinvetionsinrecenttimes
'''

alpha = string.ascii_letters

def ceaser_decrypt_without_key(target):
    print("DECRYPTING....")
    key = 0
    while key <= 26:
        temp = ""
        for char in target:
            if char.isalpha():
                temp += alpha[(alpha.index(char)-int(key)) % 26]
            else:
                temp += char
        print(temp + " ........... key: ", key)
        key = key + 1


def ceaser_decrypt(target, shift):
    print("DECRYPTING....")
    temp = ""
    temp = ""
    for char in target:
        if char.isalpha():
            temp += alpha[(alpha.index(char)-int(shift)) % 26]
        else:
            temp += char
    print(temp)


def encrypt(text,s): 
    result = "" 
    for i in range(len(text)): 
        char = text[i] 
        if (char.isupper()): 
            result += chr((ord(char) + s-65) % 26 + 65) 
        else: 
            result += chr((ord(char) + s - 97) % 26 + 97) 
  
    return result 
