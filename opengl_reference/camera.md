# Camera

It is tempting to think of a camera object as a type of game object that is used as a lense to view the game world. 
I would discourage this thinking. 
Fundamentally, a camera, in our use case, is just some object that calculates a view and projection matrix for us. 
The projection matrix will be (mostly) constant, and the view matrix will update based on position and rotaiton. 
With this disclaimer in mind, I suggest you read the reference on [transformations](./transformation.md), as it will cover relavent information. 

Full implementation of [Camera Class](../examples/src/camera.cpp)


## Setting out