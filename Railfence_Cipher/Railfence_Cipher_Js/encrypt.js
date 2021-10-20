'use strict';

const fs = require('fs');
// input is provided by config.json file
let input = JSON.parse(fs.readFileSync('config.json'));
// input.depth : depth for algorithm
// input.text : text to encrypt

function encrypt(input) {
	let buffers = [];
	for (let i = 0; i < input.depth; i++) {
		buffers.push('');
	}

	let itr = 0;
	let update = +1;

	for (let character of input.text) {
		buffers[itr] += character;
		itr += update;
		if (itr == 0) {
			update = +1;
		} else if (itr == input.depth - 1) {
			update = -1;
		}
	}
	
	return buffers.join('');
}

console.log(
	encrypt(input)
);

module.exports = encrypt;