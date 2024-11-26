/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:38:33 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:06:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*                                                                            */
/*		Memory manipulation functions                                         */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, size_t n);
//Sets n bytes of memory to zero.

void	*ft_calloc(size_t nmemb, size_t size);
// Allocates memory for an array and initializes it.
void	*ft_memchr(const void *s, int c, size_t n);
//Searches for a character in a memory block.
void	*ft_memcpy(void *dest, const void *src, size_t n);
//Copies n bytes of memory from one block to another.
void	*ft_memmove(void *dest, const void *src, size_t n);
//Moves n bytes of memory from one block to another, handling overlapping memory
void	*ft_memset(void *s, int c, size_t n);
//Fills a memory block with a specific value.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
//Compares two blocks of memory.

/* ************************************************************************** */
/*                                                                            */
/*		String manipulation functions                                         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//Applies a function to each character of a string in place.

int		ft_strncmp(const char *s1, const char *s2, size_t n);
//Compares two strings with a specified length limit.

size_t	ft_strlen(const char *s);
//Returns the length of a string.
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
//Copies a string with bounds checking.
size_t	ft_strlcat(char *dst, const char *src, size_t size);
//Concatenates a string with bounds checking.

char	*ft_strchr(const char *s, int c);
//Finds the first occurrence of a character in a string.
char	*ft_strdup(const char *s);
//Duplicates a string.
char	*ft_strrchr(const char *s, int c);
//Finds the last occurrence of a character in a string.
char	*ft_strnstr(const char *big, const char *little, size_t len);
//Finds a substring in a string, with length limit.
char	*ft_substr(char const *s, unsigned int start, size_t len);
//Finds a substring in a string, with length limit.
char	*ft_strjoin(char const *s1, char const *s2);
//Finds a substring in a string, with length limit.
char	*ft_strtrim(char const *s1, char const *set);
//Trims characters from the beginning and end of a string based on a set.
char	*ft_itoa(int n);
//Converts an integer to a string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//Applies a function to each character of a string, creating a new string.

char	**ft_split(char const *s, char c);
//Splits a string into an array of substrings based on a delimiter.

/* ************************************************************************** */
/*                                                                            */
/*		File handling functions                                               */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_fd(char c, int fd);
//Writes a character to a file descriptor.
void	ft_putstr_fd(char *s, int fd);
//Writes a string to a file descriptor.
void	ft_putendl_fd(char *s, int fd);
//Writes a string followed by a newline to a file descriptor.
void	ft_putnbr_fd(int n, int fd);
//Writes an integer to a file descriptor.

/* ************************************************************************** */
/*                                                                            */
/*		Utility functions                                                     */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c);
//Checks if a character is alphanumeric.
int		ft_isalpha(int c);
//Checks if a character is alphabetic.
int		ft_isascii(int c);
//Checks if a character is ASCII.
int		ft_isdigit(int c);
//Checks if a character is a digit.
int		ft_isprint(int c);
//Checks if a character is printable.
int		ft_tolower(int c);
//Converts a character to lowercase.
int		ft_toupper(int c);
//Converts a character to uppercase.
int		ft_atoi(const char *nptr);
//Converts a string to an integer.

/* ************************************************************************** */
/*                                                                            */
/*		Linked lists functions                                                */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstnew(void *content);
//Creates a new linked list node.

t_list	*ft_lstlast(t_list *lst);
//Returns the last node of the linked list.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//Creates a new linked list by applying a function to each node.

int		ft_lstsize(t_list *lst);
//Returns the size of the linked list.

void	ft_lstadd_front(t_list **lst, t_list *new);
//Adds a node to the front of a linked list.
void	ft_lstadd_back(t_list **lst, t_list *new);
//Adds a node to the end of a linked list.
void	ft_lstdelone(t_list *lst, void (*del)(void*));
//Deletes a single node from the linked list.
void	ft_lstiter(t_list *lst, void (*f)(void *));
//Applies a function to each node in the linked list.
void	ft_lstclear(t_list **lst, void (*del)(void*));
//Deletes and frees an entire linked list.

/* ************************************************************************** */
/*                                                                            */
/*  	Get_next_line                                                         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_next_line(char *str);

#endif
