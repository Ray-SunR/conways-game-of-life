#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <sstream>
#include "cell.h"
#include "textdisplay.h"
#include "window.h"
class Grid {
  Cell **theGrid;  // The actual grid.
  int gridSize;    // Size of the grid.

  TextDisplay *td; // The text display.
  // Add private members, if necessary.
  Xwindow* xw; //window
  void clearGrid();   // Frees the grid.

 public:
  Grid();
  ~Grid();

  void init(int n); // Sets up an n x n grid.  Clears old grid, if necessary.
  void tick();      // Runs one iteration of the simulation.
  void turnOn(int r, int c);  // Sets cell at row r, col c to living.

  friend std::ostream& operator<<(std::ostream &out, const Grid &g);
};



#endif
