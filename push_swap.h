#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct stack{
    int value;
    struct stack *next;
    int index;
}t_stack;

/*typedef struct stack_track 
{
    int size_of_stack;
    t_stack *top;    
} t_stack_track;*/

void	push_swap(char **integers, int av, t_stack **a);
void	push_stack(t_stack **lst, t_stack *new);

int    fill_stack(char **args, t_stack **a, int av, int selector_flag);

t_stack   *create_stack(int value);

void    check_dups(char **integers);

 char	**free_all(char **strs);

 int	ft_atoi_m(const char *nptr);

 void    print_error();
char **ft_strjoin_m(char **splitted, char **integers);
int swap_a(t_stack **a, int *ops_count);
int swap_b(t_stack **b, int *ops_count);
t_stack	*ft_lstlast2(t_stack *lst);
int push_a(t_stack **a, t_stack **b, int *ops_count);
int push_b(t_stack **a, t_stack **b, int *ops_count);
int rotate(t_stack **a, char c, int *ops_count);
int is_empty_or_unary(t_stack *a);
int reverse_rotate(t_stack **a, char c, int *ops_count);
int rr(t_stack **a, t_stack **b, int *ops_count);
int rrr(t_stack **a, t_stack **b, int *ops_count);
void	sort_simple(t_stack **a, int size, int bench_flag);
void	ft_lstadd_front2(t_stack **lst, t_stack *new);
void sort_complex(t_stack **a, int size, int bench_flag);
void sort_medium(t_stack **a, int size, int bench_flag);
void index_stack(t_stack **a);
double compute_disorder(t_stack *a);
void    bench(int *ops_count, int disorder, char *strategy);
int		*init_ops(void);
void	end_sort(int *ops, int disorder, int bench_flag, char *name);
int		stack_size(t_stack *s);
void	rotate_to_top(t_stack **s, char c, int pos, int *ops);
void	index_stack(t_stack **a);
int swap_b_bouns(t_stack **b);
int swap_a_bouns(t_stack **a);
int ss_bouns(t_stack *a, t_stack *b);
int push_a_bouns(t_stack **a, t_stack **b);
int push_b_bouns(t_stack **a, t_stack **b);
int rotate_bouns(t_stack **a);
int reverse_rotate_bouns(t_stack **a);
int rr_bouns(t_stack **a, t_stack **b);
int rrr_bouns(t_stack **a, t_stack **b);

#endif
