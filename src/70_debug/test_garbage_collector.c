#include "minishell.h"

// test :
// initialisation du garbage collector
// ajout de nouveau element par malloc
// ajout de nouveau elements directement avec leur pointeur
// free du garbage collector

void    ft_test_garbage_collector(t_data *data)
{
	// test init garbage collector et affichage vide
	ft_printf("test init garbage collector et affichage vide\n");
	ft_init_garbage_collector(data);
	ft_print_garbage_collector(data);

	// test ajout un elm par malloc et print return + garbage collector
	ft_printf("\ntest ajout un elm par malloc et print return + garbage collector\n");
	char *elem1 = ft_malloc(data, sizeof(char) * 4);
	elem1[0] = 'a';
	elem1[1] = 'b';
	elem1[2] = 'c';
	elem1[3] = '\0';
	ft_printf("test return ecriture malloc : adresse=%p, content=%s\n", elem1, elem1);

	char *elem2 = ft_malloc(data, sizeof(char) * 1);
	elem2[0] = '\0';
	ft_printf("test return ecriture malloc : adresse=%p, content=%s\n", elem2, elem2);

	char *elem3 = malloc(sizeof(char) * 1);
	elem3[0] = '\0';
	ft_add_to_garbage_collector(data, elem3);
	ft_printf("test ajout direct: adresse=%p\n", elem3);

	ft_print_garbage_collector(data);

	// free garbage collector
	ft_printf("free du garbage collector\n");
	ft_free_garbage_collector(data);
	ft_print_garbage_collector(data);

}
