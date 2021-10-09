
def _expand_key(key, n):
    """
     The key is expanded cyclically to be equal to the length of the text. 
    Args:
        key (str): The key provided by the user
        n (int): Length of the plain text
    Returns:
        str: Expanded key.
    """
    temp_key, pos = [], 0
    while(pos < n):
        temp_key.append(key[pos % len(key)])
        pos += 1
    return "".join(temp_key)

def encrypt(text, key):
    """ returns the encrypted text generated with the help of the key 

    Args:
        text (str): The plaintext provided by the user
        key (str): The key provided by the user

    Returns:
        str: Generated Ciphertext
    """
    key = _expand_key(key, len(text))
    encryption = []    
    for x, k in zip(text, key):
        encryption.append(chr((ord(x)-ord('a') + ord(k)-ord('a')) % 26 + ord('a')))
    return "".join(encryption)

def decrypt(text, key):
    """Decrypts the encrypted text and returns the original text 

    Args:
        text (str): The ciphertext provided by the user
        key (str): The key provided by the user

    Returns:
        [type]: [description]
    """
    key = _expand_key(key, len(text))
    decryption = []    
    for x, k in zip(text, key):
        decryption.append(chr(((ord(x)-ord('a')) - (ord(k)-ord('a')) + 26) % 26 + ord('a')))
    return "".join(decryption)


def main():
    """Driver method.
    """
    print("Select Action:\n1. Encrypt a string.\n2. Decrypt a string.")

    while True:
        objective = int(input("Enter Option (1 or 2): "))
        if(objective==1 or objective==2):
            break
        else:
            print("Enter 1 or 2. Try again!")
    
    text = input("Enter string:\n")
    key = input("Enter key: ")
    
    words = []
    for c in text:
        if c.isalpha(): words.append(c)

    if(objective == 1):
        result = (encrypt("".join(words).lower(), key.lower()))
    elif(objective == 2):
        result = (decrypt("".join(words).lower(), key.lower()))
    
    print("\nResult :----")
    j = 0
    for c in text:
        if c.isalpha(): 
            print(result[j], end='')
            j += 1
        else: print(c, end='')
        
    
if __name__ == "__main__":
    main()
