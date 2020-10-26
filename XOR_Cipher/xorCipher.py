#!/usr/bin/python

import sys

def encryptDecrypt(inputString):
	xorKey = 'C'; 
	length = len(inputString); 
	for i in range(length): 
		inputString = (inputString[:i] + chr(ord(inputString[i]) ^ ord(xorKey)) + inputString[i + 1:]); 
		print(inputString[i], end = "");
	return inputString; 

if __name__ == '__main__': 
    sampleString = input("Type here: ");
    print("Encrypted String: ", end = "");
    sampleString = encryptDecrypt(sampleString); 
    print("\n");
    print("Decrypted String: ", end = ""); 
    encryptDecrypt(sampleString);