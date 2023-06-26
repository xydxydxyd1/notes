Template Parameters
===================

Template parameters can be non-type, type, or template.

```cpp
template <parameter_list> require_clause* declaration;
template <parameter-list> concept concept-name = constraint-expression;
```
*require_clause* is optional; see [Constraints and Concepts](#constraints-and-concepts)

Specialization and Instantiation
--------------------------------

When template parameters are received (i.e. a definition with things in angle brackets),
it is a *specialization* of the template given

When used like normal, the specialization is *instantiated.* I'm not worrying too much
about it.

```cpp
template <typename T>
struct Struct
{

     T x;
};

template<>
struct Struct <int> // explicit specialization
{

    //code
};

template struct Struct<char>;	// explicit instantiation

int main()
{
   Struct <int> s; // use explicit specialization
   Struct <float> r; // implicit instantiation

```

+ TODO: Test explicit instantiation declaration after studying linkage <26-06-23, xydxydxyd1> +

- Explicit instantiation is used to control the place the template is instantiated
- `extern` explicit instantiation declaration is for using a single explicit
instantiation somewhere, instead of implicitly declaring it all the time.
- Also checkout [Partial Specialization](#partial-specialization).
- Example from [Stack Overflow](https://stackoverflow.com/questions/3914642/difference-between-instantiation-and-specialization-in-c-templates)

Class Templates
===============

Template Instantiation
----------------------

A class template by itself is nothing; no code is generated. Code appears
when the template is *instantiated* (note: not specialized).

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
	template<typename T1, typename T2>
	class is_pointer
	{
	public:
		static const bool value = false;
	};

	template<typename T2>
	class is_pointer<T2*, T2>
	{
	public:
		static const bool value = true;
	};

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
