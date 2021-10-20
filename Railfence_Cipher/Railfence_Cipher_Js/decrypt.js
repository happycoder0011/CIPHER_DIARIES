'use strict';

const fs = require('fs');
// input is provided by config.json file
let input = JSON.parse(fs.readFileSync('config.json'));
// input.depth : depth for algorithm
// input.text : text to encrypt

const CHARACTER_LITERAL = '#';
const EMPTY_LITERAL = ' ';

function toPlainText(input, matrix) {
    let plainText = '';
    let update = +1;
    for (let col = 0, row = 0; col < input.text.length; col++) {
        if (row == 0)
            update = +1;
        if (row == input.depth - 1)
            update = -1;
        plainText += matrix[row][col];
        row += update;
    }
    return plainText;
}

function fillMatrix(input, matrix) {
    let itr = 0;
    for (let i = 0; i < input.depth; i++) {
        for (let j = 0; j < input.text.length; j++) {
            if (matrix[i][j] === CHARACTER_LITERAL)
                matrix[i][j] = input.text[itr++];
        }
    }
}

function initMatrix(input, matrix) {
    let update = +1;
    for (let col = 0, row = 0; col < input.text.length; col++) {
        if (row == 0)
            update = +1;
        if (row == input.depth - 1)
            update = -1;
        matrix[row][col] = CHARACTER_LITERAL;
        row += update;
    }
    return update;
}

function decrypt(input) {
    let matrix = new Array(input.depth);
    for(let i = 0; i < input.depth; i++) 
        matrix[i] = new Array(input.text.length).fill(EMPTY_LITERAL);
    
    initMatrix(input, matrix);

    fillMatrix(input, matrix);

    let plainText = toPlainText(input, matrix);
    return plainText;
}

console.log(decrypt(input));

module.exports = decrypt;