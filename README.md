# Game-of-Life
Game of Life is a cellular automaton proposed by John Horton Conway. The universe of this game is a grid of square 
cells that could have one of two states: dead or alive. Every cell interacts with its adjacent neighbors, 
with the following transactions occurring at every step:
* Any live cell with fewer than two live neighbors dies as if caused by underpopulation
* Any live cell with two or three live neighbors lives on to the next generation
* Any live cell with more than three live neighbors dies, as if by overpopulation
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
