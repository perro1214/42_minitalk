#include "ft_printf.h"

char *tr_pointer(size_t number) {
    char *tr_list = "0123456789abcdef";
    return ft_pointer_hextoa((size_t)number,tr_list);
}
