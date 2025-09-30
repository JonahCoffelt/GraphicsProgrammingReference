# Engine Design Basics

At this point, though not explicity stated, the design paradigm of this reference guide has been to take some OpenGL/GLFW behavior and abstract it by object-oriented encapsulation. 
As graphics programmers, this has been good for us because we know all of the expected behvaior for objects like `VBO`s and `VAO`s. 
These abstractions allow use to more easily and clearly work on progressivly advanced techniques. 
However, even a simple scene has become around 100 lines of boilerplate code, which is not ideal. 
Additionally, people who many want to use this engine but do not have knowledge about graphics programming will strugle and likely choose a more understandable alternative. 
So at this point, we should shift gears and think about how to best design an engine for developers.


## Insipration

Lucky for us, there are plenty of great engines out there that already have established design paradigms for us to use. 
My favorite design paradigm is that of Godot, which is primarily node based. 


## Nodes

Nodes are the fundamental building block of a scene, and may take many forms.
These forms include 3D, 2D, and GUI.


## Scene Tree

A Scene is a tree of nodes, where nodes may be children of the scene root or other nodes.


## Resources

Resources include objects like textures, materials, audio files, models, and many more. 
Having a centralized location for resources will be helpful for ensuring resources are readily availible and not duplicated. 