#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
#include "window.h"
const int maxNeighbours = 8;

class Cell {
  bool isAlive;//indicate whether a cell is alive
  int numNeighbours;//indicate how many neighbours it has
    int numNeighbourAlive;//indicate how many neighbours alive
  Cell *neighbours[maxNeighbours];//used to store the alive neighbours' pointers
  Xwindow* xw;//Window
  int r, c;//row and column
  int x, y;//coordinate of the cell
  int width,height; //width and height of the cell
 // Add other private members if necessary

 public:
  Cell();  // Default constructor
  void setLiving();         // Explicitly sets me to living.
  void setCoords(int r, int c, int x, int y, int width, int height, Xwindow* xw);
  void notifyDisplay(TextDisplay &t);//notify the text display
    void resetNumNeiAlive();//each time when calculate the number of neighbours alive, we have to reset all the alive neighbours numbers to zero.
  void addNeighbour(Cell *neighbour);//register the neighbour into a cell
  void draw();
  void undraw();
    //accessor of the private fields.
  int getX() const { return x;}
  int getY() const { return y;}
  int getR() const { return r;}
  int getC() const { return c;}
  void notify();  // My neighbours will call this, to let me know
                  // they're alive.

  void notifyNeighbours();   // Tell all of my neighbours that I am alive
                            // (if I'm alive).
    void setX(int i) {r = i;}
    void setY(int i) {c = i;}
  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours
};

#endif
