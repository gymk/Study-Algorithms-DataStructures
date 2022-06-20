# Bit Manipulation

## XOR `^`

- XOR of two numbers gives a number which enables transforming one number to another

```text
  38 and 78
    38 ==> 0011 1000
    78 ==> 0111 1000
    --     ---------
  ^        0100 0000 ==> 64
    64 is the common number which will enable 38 to transform into 78 and 78 to transform into 38

  38 ^ 64 will give 78
  78 ^ 64 will give 38
```

## Toggling rightmost `1` - `x & (x-1)`

- Since the difference between current and previous natural number is 1
  - It will remove rightmost `1` bit
    - See the [code](diff_bet_two_conq_no.cpp)

## Get rightmost bit

- `x ^ (x & (x-1))`
  - Since `x & (x-1)` will toggle rightmost bit of `x`
    - Since diff of two contiguous natural number is `1`
  - Doing XOR will give will give our result

## Study Links

- [XOR - The magical bitwise operator](https://hackernoon.com/xor-the-magical-bit-wise-operator-24d3012ed821)
