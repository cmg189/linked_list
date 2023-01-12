# Linked List

This program implements a double linked list in C++

Objects of an Employee class or stored in this linked list.
These objects contain basic employee information such as thier name, ID, position, and salary.

## Table of Contents

1. [Description](#desc)
2. [Program Output](#output)
3. [Compile and Execute](#exe)
4. [Function Headers](#func)
5. [Classes](#class)
6. [Resources](#res)

## Description <a name="desc"></a>

A linked list is a data structure that holds a collection of data elements refered to as nodes.
Nodes in a linked list reference their neighbooring node by a pointer.
A linked list's memory is allociated dynamically during run time, as opposed to an array who's memory is typically allociated during compilation.

There are two main types of linked lists

1. Single linked list: Each node has a reference to the next node in the list, but not the previous node.

2. Double linked list: Each node has a reference to both the next node, and the previous node, in the list.

## Program Output <a name="output"></a>

## Compile and Execute <a name="exe"></a>

- Windows
  To compile run the command: `g++ main.cpp headers.cpp -o list`

  To execute run the command: `list.exe`

- Linux / Mac
  To compile run the command: `g++ main.cpp headers.cpp -o list`

  To execute run the command: `./list`
  

## Function Headers <a name="func"></a>

```cpp

```

- Description

- Parameters

- Return

---

## Classes <a name="class"></a>

```cpp
class Employee
```

- Description

  This class represents a company's employee details

- Public Member Functions

  Constructors:

  `Employee()` Default constructor

  `Employee(string name, int id, string position, float salary)` Parameterized constructor

  Accessors:

  `string get_name()` Returns an employee's name

  `int get_id()` Returns an employee's ID

  `string get_position()` Returns an employee's position

  `float get_salary()` Returns an employee's salary

  Mutators:

  `void set_name(string name)` Assigns an employee's name

  `void set_id(int id)` Assigns an employee's ID

  `void set_position(string position)` Assigns an employee's position

  `void set_salary(float salary)` Assigns an employee's salary

- Private Member Variables

  `string name` Represents an employee's name

  `int id` Represents an employee's id

  `string position` Represents an employee's position

  `float salary` Represents an employee's salary

## Resources <a name="res"></a>
