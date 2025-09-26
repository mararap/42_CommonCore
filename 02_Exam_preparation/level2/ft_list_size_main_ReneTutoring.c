#include "ft_list_ReneTutoring.h"

int main(void)
{
	unsigned long  ul_nbr;
	my_ulint ul_nbr2;   // kürzer dank typedef, aber halt auch überfl

 // Analog:
	struct s_point my_point;
	t_point my_point; //kürzer dank typedef
	t_point my_point2; //kürzer dank typedef

// Initialisieren von structs instanzen / Variablen:
// A) Alles auf 000000 setzten:
	ft_bzero(&my_point, sizeof(my_point));
	ft_bzero(&my_point, sizeof(t_point));
// B) Untereinheiten separat initialisieren:
   my_point.x = 1.02;
   my_point.y = 3.14;

// C) Rüberkopieren von anderer Variable vom gleicheb Typ
	my_point2 = my_point;


	// Einzelne Instanzen / Variable...
	t_list_node	first_address;
	t_list_node second_address;

	//  Vorbem. Analogie:
	//  1) C String: Nullterminierte Folge von Chars
	//  char *p_auf_ersten_char_eines_strings   (korrekt, aber zu länglich fürs Coden)
	//  --> 2) char *str;

	// Eigentliche entsprich  Linked list  grob  C String
	//  t_list_node *p_auf_den_ersten_knoten_einer_linked_list;   (korrekt, aber ...)
	//   --> 2) t_list_node *lst;     
	
	// Analogie beim Iterien:
	str = str + 1;
	lst = lst->next;

	// Prüfen, ob Ende erreicht


}
