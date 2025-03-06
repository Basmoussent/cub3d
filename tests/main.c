#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_img;

typedef struct s_vars {
    void    *mlx;
    void    *win;
    t_img   img;
} t_vars;

// Fonction pour récupérer la couleur d'un pixel dans l'image source
int get_pixel_color(t_img *img, int x, int y)
{
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
        return (0);
    char *pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    return *(int *)pixel;
}

// Fonction pour dessiner un pixel dans la fenêtre
void put_pixel_to_window(void *mlx, void *win, int x, int y, int color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 600) // Vérifie les limites de la fenêtre
        mlx_pixel_put(mlx, win, x, y, color);
}

// Fonction pour appliquer la transformation perspective et afficher l'image
void draw_transformed_image(t_vars *vars)
{
    int x, y;
    int new_x, new_y;
    int factor = 3; // Facteur de perspective (plus il est élevé, plus l'effet est fort)

    for (y = 0; y < vars->img.height; y++)
    {
        for (x = 0; x < vars->img.width; x++)
        {
            int color = get_pixel_color(&vars->img, x, y);

            // Transformation en perspective
            int depth = x / factor; // Simule la profondeur
            new_x = 400 + depth; // Centre l'image et la décale vers la droite
            new_y = y + depth / 2; // Ajuste la hauteur pour la perspective

            put_pixel_to_window(vars->mlx, vars->win, new_x, new_y, color);
        }
    }
}

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Perspective Image");

    // Charger l'image
    vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./assets/NO.xpm", &vars.img.width, &vars.img.height);
    if (!vars.img.img)
    {
        printf("Erreur : Impossible de charger l'image\n");
        return (1);
    }

    vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

    // Affichage de l'image transformée
    draw_transformed_image(&vars);

    mlx_loop(vars.mlx);
    return (0);
}
