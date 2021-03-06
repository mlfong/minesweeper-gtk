#include "tile.h"

Tile::Tile(int val) :
value(val), marked(false), clicked(false)
{

}

Tile::Tile() :
value(0), marked(false), clicked(false)
{

}

int Tile::getValue()
{
	return value;
}

bool Tile::isMarked()
{
	return marked;
}

bool Tile::isClicked()
{
	return clicked;
}

void Tile::mark()
{
	marked = !marked;
}

void Tile::setValue(int v)
{
	value = v;
}

int Tile::click()
{
	clicked = true;
	return (value == BOMB) ? 0 : 1;
}

std::ostream &operator<<(std::ostream &os, const Tile &obj)
{
	os << "(" << obj.value << ", " << obj.marked << ", " << obj.clicked << ")";
	return os;
}
