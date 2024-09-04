# Topic 1 Introduction to Data and Algorithms 

## *week 1 class 1* 

### *What are ethics / morals?* 
*they're not interchangable!!*
- Morals = based on situational diagnosis.

- Ethics = Based on grand instruction? 


### *What is an algorithim*

- Algorithims are always the same. Set of unambigeous steps of instructions. 

- Algorithims allow devs to manipulate data more effectivly 

- Example: Recursive alogrithim

- GCD is an example; to find GCD we use: gcd (m,n) = gcd (n , m mod n). **mod n** is the integer remainder. 
 Euclids algorithim --------------------------------^ 

Example: GCD (60,24) = GCD (24, 12) ----> GCD (12,0)

-1. if n = 0 return m and stop 
-2. divide m by n and assign the value of the remainder to r
-3. assign the value of n to m and the value of r to n 

- *psuedo-code example*
```psuedo
while n ! = 0 do
r = m mod n
m = n
n = r 
return m 
```

- what is an input to an algorithim called? *an instance*
- How often should an algorithim work correctly?
  
- Random Access Memory:
  1.) allocates temporary storage / built as an array.
  2.) a sequential alogrithim will run in ram.
  3.) newer computers have multiple processors running concurently(concerancy is very important).
  4.) algos that run concerently are called parallel algorithims and implemented with threading.

- Two issues that effect algos and how they work
 1.) Exact: more accurate
 2.) Generality: may have a rounding error

 - Algo Design techniques
1.) Get it working then optimize
2.) document algorithims with psuedo-code + flowcharts + conversation.
3.) Natural language is the most problematic of the 3.
4.) ensure your models are clearly communicated and show failure cases.
5.) OPTIMIZE after getting it to work.

    
