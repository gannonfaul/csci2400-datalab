/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: gafa8660 */
    "gafa8660", 
   /* Student name 1: Gannon Faul */
   "Gannon Faul",
   /* Login ID 1: gafa8660 */
   "gafa8660",
   /* Student name 2: */
   "",
   /* Login ID 2: */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4
// rating 1
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /* 
   * Use DeMorgan's Law to create ^ with & and ~
   * A ^ B = ~(A | B)
   * DeMorgan's Law: ~(A | B) = ~A & ~B
   * Thus: A ^ B = ~A & ~B
   */  
  return (~x) & (~y);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /*
   * Return max two's complement integer (0 followed by 31 1's)
   */

  // Set x = 1
  int x = 1;

  // Left shift x by 31 to get 1 followed by 31 0's, 
  // Negate to get 0 followed by 31 1's
  return ~(x << 31);
}
// rating 2
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  // Determine if x can be represented as an n-bit binary number
  // Cannot simply right shift by n-1 because negative numbers in 
  // two's complement have leading 1's

  // Right shift x by 31 to determine sign of x
  // Create mask to set all bits to sign
  int signMask = ~((x >> 31) & 1) + 1;

  // XOR signMask with x to turn all leading bits to zero
  // Right shift result by n - 1. If nonzero number is left, the bits don't fit
  // NOT to return opposite of shift result
  return !((x ^ signMask) >> (n + ~0));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  // if x < 0, must be altered so that it rounds towards zero

  // AND sign of x with (1 in the nth bit position minus 1) to get either:
  //       a. zero if x is positive, or 
  //       b. 1 less than a 1 in the nth bit if x is negative

  // ADD to x so that the result is either:
  //     a. x if x is positive, or
  //     b. x + 1 less than a 1 in the nth bith position if x is negative,
  //        which is equal to x + 1
  x = x + ((x >> 31) & ((1 << n) + ~0));

  // Right shift by n
  return x >> n;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  // XOR will result in 0 if x == y because only different bits will produce a 1
  // Must !! to ensure function returns 0 or 1
  return !!(x ^ y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  // A ^ B = (A | B) & ~(A & B)
  // A | B = ~(~(A | B))
  // DeMorgan's Law:
  // ~(~(A | B)) = ~(~A & ~B)
  // Thus:
  // A ^ B = ~(~A & ~B) & ~(A & B)
  return ~(~x & ~y) & ~(x & y);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  // AND x with 1 to get all 0's or a 1 only in the LSB position
  int result = x & 1;

  // Negate result to get all 1's or all 1's with a zero in the LSB position
  // Add 1 because if all 1's, the addition will carry through and turn all
  // bits to zero, if the LSB is a 0, the 1 will add in with no carry and the
  // result will be all 1's
  return ~result + 1;
}
// rating 3
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) { 
  // Shift MSByte to the LSByte position
  // AND with 0xff to ensure only LSByte is populated
  int segment1 = (x >> 24) & 0xff;

  // Shift 2nd MSByte to the LSByte Position
  // AND with 0xff to ensure only LSByte is populated
  int segment2 = (x >> 16) & 0xff;
  // Shift Byte back to correct position
  segment2 = segment2 << 8;

  // Shift 3rd MSByte to LSByte position
  // AND with 0xff to ensure only LSByte is populated
  int segment3 = (x >> 8) & 0xff;
  // Shift back to the correct position
  segment3 = segment3 << 16;

  // Shift LSByte to the MSByte position
  int segment4 = x << 24;

  // OR all segments together so that all bytes are returned in reverse order
  return (segment1| segment2 | segment3 | segment4);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // Shift x to the right by n bits
  x = x >> n;
  
  // Send 1 to the MSB position 
  int shiftPosition = 1 << 31;

  // Shift 1 back to the right n - 1 positions and negate 
  shiftPosition = ~(shiftPosition >> (n + ~0));

  // AND x with shiftPosition so that zero's after the shift position cancel 
  // out any 1's in x
  return x & shiftPosition;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  // ADD x to negation of y and right shift to find sign
  // signDifference will equal 1 if positive and 0 if negative
  int signDifference = !((x + ~y) >> 31);

  // Right shift x and y to find signs
  x = x >> 31;
  y = y >> 31;

  // AND !x with y which will result in a 1 if x is positive and y is negative

  // AND signDifference with (~x | y) which will result in a 1 if both: 
  //      a. (x + ~y) is positive, and
  //      b. either x is positive or y is negative

  // OR the above ANDs together because if either of them are > 0 then x > y
  // !! the result to get a 0 or 1
  return !!((~x & y) | (signDifference & (~x | y))); 
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  // Create mask of 1's from highbit + 1 to MSB
  int highMask = ~0 << highbit;
  highMask = highMask << 1;

  // Create mask of 1's from 0 to lowbit
  int lowMask = ~0 << lowbit;

  // XOR highMask ^ lowMask. Bits between highbit and lowbit will be different
  // resulting in a 1, all other bits are equal, resulting in 0's. 
  int mask = highMask ^ lowMask;

  // AND with lowMask because if lowbit > highbit, this will set all bits less 
  // than lowbit to zero
  return mask & lowMask;
}
// rating 4
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  // Negate sign of x to get either:
  //     a. all 1's if x is positive
  //     b. all 1's with a 0 is the LSB position if x is negative

  // ADD the above negation with 1 to get either:
  //     a. all 0's due to the carry of the 1 to the next bit
  //     b. all 1's by adding 1 to situation b. from the above negation

  // XOR x with sign of x to get either:
  //     a. x if x is positive (sign will be 0)
  //     b. x - 1 if x is negative (sign will be 1). This is equal to the 
  //        1's complement of the absolute value of x

  // ADD these two results together to get either:
  //     a. x + 0 if x is positive
  //     b. (1's complement of the magnitude of x) + ~0. This flips the bits
  //        to result in the positive magnitude of x.

  return (~(x >> 31) + 1) + (x >> 31 ^ x);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // Create 32-bit mask of form 00010001...
  int temp = 0x11;
  int mask = (temp << 8) | temp;
  mask = (mask << 16) | mask;

  // AND x with mask to get a 1 in the LSB position of every 4-bits of numBits
  // if the same bit in x is a 1
  int numBits = x & mask;

  // Right shift x by 1 bit and repeat the AND to get a 1 in the LSB position
  // of every 4 bits if the same bit in x >> 1 is a 1

  // Add result to numBits total so that every 4 bits of numBits is the total
  // number of 1's in first two bits of the same 4 bit segment in x
  numBits = numBits + ((x >> 1) & mask);

  // Repeat for the 3rd and 4th bit in every 4 bits
  numBits = numBits + ((x >> 2) & mask);
  numBits = numBits + ((x >> 3) & mask);

  // Every 4 bits in numBits now represents the total number of 1's in the 
  // corresponding 4 bit segments of x

  // Add the first and second 4 bit segments of numBits together to get the
  // total number of 1's in the least significant byte of x
  int LSByte = (numBits & 0xf) + ((numBits >> 4) & 0xf);

  // Repeat for the second, third, and fourth bytes of x
  int secondByte = ((numBits >> 8) & 0xf) + ((numBits >> 12) & 0xf);
  int thirdByte = ((numBits >> 16) & 0xf) + ((numBits >> 20) & 0xf);
  int MSByte = ((numBits >> 24) & 0xf) + ((numBits >> 28) & 0xf);

  // Add these totals together to get the total number of 1's in x and return
  return (LSByte + secondByte + thirdByte + MSByte); 
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  // Determine if sign changes between x and 2's-complement of x
  //
  // Take 2's-complement: n and x will have different signs iff x != 0
  int n = ~x + 1;
  // If 32nd bit of both x and n is 0, x = 0. AND with 1 to get 1 or 0 return  
  return (n >> 31 | x >> 31) & 1;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // Evaluate isNonZero(x) then XOR with 1 to negate
  //
  // Take 2's-complement: n and x will have different signs iff x != 0
  int n = ~x + 1;
  // If 32nd bit of both x and n is 0, x = 0, XOR with 1 to negate 
  return ((n >> 31 | x >> 31) & 1) ^ 1;
}
