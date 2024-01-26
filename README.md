# PS1: LFSR / PhotoMagic

## Contact
Name: Patricia Antlitz

Section: 202

Time to Complete: 1 day


## Description
Explain what the project does.

This is a LFSR (Linear Feedback Shift Register) simulator. It works on a binary code which is a Fibonacci sequence. We shift all bits to the left by one, and use the required tap positions and the MSB (Most Significant Bit) to calculate the next bit, to be added to the end of the string. The program uses a XOR logic for the calculation, where: 
0 xor 0 = 0,
0 xor 1 = 1,
1 xor 0 = 1,
1 xor 1 = 0

The tap positions required by the assignment are positions 13, 12 and 10 having the most significant bit at position 15. This code however, uses tap positions 2, 3, and 5 and the MSB position 0, which is the equivalent from left to right.

The given seed is = "1011011000110110""
by running step() will:
calculate the next bit:
((msb xor tap2) xor tap3) xor tap 5 = 
((1 xor 1) xor 1) xor 1 =
(0 xor 1) xor 1 =
1 xor 1 = 0

then removes index 0, shift all bits to the left and add the calculated bit to the end
of the string.

output:
0110110001101100 0

### Features
Describe the representation you used and why you did things that way.

For this project, I decided to use strings, which was not my original approach (more about it below). The reason being, its simple, and in my mind there is no need to make an elaborated code for this. Ultimately, we want to perform that XOR calculation, then get rid of index 0, shift everything to the left and then "append" whatever that calculated number is to the end. A simple int can hold the result of the XOR calculation. And the characters of a string can be accessed by index number. Its also simple to remove the first character, and add a character to the end. 

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

This took me a lot of reading, researching, and I wish I realized sooner that I could easily do this with a string. I spent a full day trying to make vectors work for this and I couldn't get the right output for generate(). I also tried to use bitset after talking about it with my classmate Daury. He mentioned vectors and bitset would be an good approach. I always struggle with putting my ideas in order when I read the assignment's requirements, so I asked him for some directions. Understanding the requirements usually takes a big chunck of my time. 
I started my code using bitset first because after reading about it I thought it was a good approach. However, I didn't want to limit the size of the bits to bitset<16> and such. I also didn't want to set a large amount of bits aside with no need (64). Ideally, I wanted to be able to have a flexible sizing, based on the size of the seed.
So I moved to vectors next, because its shrinkable and expandable. My main problem was not actually the vector itself, but the logic. I was stuck with this code for hours, not able to calculate generate correctly, and honestly, step() was also only 99% right. After trashing everything and moving to a string I realized the problem was that I didnt reset the seed before running generate(), and I didnt initiate the bit before running step(). The logic itself was fine, but Im glad I made the change because it made me see clearly what the problem was. I decided to keep string, even though I could go back to a vector because it made the code simpler.

### Tests
Describe what is being tested in your Boost unit tests.

This code is running a stress test, when a lot of bits are being generated. The idea is to see if the program is able to handle it. On top of the stress test, following the same idea, there is a performance test. This test checks if the program is efficient. There is a test that checks if the seed is a binary number, and a test that checks what the output would be if the seed was smaller, and if it followed certain pattens, such as 111111, or 000000. There is also a test that checks how consistent the outputs are. No destructors were needed, because no memory was allocated.

### Extra Credit
Anything special you did. This is required to earn bonus points.
I kept it simple

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

I discussed this with Daury (what data structure to use).
I discussed PhotoMagic with Mark. He was the one who explained to me no file needed to be created, it was just a command in the Makefile.

sources:

studying:
https://www.eetimes.com/tutorial-linear-feedback-shift-registers-lfsrs-part-1/

https://en.wikipedia.org/wiki/Linear-feedback_shift_register

bitset:
https://en.cppreference.com/w/cpp/utility/bitset

online calculator, to check outputs:
https://www.omnicalculator.com/math/linear-feedback-shift-register

polynomial lfsr example coded in C: and example 
https://www.moria.us/articles/demystifying-the-lfsr/

source: 
https://cs.stackexchange.com/questions/109618/how-fibonacci-lfsr-work

https://www.programiz.com/cpp-programming/examples/fibonacci-series

This is the example that made me realize strings were the best option:
https://github.com/qiaoyuguo/practice/blob/master/cos126/assignments/assign5/LFSR.java

other code sources:
https://github.com/hamolicious/LFSR-RNG/blob/main/lfsrrng/generator.py





