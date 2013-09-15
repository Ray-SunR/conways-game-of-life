#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
  char **theDisplay;
  int i, j;
  const int gridSize;
 public:
  TextDisplay(int n);

  void notify(int r, int c, char ch);

  ~TextDisplay();

  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
