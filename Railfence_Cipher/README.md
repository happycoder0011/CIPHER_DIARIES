# Rail Fence Cipher

## Encryption

To use the Rail Fence Cipher, you have to write your message in zigzag lines across the page, and then read off each row. Firstly, you need to have a key, which for this cipher is the number of rows you are going to have. You then start writing the letters of the text diagonally down to the right until you reach the number of rows specified by the key. You then bounce back up diagonally until you hit the first row again. This continues until the end of the text.
For the text "Hacktoberfest-2020", with a key of 3, we get the encryption process shown below.

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| H   |     |     |     | t   |     |     |     | r   |     |     |     | t   |     |     |     | 2   |     |     |
|     | a   |     | k   |     | o   |     | e   |     | f   |     | s   |     | -   |     | 0   |     | 0   |     |
|     |     | c   |     |     |     | b   |     |     |     | e   |     |     |     | 2   |     |     |     | X   |

Note that at the end of the message we have inserted an "X". These are called nulls, and act as placeholders. We do this to make the message fit neatly into the grid (so that there is the same number of letters on the top row, as on the bottom row. Although not necessary, it makes the decryption process a lot easier if the message has this layout.
The ciphertext is read off row by row to get "Htrt2akoefs-00cbe2X".

## Decryption

The decryption process for the Rail Fence Cipher involves reconstructing the diagonal grid used to encrypt the message. We start writing the message, but leaving a dash in place of the spaces yet to be occupied. Gradually, you can replace all the dashes with the corresponding letters, and read off the text from the table.
We start by making a grid with as many rows as the key is, and as many columns as the length of the ciphertext. We then place the first letter in the top left square, and dashes diagonally downwards where the letters will be. When we get back to the top row, we place the next letter in the ciphertext. Continue like this across the row, and start the next row when you reach the end.
For example, if you receive the ciphertext "HHga anXpyciXpkX", encrypted with a key of 4, you start by placing the "H" in the first square. You then dash the diagonal down spaces until you get back to the top row, and place the "H" here. Continuing to fill the top row you get the pattern below.

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| H   |     |     |     |     |     | H   |     |     |     |     |     | g   |     |     |     |
|     | -   |     |     |     | -   |     | -   |     |     |     | -   |     | -   |     |     |
|     |     | -   |     | -   |     |     |     | -   |     | -   |     |     |     | -   |     |
|     |     |     | -   |     |     |     |     |     | -   |     |     |     |     |     | -   |

Continuing this row-by-row, we get the successive stages shown below.
Our result from the second stage in the decryption process.

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| H   |     |     |     |     |     | H   |     |     |     |     |     | g   |     |     |     |
|     | a   |     |     |     |     |     | a   |     |     |     | n   |     | X   |     |     |
|     |     | -   |     | -   |     |     |     | -   |     | -   |     |     |     | -   |     |
|     |     |     | -   |     |     |     |     |     | -   |     |     |     |     |     | -   |

The third stage in the decryption process.

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| H   |     |     |     |     |     | H   |     |     |     |     |     | g   |     |     |     |
|     | a   |     |     |     |     |     | a   |     |     |     | n   |     | X   |     |     |
|     |     | p   |     | y   |     |     |     | c   |     | i   |     |     |     | X   |     |
|     |     |     | -   |     |     |     |     |     | -   |     |     |     |     |     | -   |

The fourth and final stage in the decryption process.
From this we can now read the plaintext off following the diagonals to get "Happy Hacking".

|     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| H   |     |     |     |     |     | H   |     |     |     |     |     | g   |     |     |     |
|     | a   |     |     |     |     |     | a   |     |     |     | n   |     | X   |     |     |
|     |     | p   |     | y   |     |     |     | c   |     | i   |     |     |     | X   |     |
|     |     |     | p   |     |     |     |     |     | k   |     |     |     |     |     | X   |

<sub><a href="https://crypto.interactive-maths.com/rail-fence-cipher.html">Source</a></sub>
