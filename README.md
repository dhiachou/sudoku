## Description:
This game is a standard SUDOKU puzzle.
We provide hereby a source that can be compiled into a command line application or a graphical application. We use SDL1.2 for the graphics.
It is developed to make it easy to maintain and improve its functionalities. It is easy to adapt the code to make it work for grids of different size for example.

## Requirements :
In order to build the project, you will need the following libraries :
libsdl1.2-dev
libsdl-image1.2-dev
libsdl-ttf1.2-dev

## Building :
To build all run :
$ make
To build GUI only run :
$ make sdl
To build CLI only run :
$ make console

## Usage:
A partially completed 9x9 grid divided into nine 3x3 sub-grids (Squares) is provided to the player. The objective of the SUDOKU game is to fill in the rest of the Grid with digits so that each column, row and square contains all of the numbers 1 through 9. Three levels are available (easy, medium and hard).


## Contribution:
Fork the repository, modify it, submit a package with name, description, URL, and optional screenshot. Don't forget to submit a pull request.


## License :
This project is released under the terms of the [MIT license](http://en.wikipedia.org/wiki/MIT_License)
The MIT License is simple and easy to understand and it places almost no restrictions on what you can do with this project.
You are free to use the project in any other project (even commercial projects) as long as the copyright header is left intact.
