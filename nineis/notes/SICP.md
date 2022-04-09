# SCIP course notes
--------

This plan gonna begin in 4.9 and each day for a part

## Lec1a: Lisp概览


### Part1 technique for controlling complexity
- black-box abstraction
- Conventional interfaces
- Metaliguistic abstraction -- making new languages

### Part2 General framework
- primitive elements
- means of combination
- measn of abstraction

``` Lisp
 (+ 3 17.4 5)   = 25.5
```

![Introcution](./pics/Introduction.png)

**syntactic sugar** 
![Lambda](./pics/Lambda.png)

``` Lisp

//**RECURSIVE DEFINITION** 
// x for the orginal number while guess for the guess number
// so in this example 'guess' and 'x' are all primitive elements
// while "try" | "good-enough" | "average" and so on are means of combination

(DEFINE (TRY GUESS X)
    (IF (GOOD-ENOUGH? GUESS X)
        GUESS
        (TRY (IMPROVE GUESS X) X)))
        
(define (improve guess x)
    (average guess (/ x guess)))
    
// process (good-enough? guess x) return false or true

(define (good-enough? guess x)
    (< (abs (- (square guess) x)) .001))
    
```

![square-box](./pics/square-box.png)
- block structure

Q: what's the difference between the clause
    (define A (* 5 5)) AND (define (D) (* 5 5))
A: In the Lisp command, input 
    A -> 25 while the second
    D -> compound procedure D
    (D) -> 25 //running procedure D
    (A) -> error
    
    for A is the primitive element while D is a procedure
    
