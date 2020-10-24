function crypt(input, key) {
  let result = '';
  for (let i=0;i<input.length;i++) {
    result += String.fromCharCode(input.charCodeAt(i) ^ key.charCodeAt(i%key.length));
  }
  return result;
}

const key = 'RandomString'
const encryptedString = crypt('this is a test string 123456', key);
console.log('Encrypted: ', encryptedString);
const decryptedString = crypt(encryptedString, key);
console.log('Decrypted: ', decryptedString);
