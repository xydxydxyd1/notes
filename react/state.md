State
=====

A component's memory is called a `state`. Why is this needed?

Reason for States
-----------------

#### Problems ####
- Local variables don't persist across renders.
- Changes to local variables don't make React render again.

#### Solution ####
The `useState` Hook provides
- a state variable that persists across renders
- a setter that prompts for renders for the component.

useState
--------

```typescript
import {useState} from 'react'

const [something, setSomething] = useState(0);
```

- State is like array
	- an array outside stores all the state variables and their setters
	- on first render, new states are created and initialized
	- each render, useState gives everyone their states based
	on the array index
- State is local to a component instance

