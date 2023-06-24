General
=======

Traits and concepts beef up generic programming by placing restrictions
on template arguments.

A *concept* models semantic categories, whereas a *type trait* models
syntactic categories.


Type Traits
===========

Feature is introduced in C++14

Type traits allow one to ask questions to the compiler: does this type have
a destructor? Is it a floating point? etc.

It also allows you to do some transformations, such as removing `const` and
`reference`.

A *type trait* is a template struct containing a member constant, which holds
the answer to the question the type trait asks (or does some transformation).

Partial Specialization
----------------------

For customizing a template for specific sets of template arguments

```cpp

```



Constraints and Concepts
========================


Class templates and function templates can have *constraints*:
requirements on the template arguments.

Sets of constraints are called *concepts*.

Concepts model semantic categories, as opposed to syntactic.

Sources
=======

[Informative blog by Jakub Konka](https://www.jakubkonka.com/2017/09/02/type-traits-cpp.html)

[Link to Documentation](https://en.cppreference.com/w/cpp/language/constraints)

[Quick Primer on Type Traits](https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp)

[Discussion Section on Traits](https://github.com/ecs36c-sq2023/ecs36c-discussions/blob/main/discussion8.md)

[Partial Specilizaiton](https://en.cppreference.com/w/cpp/language/partial_specialization)
