/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:50:09 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/25 18:08:56 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H


// Erste Art eine Linked List anzugehen: Generisch (Abstrakt / allgemein)
// Vorteil: Man braucht die ganzen Hilfsfunktionen nur ein mal coden
// Nachteil: Es wird komplizierter /  abstrakter, weil man mit void pointern 
//           arbeiten muß (um ohne kenntniss des Datentyps trotzdem was zu machen)

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

#endif // !FT_LIST_H


// Bsp für erste Art:

typedef struct	s_address
{
	char				*name;
	int					postleitzahl;
	char				*strasse;
}					t_address;


//In main:
//  t_address *p_new_address = malloc (sizeof(t_address));
//  p_new_address->name = "Miau";
//  p_new_address->postleitzahl = 3;
//  p_new_address->strasse = "schoenweg";
//
//  t_list* p_first_node = ft_lstnew(p_new_address);
//  t_list* p_node = p_first_node;
//
//  Zweiten Knoten anfügen:
//  t_address *p_new_address = malloc (sizeof(t_address));
//  p_new_address->name = "Maeh";
//  p_new_address->postleitzahl = 7;
//  p_new_address->strasse = "greenwood";
//  p_node = ft_lstnew(p_new_address);        //Name new_node_waere hier viel eingängiger...
//  ft_lst_addback(&p_first_node, p_node)     // oder add_front???
//
//  // Zugriff auf content via linked list:
//  //so gehts net: p_first_node->data   Void pointer: p_first_node->data->name = "Wuff"
//  (t_address*)(p_first_node->data)->name = "Wuff"




// Zweite Art eine Linked list anzugehen: Themengebunden
// Vorteil: Einsichtig
// Nachteil: Bei einer anderen Themengebunden List bräuchte man für jede 
//           einge Art von Linked list jeweils die ganze Pallette an Hilfsfunktionen,
//           die auf die jeweilige Linked list zugeschnitten ist.

typedef struct	s_list_node      // oder kuerzer s_node
{
	char				*name;
	int					postleitzahl;
	char				*strasse;
	struct s_list_node	*next;
}					t_list_node;


/////// STRUCTS

typedef struct	s_point
{
	double x;
	double y;
}  t_point;


struct	s_quadrat
{
	t_point	ecke_oben_link;
	double	seitenlänge;
};



// Um kürzer Variablen einer solchen neuen Variablenart zu definieren:

typedef unsigned long my_ulint;

// Besonder nützlich in Verbindung mit structs:
typedef struct	s_point
{
	double x;
	double y;
} t_point;
