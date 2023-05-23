/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/23 17:00:44 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 42

# include	<stddef.h> // size_t NULL
# include	<stdlib.h> // malloc free sizeof
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

char		*ft_strjoin1(char *str, char *buff);
char		*process_line(char *str);
char		*process_str(int fd, char *buff, char *str);
char		*get_next_line(int fd);

// -------------------------------------------------------------------------- */
//                                 <ctype.h>                                  */
// -------------------------------------------------------------------------- */
// checks for an alphabetic character
int			ft_isalpha(int c);
// checks for a digit (0 through 9)
int			ft_isdigit(int c);
// checks for an alphanumeric character ft_isalpha + ft_isdigit
int			ft_isalnum(int c);
// checks whether c is in the ASCII table
int			ft_isascii(int c);
// checks for any printable character including space
int			ft_isprint(int c);
// convert lowercase letters to uppercase
int			ft_toupper(int c);
// convert uppercase letters to lowercase
int			ft_tolower(int c);

// -------------------------------------------------------------------------- */
//                                 <string.h>                                 */
// -------------------------------------------------------------------------- */
// calculates the length of the string pointed to by s,
// excluding the terminating null byte
size_t		ft_strlen(const char *s);
// fills the first n bytes of the memory area pointed to by s
// with the constant byte c
void		*ft_memset(void *s, int c, size_t n);
// erases the data in the n bytes of the memory starting at the location pointed
// to by s, by writing zeros (bytes containing '\0') to that area
void		ft_bzero(void *s, size_t n);
// copies  n  bytes from memory area src to memory area dest
void		*ft_memcpy(void *dest, const void *src, size_t n);
// copies n bytes from src to dest copying takes place as though the bytes in
// src are first copied into a temporary array
void		*ft_memmove(void *dest, const void *src, size_t n);
// copy strings take the full size of the buffer
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
// concatenate strings take the full size of the buffer
size_t		ft_strlcat(char *dest, const char *src, size_t size);
// returns a pointer to the first occurrence of the character c
char		*ft_strchr(const char *s, int c);
// returns a pointer to the last occurrence of the character c
char		*ft_strrchr(const char *s, int c);
// compares the two strings s1 and s2 returns an int
int			ft_strncmp(const char *s1, const char *s2, size_t n);
// scans the initial n bytes of the memory area pointed to by s for the first
// instance of c
void		*ft_memchr(const void *s, int c, size_t n);
// compares the first n bytes (each interpreted as unsigned char) of the memory
// areas s1 and s2
int			ft_memcmp(const void *s1, const void *s2, size_t n);
// locates the first occurrence of the null-terminated string little in the
// string big, where not more than len characters are searched
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
// function returns a pointer to a new string which is a duplicate of the string
// s with malloc
char		*ft_strdup(const char *s);

// -------------------------------------------------------------------------- */
//                                 <stdlib.h>                                 */
// -------------------------------------------------------------------------- */
// function converts the initial portion of the string pointed to by nptr to int
int			ft_atoi(const char *nptr);
// allocates memory for an array of nmemb elements of size bytes each and
// returns a pointer to the allocated memory.  The memory is set to zero
void		*ft_calloc(size_t nmemb, size_t size);

// -------------------------------------------------------------------------- */
//                           <Additional functions>                           */
// -------------------------------------------------------------------------- */
// Allocates with malloc and returns a substring from the string ’s’
// The substring begins at index ’start’ and is of maximum size ’len’.
char		*ft_substr(char const *s, unsigned int start, size_t len);
// Allocates with malloc and returns a new string, which is the result
// of the concatenation of ’s1’ and ’s2’.
char		*ft_strjoin(char const *s1, char const *s2);
// Allocates with malloc and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
char		*ft_strtrim(char const *s1, char const *set);
// Allocates with malloc and returns an array of strings obtained by splitting
// ’s’ using the character ’c’ as a delimiter. The array must end with a NULL
// pointer.
char		**ft_split(char const *s, char c);
// Allocates with malloc and returns a string representing the integer received
// as an argument. Negative numbers must be handled.
char		*ft_itoa(int n);
// Applies the function ’f’ to each character of the string ’s’, and passing its
// index as first argument to create a new string with malloc resulting from
// successive applications of ’f’
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Applies the function ’f’ on each character of the string passed as argument,
// passing its index as first argument. Each character is passed by address to
// ’f’ to be modified if necessary.
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
// Outputs the character ’c’ to the given file descriptor
void		ft_putchar_fd(char c, int fd);
// Outputs the string ’s’ to the given file descriptor.
void		ft_putstr_fd(char *s, int fd);
// Outputs the string ’s’ to the given file descriptor followed by a newline.
void		ft_putendl_fd(char *s, int fd);
// Outputs the integer ’n’ to the given file descriptor.
void		ft_putnbr_fd(int n, int fd);

// ------------------------------------------------------------------------- */
//                                 Bonus Part                                */
// ------------------------------------------------------------------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// Allocates with malloc and returns a new node. The member variable ’content’ 
// is initialized with the value of the parameter ’content’. The variable ’next’
// is initialized to NULL.
t_list		*ft_lstnew(void *content);
// Adds the node ’new’ at the beginning of the list.
void		ft_lstadd_front(t_list **lst, t_list *new);
// Counts the number of nodes in a list.
int			ft_lstsize(t_list *lst);
// Returns the last node of the list.
t_list		*ft_lstlast(t_list *lst);
// Adds the node ’new’ at the end of the list.
void		ft_lstadd_back(t_list **lst, t_list *new);
// Takes as a parameter a node and frees the memory of the node’s content using
// the function ’del’ given as a parameter and free the node.
// The memory of ’next’ must not be freed.
void		ft_lstdelone(t_list *lst, void (*del)(void*));
// Deletes and frees the given node and every successor of that node, using the
// function ’del’ and free. Finally, the pointer to the list must be set to NULL
void		ft_lstclear(t_list **lst, void (*del)(void*));
// Iterates the list ’lst’ and applies the function ’f’ on the content of each
// node.
void		ft_lstiter(t_list *lst, void (*f)(void *));
//Iterates the list ’lst’ and applies the function ’f’ on the content of each
// node. Creates a new list resulting of the successive applications of the
// function ’f’. The ’del’ function is used to delete the content of a node if
// needed.
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif