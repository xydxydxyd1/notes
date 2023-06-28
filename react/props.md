Passing Props
=============

[Source](https://react.dev/learn/passing-props-to-a-component)

React components communicate via *props*. Parent components can give
props to children.

Pass in props like HTML attributes.

Usually write them out (instead of interfacing) for readability.
Use "spread" syntax with restraint.

Children
--------

When nesting contents in a JSX tag, it is passed in a prop called `children`.

### Typescript: PropsWithChildren ###

`React.PropsWithChildren<T>` takes in a type `T` and returns a union of that
type with children types.

```ts
type PropsWithChildren<P> = P & { children?: ReactNode };
```

Props over time
---------------

Props are not static, but are immutable:
- props can update -- components can receive different props over time.
- props can't be changed

[Source](https://blog.logrocket.com/using-react-children-prop-with-typescript/)
