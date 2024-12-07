This code assumes parity bits in location 1, 2, 4, 8, 16, 32, ... as per the wikipage linked in assignment.
depending on little endian vs big endian parity bits may be located differently.
decoding uses even parity rather than odd.

each line is considered a new 7 bit "codeword" that will be proccessed one at a time.

the assignment instructions are a bit flawed. it says input is a [7,4] hamming codeword
but then says if their is more than 1 bit flipped then just print an error message.

7,4 hamming code CANNOT fix single bit flips AND detect two bit errors (at the same time) as the distance from other codewords r=3.
this means a codeword with two bit flips will collide with a valid codeword or a codeword with one bitflip so we must assume our data
has 1 or 0 bit flips for it to be decoded into anything meaningful.

if we want to detect 1 and 2 bit flips in a 7,4 hamming code we can only determine if our codeword is valid but the bits wouldn't hold the parity needed to get original 4bit message.

