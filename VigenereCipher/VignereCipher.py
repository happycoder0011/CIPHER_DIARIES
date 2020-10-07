# Python code to implement Vigenere Cipher 

# This function generates the key in a cyclic manner until it's length isn't equal to the length of original text 
def generateKey(string, keyword): 
    keyword = list(keyword) 
    if len(string) == len(keyword):
        return keyword
    else: 
        for i in range(len(string) - len(keyword)):
            keyword.append(keyword[i % len(keyword)])
        return "" . join(keyword)

# This function returns the encrypted text generated with the help of the key 
def encrypt(string, keyword): 
    key = generateKey(string, keyword)
    cipher_text = [] 
    for i in range(len(string)): 
        x = (ord(string[i]) +
             ord(key[i])) % 26
        x += ord('A') 
        cipher_text.append(chr(x)) 
    return "" . join(cipher_text)

# This function decrypts the encrypted text and returns the original text 
def decrypt(cipher_text, keyword):
    key = generateKey(cipher_text, keyword)
    orig_text = [] 
    for i in range(len(cipher_text)): 
        x = (ord(cipher_text[i]) -
             ord(key[i]) + 26) % 26
        x += ord('A') 
        orig_text.append(chr(x)) 
    return "" . join(orig_text)

# Driver code 
if __name__ == "__main__": 
    string = "ATTACKATDAWN"
    keyword = "ABCD"
    cipher_text = encrypt(string, keyword) 
    print("Ciphertext :", cipher_text) 
    print("Original/Decrypted Text :", decrypt(cipher_text, keyword)) 

