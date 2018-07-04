#include "fdf.h"

t_line_list	*new_line_list(void)
{
	t_line_list	*line_list;
	line_list = (t_line_list *)malloc(sizeof(t_line_list));
	vector_init(line_list->vert_vec);
	vector_init(line_list->ind_vec);
}
