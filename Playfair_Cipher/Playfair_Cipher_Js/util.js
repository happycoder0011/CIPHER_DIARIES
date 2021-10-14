function strip(text) {

  var splitString = "";

  for (var item in text) {

    var letter = text.charAt(item);

    // ignore whitespace and append to string
    if (letter.search(/\s|\W|\d/igm) == -1) {
      splitString += letter;
    }
  }
  return splitString;
}

function fillMatrix(keyText) {
  var userInput = keyText;
  var matrix = new Array(25);
  var matrixIndex = 0;
  var keyIndex = 0;
  var alphabet = "abcdefghijklmnopqrstuvwxyz";

  // strip whitespace
  userInput = strip(userInput);
  userInput = userInput.toLowerCase();

  // Fill in the keyword
  while ( keyIndex < userInput.length ) {
    var letter = userInput.charAt(keyIndex);
    if ( matrix.indexOf(letter) == -1 ) {
      matrix[matrixIndex] = letter;
      matrixIndex++;
    }
    keyIndex++;
  }
      // Insert unique letters from the alphabet
      for (var item in alphabet) {
        var literal = alphabet.charAt(item);

        //check both uppercase and lowercase letters
        var letterNotInMatrix = (matrix.indexOf(literal) +
          matrix.indexOf(literal.toUpperCase()) == -2);

        // if the letter is not in the matrix (-1 + -1)
        if ( letterNotInMatrix   ) {
          // Skip i or j if already in matrix
          if ( (literal == "i" || literal == "I") && (matrix.indexOf("j") == -1 &&
                matrix.indexOf("J") == -1 ) ) {
                  matrix[matrixIndex] = literal;
                  matrixIndex++;
                }
          // replace j with i
          else if ( literal == "j" || literal == "J" &&
              (matrix.indexOf("i") == -1 && matrix.indexOf("I") == -1 ) ) {}
          else {
            matrix[matrixIndex] = literal;
            matrixIndex++;
          }
        }
      }
  return matrix;
}

function getDigrams(text) {

  var count = 0;
  var input = text.toLowerCase();
  var tempDigram = "";
  var textLength = input.length;
  var digramLength;
  var letter;
  var array = [];

  while (count < input.length) {

    digramLength = tempDigram.length;
    letter = input.charAt(count);

    if ( digramLength == 0 ) {
      tempDigram += letter;
    }
    else if ( digramLength == 1 ) {
      var str = tempDigram.charAt(0);
      if (  str == letter ) {
        tempDigram += "x";
        count--; // stay at the current char
      }
      else {
        tempDigram += letter;
        array.push(tempDigram);
        tempDigram = "";
      }
    }
    else {
      array.push(tempDigram);
      tempDigram = "";
      tempDigram += letter;
    }

    // check odd ending
    if ( textLength % 2 != 0 && count == input.length - 1
          && tempDigram.length % 2 != 0 ) {
      tempDigram += "x";
      array.push(tempDigram);
    }
    // check odd letters
    else if (count == input.length - 1 && tempDigram.length != 0) {
        tempDigram = letter + "x";
        array.push(tempDigram);
    }
    count++;
  }

  return array;
}

export {
	strip,
	fillMatrix,
	getDigrams
}
