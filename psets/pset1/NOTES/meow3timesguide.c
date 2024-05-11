#include <stdio.h>

void meow(int n);

int main(void)
{

// <-- this is a comment, every row with two slashes is "commented out" and does not talk to the computer.

// the boolean expression: while (true) in a way logically becomes a "forever" loop.
// explanation: the boolean expression: while (2 > 1) also becomes forever, but is messier than just writing: while (true).
// the below program would print meow forever.

// while (true)
// {
//     printf("meow\n");
// }

// lets make the program meow 3 times.

// int counter = 0;
//
// while (counter < 3)
// {
//     printf("meow\n");
//
//     counter = counter + 1;
// }

// the above program should work but let's shorten it a bit.
// a common coding convention for naming basic counters is "i" as in integer.

// int i = 0;
// while (i < 3)
// {
//     printf("meow\n");
//     i = i + 1;
// }

// let's finish up with some "syntactic sugar".
// the line: i = i + 1; can be shortened to (I THINK) i+ = 1;
// and (FOR SURE) even shorter: i++;
// this gives us:

//    int i = 0;
//    while (i < 3)
//    {
//        printf("meow\n");
//        i++;
//    }

// this counter could be made to start from 1 and aim for i <= 3 and even count negatively using the i-- counter.
//
// lets make this program using a "for loop".
// in the for loop: first; i is set to 0, secondly; for i < 3 --> print meow, thirdly; increase i by 1.
// then, because of the syntax structure, which is beyond me, step 2 and 3 is repeated until i is not < 3.

// for (int i = 0; i < 3; i++)
// {
//     printf("meow\n");
// }

// if we want to make a function out of meow we have to name it and declare if it takes an input,
// as well as its return type like this:

// void meow(void)

// we also need to tell the computer what meow does, like this:

// {
//    printf("meow\n");
// }

// please note that functions need to be included in the "boiler plate" before the first "curly brace"
// in order to hide functions away in the bottom of the program i C, you first need to declare your functions up top.
// please see top and bottom for details.

// now we can just enter meow as a function in our program. Now it's even shorter!

//    int i = 0;
//    while (i < 3)
//    {
//        meow();
//        i++;
//    }
//

// wouldn't it be cool if we could make the function even smarter and let us decide how many times it should meow?
// let's achieve this by entering into the function it's action and replacing the value 3 with "n".
// with the function containing the program all we need typ type now is meow and the number of times, like this:

    meow(3);

}

// IS THAT NEAT CODING OR WHAT? We brought the whole code down to one line!
// (exluding ofcourse, boiler plate, and functions hidden out of sight in the bottom)










void meow(int n)
{
        int i = 0;
        while (i < n)
        {
            printf("meow\n");
            i++;
        }
}