#ifndef MINE_GUI_H
#define MINE_GUI_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>

#include "tile.h"
#include "minesweeper.h"
#include "minetogglebutton.h"
#include <vector>

typedef Gtk::Button Button;
typedef Gtk::ToggleButton ToggleButton;

class MineGui : public Gtk::Window
{

public:
  MineGui(int);
  virtual ~MineGui();

protected:
  int width;
  int height;
  MinesweeperGame game;
  std::vector<MineToggleButton*> b_tiles;
  //Signal handlers:
  void on_button_clicked();
  
  //Member widgets:
  Gtk::Table grid;
  Gtk::Table container;
  
};

#endif 


