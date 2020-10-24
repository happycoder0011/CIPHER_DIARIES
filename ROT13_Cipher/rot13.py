"""
ROT13 implementation in Python
"""


def rot13(message: str):
    cipher = ''
    for char in message:
        i = ord(char)
        if 65 <= i <= 90:
            i = (i + 13 - 65) % 26 + 65
        elif 97 <= i <= 122:
            i = (i + 13 - 97) % 26 + 97
        cipher += chr(i)
    return cipher


if __name__ == '__main__':
    text = input('Enter your message/ciphertext: ')
    print('ciphertext: ' + rot13(text))
