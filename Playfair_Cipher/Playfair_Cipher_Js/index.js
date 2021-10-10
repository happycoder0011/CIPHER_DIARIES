import encrypt from './encrypt.js'
import decrypt from './decrypt.js'

// Your key to encrypt the text
const keyText = 'blameme';
const text = "chamingo";

// ENCRYPT your text
const encryptedText = encrypt(text, keyText);
console.log(encryptedText);

// DECRYPT your text
const decryptedText = decrypt(encryptedText, keyText);
console.log(decryptedText)