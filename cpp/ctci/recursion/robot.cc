#include <iostream>

bool IsFree(int x, int y)
{
	if (x == 0 && y == 1)
		return false;
	return true;
}

int MoveSimple(int x, int y) 
{
	std::cout << "(" << x << "," << y << ")" << std::endl;
	if (x == 0 && y == 0)
		return 1;
	
	if (x == 0)
		return MoveSimple(x, y - 1);

	if (y == 0)
		return MoveSimple(x - 1, y);

	return (MoveSimple(x, y - 1) + MoveSimple(x - 1, y));
}

int Move(int x, int y) 
{
	std::cout << "(" << x << "," << y << ")" << std::endl;
	if (x == 0 && y == 0)
		return 1;
	
	if (!IsFree(x,y)) 
		return 0;

	if (x == 0)
		return Move(x, y - 1);

	if (y == 0)
		return Move(x - 1, y);

	return (Move(x, y - 1) + Move(x - 1, y));


}

int main(int argc, char** argv)
{
	std::cout << Move(3-1,3-1) << std::endl;


}
