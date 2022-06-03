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

	// remplissage garbge collector
	ft_printf("remplissage garbage collector (5 elements)\n");
	char *elem4 = ft_malloc(data, sizeof(char) * 1);
	elem4[0] = '\0';
	char *elem5 = ft_malloc(data, sizeof(char) * 1);
	elem5[0] = '\0';
	char *elem6 = ft_malloc(data, sizeof(char) * 1);
	elem6[0] = '\0';
	char *elem7 = ft_malloc(data, sizeof(char) * 1);
	elem7[0] = '\0';
	char *elem8 = ft_malloc(data, sizeof(char) * 1);
	elem8[0] = '\0';
	ft_print_garbage_collector(data);


	// free 1 element
	ft_printf("free du 2n element\n");
	ft_free(data, elem5);
	ft_print_garbage_collector(data);

	ft_printf("free du 1er element\n");
	ft_free(data, elem4);
	ft_print_garbage_collector(data);

	ft_printf("free du dernier element\n");
	ft_free(data, elem8);
	ft_print_garbage_collector(data);

	ft_printf("free du 1er element\n");
	ft_free(data, elem6);
	ft_print_garbage_collector(data);

	ft_printf("free du 1er element\n");
	ft_free(data, elem7);
	ft_print_garbage_collector(data);

}
