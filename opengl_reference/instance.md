# Instance

Instancing is a rendering technique that allows us to render multiple objects of the same mesh in a single call.
This solves a common bottleneck of rendering, CPU to GPU data transfer. 
Instead of sending the same mesh multiple times in many different calls, we can call the an instsance render to render multiple objects all at once, allowing us to condense all the information into contigous blocks of data. 
Doing this opens the door for fast, efficent, and GPU friendly rendering.

## Implementation

TODO