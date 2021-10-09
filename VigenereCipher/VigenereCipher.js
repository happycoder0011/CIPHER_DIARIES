const inputText = document.getElementById('inputText');
const cipherKey = document.getElementById('cipherKey');

let mode = 'Encrypt Mode'

inputText.addEventListener('input', function (e) {
  handleCipher()
}, false);

cipherKey.addEventListener('input', function (e) {
  handleCipher()
}, false);

function changeCipherMode(modeSelected) {
  document.getElementById('cipherMode').innerHTML = modeSelected
  mode = modeSelected;
  handleCipher();
}

function handleCipher() {
  if (inputText.value == '' || cipherKey.value == '') {
    return
  }
  if (mode == 'Encrypt Mode')
    crypt(isEncrypt = true)
  else if (mode == 'Decrypt Mode') {
    crypt(isEncrypt = false)
  }
  return
}

function crypt(isEncrypt) {
  let resultTemp = '';

  //we crypt and decrpyt only plain text on lower case so we clean the input and key texts
  let cleanInputText = inputText.value.toLowerCase().replace(/[^a-z]/g, "");
  let cleanCipherKey = cipherKey.value.toLowerCase().replace(/[^a-z]/g, "");


  //the alphabet codes are from a=97 to z=122; the cypher shift the code with the key element at the same index, repeating the key if necessary
  for (character in cleanInputText) {
    charCode = cleanInputText.charCodeAt(character);
    keyCode = cleanCipherKey.charCodeAt(character % cleanCipherKey.length) - 96;

    //to Encrypt we need to add the key element, to Decrypt we need to subtract the key element
    if (!isEncrypt) {
      keyCode = keyCode * -1
    }

    //to cycle the alphabet we need to remove 97 to the code, cycle the alphabet if needed and add 97 again
    //note that +26 is needed to ensure we won't have negative number in case of decrypt
    resultTemp = resultTemp + String.fromCharCode(((charCode - 97 + keyCode + 26) % 26) + 97);

  }
  document.getElementById('result').value = resultTemp;
}
