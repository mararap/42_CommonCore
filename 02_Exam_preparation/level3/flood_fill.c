
#include "flood_fill.h"

void  fill(char **tab, t_point size, char target, int x, int y)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return; // out of bounds
	if (tab[x][y] == 'F' || tab[y][x] != target)
		return; // already filled or not the right character
	
	tab[y][x] = 'F'; // fill current cell

	// recursively fill in all 4 directions
	fill(tab, size, x - 1, y, target);
	fill(tab, size, x + 1, y, target);
	fill(tab, size, x, y - 1, target);
	fill(tab, size, x, y + 1, target);
}
void	flood_fill(char **tab, t_point size, t_point begin)
{
	// store the value of where we start in target
	char	target = tab[begin.y][begin.x];
	// call fill-function to fill the grid with coordinates
	// begin.x and begin.y, 2D-array "tab" and value "target"
	fill(tab, size, target, begin.x, begin.y);
}
// main example from exam subject
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
