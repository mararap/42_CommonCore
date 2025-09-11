/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thuggonaut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:21:15 by marapovi          #+#    #+#             */
/*   Updated: 2025/09/08 21:38:02 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Declare pointers to two data structures / linked lists, one for stack 'a' and
//another for 'b'
	//Set both pointers to NULL to avoid undefined behaviour and indicate we're
	//starting with empty stacks

//Handle input count errors, Argument count must be 2 or more, and the second
//input must not be empty
	//if input errors, return error

//Handle both cases of input, whether a variable number of command line
//arguments, or as a string
	//if the input of numbers is a string, call 'ft_split()' to split
	//substrings

//Initialize stack 'a' by apendingeach input number as a node to stack 'a'
	//handle integer overflow, duplicates, and syntax errors, e.g. input must
	//only contain digits, or '-' '+' signs
		//if errors found, free stack 'a' and return error
	//check for each input, if it is a long integer
		//if the input is a string, convert it to a long integer
	//append the nodes to stack 'a'

//check if stack 'a' is sorted
	//if not sorted, implement our sorting algorithm
		//check for 2 numbers
			//if so, swap the numbers if necessary
		//check for 3 numbers
			//if so, implement 'sort three' algorithm
		//check if the stack has more than 3 numbers
			//if so, implement 'turk' algorithm

//clean up stack


//basic operations:
//functons to handle errors
//operations
//stack length
//last node
//min and max nodes



