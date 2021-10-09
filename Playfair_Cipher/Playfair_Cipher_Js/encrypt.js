import {strip, fillMatrix, getDigrams} from './util';

export default function encrypt(inputString, kw) {
  let matrix = fillMatrix(kw);
  let plainT = strip(inputString);
  let digrams = getDigrams(plainT);
  let encryptedArray = [];
  let tempString = "";
  let letter1;
  let letter2;
  let letterPosition1;
  let letterPosition2;
  let difference;
  let mod5Result;
	let mod4Result;
	let mod6Result;
  let min;
  let max;


  if ( plainT == "" ) {
    console.log("Please input a text to be encrypted.");
		return false;
  }
	for (let i = 0; i < digrams.length; i++) {

		letter1 = digrams[i][0];
		letter2 = digrams[i][1];

		// replace j with i
		if (letter1 == "j") {
			letter1 = "i"
		}
		else if (letter2 == "j") {
			letter2 = "i";
		}

		letterPosition1 = matrix.indexOf(letter1);
		letterPosition2 = matrix.indexOf(letter2);
		min = Math.min(letterPosition1, letterPosition2);
		max = Math.max(letterPosition1, letterPosition2);
		let minDistanceFromEdge = min % 5;
		let maxDistanceFromEdge = max % 5;
		difference = Math.abs(letterPosition1 - letterPosition2);
		mod4Result = difference % 4;
		mod5Result = difference % 5;
		mod6Result = difference % 6;

		// if in the same column
		if (mod5Result == 0) {

			if (letterPosition1 >= 20) { // If at the bottom of column
				tempString += matrix[letterPosition1 - 20]; // go up
				tempString += matrix[letterPosition2 + 5]; // choose element below
			}
			else if (letterPosition2 >= 20) {
				tempString += matrix[letterPosition1 + 5];
				tempString += matrix[letterPosition2 - 20];
			}
			else {
				tempString += matrix[letterPosition1 + 5];
				tempString += matrix[letterPosition2 + 5];
			}
		}
		// if in the same row
		else if ( difference <= 4 && maxDistanceFromEdge > minDistanceFromEdge ) {

			//further verification (diagonal check)
			if (difference == 4) {

				if ( ((max + 1) % 5) == 0 ) {

					if ( ( (letterPosition1 + 1) % 5) == 0 ) {
						tempString += matrix[letterPosition1 - 4];
						tempString += matrix[letterPosition2 + 1];
					}
					else if ( ( (letterPosition2 + 1) % 5) == 0  ) {
						tempString += matrix[letterPosition1 + 1];
						tempString += matrix[letterPosition2 - 4];
					}
				}
			}
				else {

					if ( ( letterPosition1 + 1 ) % 5 == 0 ) {
						tempString += matrix[letterPosition1 - 4];
						tempString += matrix[letterPosition2 + 1];
					}
					else if ( ( letterPosition2 + 1 ) % 5 == 0 ) {
						tempString += matrix[letterPosition1 + 1];
						tempString += matrix[letterPosition2 - 4];
					}
					else {
						tempString += matrix[letterPosition1 + 1];
						tempString += matrix[letterPosition2 + 1];
					}
				}
			}

			// diagonal part
			else {

				let counter = min;
				let rowD = 0;


				// if at the edge of matrix
				if ( (min + 1) % 5 == 0 || minDistanceFromEdge > maxDistanceFromEdge ) {
					/* loop till the desired column is reached */
					while ( Math.abs(counter - max) % 5 != 0 ) {counter--; rowD--;}
				}
				else{
					/* loop till the desired column is reached */
					while ( Math.abs(counter - max) % 5 != 0 ) {counter++; rowD++;}
				}

				if ( letterPosition1 == min ) {
					tempString += matrix[letterPosition1 + rowD];
					tempString += matrix[letterPosition2 - rowD];
				}
				else {
					tempString += matrix[letterPosition1 - rowD];
					tempString += matrix[letterPosition2 + rowD];
				}
			}

			encryptedArray.push(tempString);
			tempString = "";
	}

		return encryptedArray.toString().replace(/,/ig, " ")
}
