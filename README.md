# Zombies versus Humans
This project was created for the final assignment of my 2nd year C++ course. 

The purpose of the project was to create a text based simulation 
where zombies attempt to eliminate humans while humans attempt to 
survive. 

The application creates a 2-dimensional grid that contains all organisms in the *world*. 

Each time-step, humans try to move and procreate. Zombies try to move, eat humans if they can,
as well as spawn new zombies if possible. 

If no zombies exist at the end of the turn, humans win. Conversely, if no humans exist,
then the zombies win. If both don't exist, no-one wins.

### What I would like to improve
1. Move from a text-based grid to a GUI application using something like [SFML](https://www.sfml-dev.org/). 
2. I'd like to use something like [conan](https://conan.io/) to easily make use of 3rd party libraries.
3. Add and or improve any and all headers. 


[1]:[https://www.sfml-dev.org/]