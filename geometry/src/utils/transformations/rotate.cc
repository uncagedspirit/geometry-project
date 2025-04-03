/*
a rotate function or class is passed a shape and transform the points of the shape, store them 
temp into some variables and later create a new obj using the same variables

eg 

transform(shapename){
apply transform logic on single points from the shape
    transformmatrix logic and all for all points in a loop
    then store the points in a temp data strucutre for now
}

later create a new obj of the shape, eg for circle use transformed point and radiusand create new obj 
and then return it

to whoever you will return it to will handle what he wants to do with it rather than 
this function doing saving and all.
we have applied transformation created shape, the receiver will see what he wants to do with the object of the shape

*/