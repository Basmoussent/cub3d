.PHONY: all bonus clean fclean re pipex_m pipex_b norme

DIR_M := mandatory
DIR_MLX := mlx

# Default target
all: pipex_m

# Bonus target
bonus: pipex_b

norme: file_norme

library:
	@echo "Building in mlx library"
	@$(MAKE) -C $(DIR_MLX)

pipex_m: library
	@echo "Building in cub3d..."
	@$(MAKE) -C $(DIR_M)

file_norme:
	@$(MAKE) -C $(DIR_M) norme

clean:
	@echo "Cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) clean

fclean:
	@echo "Fully cleaning in all directories..."
	@$(MAKE) -C $(DIR_M) fclean

re: fclean all