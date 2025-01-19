# Push\_swap

## Description

The **Push\_swap** project is a coding challenge that involves creating a program to sort a stack of integers using a set of predefined operations. The goal is to sort the stack with the least number of moves possible, implementing efficient sorting algorithms and optimizing performance for different dataset sizes.

The project includes a mandatory part and a bonus part:

- **Mandatory:** Develop a program that sorts integers using two stacks (`stack a` and `stack b`) and predefined operations.
- **Bonus: Is a checker program that  validates the operations output by push\_swap.**

---

## Objectives

- Implement efficient sorting algorithms.
- Minimize the number of operations required to sort the stack.
- Understand and manipulate data structures such as stacks.
- Work within strict constraints of predefined operations.

---

## Features

- Sorting a stack of integers using two stacks.
- Handles edge cases like duplicate numbers, small datasets, and large datasets.
- Includes bonus features:
  - Checker program to verify the validity of the operations.

---

## **Allowed Operations**

The following operations are used to manipulate the stacks:

- `sa` , `sb` , `ss` : Swap the top two elements of stack a, b, or both.

- `pa` , `pb` : Push the top element from one stack to the other.

- `ra` , `rb` , `rr` : Rotate stack a, b, or both upwards.

- `rra` , `rrb` , `rrr` : Rotate stack a, b, or both downwards.

---

## **How to Use**

### Compilation

To compile the program and bonus:

```bash
make
make bonus
```

This will generate the `push_swap` executable for the mandatory part and the `checker` executable for the bonus part.

### Usage

1. **Mandatory Part**
   Run the program with a list of integers to sort:

   ```bash
   ./push_swap 2 1 3 6 5
   ```

   The output will be a list of operations to sort the stack.

2. **Bonus Part**
   Use the `checker` program to validate the operations:

   ```bash
   ./push_swap 2 1 3 6 5 | ./checker 2 1 3 6 5
   ```

   The `checker` program will output `OK` if the stack is correctly sorted or `KO` if not, `Error` in case of an non exisiting operation or non numeric number or doubled numbers.
