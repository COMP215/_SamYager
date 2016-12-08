This Final Project contains the Game of Life. The game is not a typical game, it is more of a model or simulation. It takes a two dimentional grid of cells. Each cell can be either alive or dead.

The simulation is carried out at fixed time steps; every time step, all the cells on the grid can switch from dead to alive, or alive to dead, depending on four simple rules that only depend on a given cell’s eight immediate neighbours. The rules are as follows:

If the cell is dead:
   Birth: if exactly three of its neighbours are alive, the cell will become alive at the next step.

If the cell is already alive:
   Survival: if the cell has two or three live neighbours, the cell remains alive.

Otherwise, the cell will die:
   Death by loneliness: if the cell has only zero or one live neighbours, the cell will become dead at the next step.
   Death by overcrowding: if the cell alive and has more than three live neighbours, the cell also dies.



To run the program, type the following into a terminal window:
  g++ gameoflife.cpp gameoflife_main.cpp
  
The user will be asked for an input of the number of steps. Type an integer then hit <ENTER>
