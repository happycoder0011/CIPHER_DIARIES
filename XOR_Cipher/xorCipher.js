function crypt(input, key) {
  let result = '';
  for (const item of input) {
    result += String.fromCharCode(item.charCodeAt(0) ^ key);
  }
  return result;
}

const encryptedString = crypt('test string', 128);
console.log('Encrypted: ', encryptedString);
const decryptedString = crypt(encryptedString, 128);
console.log('Decrypted: ', decryptedString);
