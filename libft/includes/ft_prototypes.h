/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:34:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:34:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPES_H
# define FT_PROTOTYPES_H

/*
** ft_Prototypes
*/

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isbase(char base, char *s);
int			ft_isdigit(int c);
int			ft_is_hexa(char c);
int			ft_islower(int c);
int			ft_isprime(int nb);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isspace_wnt(int c);
int			ft_isupper(int c);
int			al_index_of(t_arlist *al, void *content, size_t content_size);
void		*al_get(t_arlist *al, int i);
int			al_add(t_arlist *al, void *content, size_t content_size);
void		*al_remove(t_arlist *al, int i);
void		al_del(t_arlist **al);
size_t		ht_hash(char *key, size_t size);
t_hashtab		*ht_new(size_t size);
void		ht_del(t_hashtab *ht, char *key, void (*del)(void *, size_t));
int			ht_add(t_hashtab *ht, char *key, void *data, size_t size);
void		*ht_get(t_hashtab *ht, char *key);
int			ht_itemadd(t_hashitem **tail, char *key, void *data, size_t size);
void		ht_itemdel(t_hashitem **head, void (*del)(void *, size_t));
void		ht_tabclear(t_hashtab *ht, void (*del)(void *, size_t));
void		ht_tabdel(t_hashtab **ht, void (*del)(void *, size_t));
int			ft_atoi(const char *str);
int			ft_atoi_base(char *str, char *base);
long		ft_atol(const char *str);
long		ft_atol_base(char *str, char base_len);
char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
char		*ft_itoa(int n);
char		*ft_itoa_base(int n, char *base);
char		*ft_ltoa(long n);
char		*ft_ltoa_base(long n, char *base);
int			get_next_line(const int fd, char **line);
void		ft_lstadd(t_list **alst, t_list *new);
size_t		ft_lstcnt(t_list *lst);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstrev(t_list **alst);
int			ft_abs(int i);
long double		ft_ldabs(long double d);
int			ft_max(int a, int b);
int			ft_min(double a, double b);
int			ft_pow(int nb, int pow);
int			ft_sqrt(int nb);
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		ft_memdel2(void **ap1, void **ap2);
void		ft_memdel3(void **ap1, void **ap2, void **ap3);
void		ft_memdel4(void **ap1, void **ap2, void **ap3, void **ap4);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_charswap(char *a, char *b);
int			ft_indexof(char c, char *str);
void		ft_intswap(int *a, int *b);
int			ft_lininterp(int p1, int p2, double ratio);
double		ft_rlininterp(double px, double p1, double p2);
size_t		ft_nbrlen(int nbr, int base_len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char const *s);
void		ft_putendl2(char const *s1, char const *s2);
void		ft_putendl3(char const *s1, char const *s2, char const *s3);
void		ft_putendl4(char const *s1, char const *s2,
				char const *s3, char const *s4);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putendl2_fd(char const *s1, char const *s2, int fd);
void		ft_putendl3_fd(char const *s1, char const *s2, char const *s3, int fd);
void		ft_putnbr(long nb);
void		ft_putnbr_base(long nb, char *base);
void		ft_putnbr_base_fd(long nb, char *base, int fd);
void		ft_putnbr_fd(long nb, int fd);
void		ft_putnbrtab(int *tab, size_t size);
void		ft_putnbrtab_fd(int *tab, size_t size, int fd);
void		ft_putstr(char const *s);
void		ft_putstr2(char const *s1, char const *s2);
void		ft_putstr3(char const *s1, char const *s2, char const *s3);
void		ft_putstr4(char const *s1, char const *s2,
				char const *s3, char const *s4);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr2_fd(char const *s1, char const *s2, int fd);
void		ft_putstr3_fd(char const *s1, char const *s2, char const *s3, int fd);
void		ft_putstrnbr(char *s1, long nb, char *s2);
void		ft_putstrnbr_fd(char *s1, long nb, char *s2, int fd);
void		ft_putstrlpad(char const *s, char c, size_t size);
void		ft_putstrrpad(char const *s, char c, size_t size);
void		ft_putstrlpad_fd(char const *s, char c, size_t size, int fd);
void		ft_putstrrpad_fd(char const *s, char c, size_t size, int fd);
void		ft_putstrtab(char **tab);
void		ft_putstrtab_fd(char **tab, int fd);
int	
				fill_precision(t_conv *c, t_formatter *fmt);
void
				fill_width(t_conv *c, t_formatter *fmt);
void
				fill_width_chr(t_printf *pf, t_formatter *fmt, int conv_ret);
int	
				convert(t_printf *pf, t_formatter *fmt);
int			convert_char(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_wchar(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_const(t_printf *pf, t_formatter *fmt);
int			convert_q(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_q_up(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_k(t_printf *pf, t_formatter *fmt, va_list ap);
void		compute_f(t_double *d);
void		fill_dbl(t_double *d);
int			convert_f(t_printf *pf, t_formatter *fmt, va_list ap);
void		write_conv(t_conv *c, t_double *d, t_formatter *fmt);
int			write_double(t_printf *pf, t_formatter *fmt, t_double *d);
int			convert_di(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_u(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_x(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_o(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_b(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_n(t_printf *pf, t_formatter *fmt, va_list ap);
int			set_coma(t_conv *c, int len);
int	
				itoa_base(t_conv *c, intmax_t i, int base, char upcase);
int			signed_integer(t_formatter *fmt, t_conv *c, va_list ap, int b);
int			unsigned_integer(t_formatter *fmt, t_conv *c, va_list ap, int b);
int			convert_m(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_r(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_p(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_str(t_printf *pf, t_formatter *fmt, va_list ap);
int			convert_wstr(t_printf *pf, t_formatter *fmt, va_list ap);
void
				parse_formatter(t_formatter *fmt, t_printf *pf);
int			ft_printf(const char *format, ...);
void		get_arg_at(int pos, t_arglist *args);
int			handle_formatter(t_printf *pf);
int			ft_vprintf(const char *format, va_list ap);
void		str_power(unsigned char *p, long a, int b, int len);
void		str_add(unsigned char *a, unsigned char *b, int len);
void		str_multi(unsigned char *a, int b, int len);
void		str_divi(unsigned char *a, int b, int len);
void		str_divi_2(unsigned char *a, int len);
int			is_length(char c, t_formatter fmt, int v);
int			is_flag(char c, t_formatter fmt);
char		*walk_format(char *s, int c);
size_t		wchartoa(char *s, wint_t w);
size_t		wstrtoa(char *s, const wchar_t *wstr);
size_t		wstrntoa(char *s, const wchar_t *wstr, size_t n);
int			check_unicode(wint_t *c);
void		print(char *s, int size);
int			put(char *s, int len);
size_t		bwrite(t_buffer *b, const char *s, size_t len);
size_t		dblwrite(t_buffer *b, unsigned char *s, size_t len);
void		ft_sortinttab(int *tab, size_t size);
void		ft_sortstrtab(char **tab);
int			ft_hasnodupl(char *str);
char		*ft_printabilize(char *str, char c);
char		**ft_split_chars(char const *s, int (*is_separator)(int));
char		*ft_stralloc(size_t size);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
void		ft_strdel(char **as);
void		ft_strdel2(char **as1, char **as2);
void		ft_strdel3(char **as1, char **as2, char **as3);
void		ft_strdel4(char **as1, char **as2, char **as3, char **as4);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
char		*ft_strimplode(char **tab, char delim);
char		*ft_strimplodef(char **tab, char delim);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin3(char const *s1, char const *s2, char const *s3);
char		*ft_strjoin4(char const *s1, char const *s2,
				char const *s3, char const *s4);
char		*ft_strjoinf(char *s1, char *s2);
char		*ft_strjoin3f(char *s1, char *s2, char *s3);
char		*ft_strjoin4f(char *s1, char *s2, char *s3, char *s4);
char		*ft_strjoinfs(char *s1, char *s2, char flag);
char		*ft_strjoin3fs(char *s1, char *s2, char *s3, char flag);
char		*ft_strlastchr(char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strlequ(char const *s1, char const *s2);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strmove(char *dst, const char *src);
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t len);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strntrim(char const *s, int n);
char		*ft_strover(char *old, char *new);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrealloc(char *str, size_t len);
char		*ft_strrev(char *str);
char		*ft_strrmvchr(char *s, char c);
char		*ft_strrmvfirst(char *s);
char		*ft_strrmvlast(char *s);
char		*ft_strrmvstr(char *haystack, char *needle);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
char		*ft_strtrim(char const *s);
size_t		ft_wrdcnt(const char *s, char c);
int			sb_add(t_strbuffer *sb, const char *data, size_t len);
int			sb_check_free_space(t_strbuffer *sb, size_t len);
int			sb_remalloc(t_strbuffer *sb, size_t new_len);
int			sb_slide(t_strbuffer *sb, size_t bef, size_t aft);
int			sb_init(t_strbuffer *sb);
void		ft_strtabdel(char ***tab);
void		ft_strtabdel2(char ***tab1, char ***tab2);
void		ft_strtabdel3(char ***tab1, char ***tab2, char ***tab3);
void		ft_strtabdel4(char ***t1, char ***t2, char ***t3, char ***t4);
char		**ft_strtabdup(char **tab);
char		**ft_strtabjoinfs(char **tab1, char **tab2, char flag);
char		**ft_strtabjoin(char **tab1, char **tab2);
char		**ft_strtabjoin3(char **tab1, char **tab2, char **tab3);
char		**ft_strtabjoin4(char **tab1, char **tab2, char **tab3, char **tab4);
int			ft_tabadd(void ***tab, void *new);
int			ft_strtabadd(char ***tab, char *new);
void		**ft_taballoc(size_t len);
char		**ft_strtaballoc(size_t len);
void		**ft_tabcpy(void **dst, void **src);
char		**ft_strtabcpy(char **dst, char **src);
void		ft_tabdel(void ***tab);
void		ft_tabdel2(void ***tab1, void ***tab2);
void		ft_tabdel3(void ***tab1, void ***tab2, void ***tab3);
void		ft_tabdel4(void ***tab1, void ***tab2, void ***tab3, void ***tab4);
size_t		ft_tablcpy(void **dst, void **src, size_t size);
char		**ft_strtablcpy(char **dst, char **src, size_t size);
size_t		ft_tablen(void **tab);
size_t		ft_strtablen(char **tab);
size_t		ft_tabstrlen(char **tab, size_t *i);
void		**ft_tabncpy(void **dst, void **src, size_t len);
char		**ft_strtabncpy(char **dst, char **src, size_t len);
void		**ft_tabnew(size_t len);
char		**ft_strtabnew(size_t len);
void		**ft_tabrealloc(void **tab, size_t len);
char		**ft_strtabrealloc(char **tab, size_t len);
void		ft_tabswap(void ***tab1, void ***tab2);
void		ft_strtabswap(char ***tab1, char ***tab2);

#endif
