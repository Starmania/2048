# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g -I./sources -I./sources/grille_de_jeu -I./sources/joueurs -I./sources/scores

# Répertoire source
SRC_DIR = ./sources

# Trouver tous les fichiers .c dans le projet
SRC_FILES = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)

# Générer les noms des fichiers objets
OBJ_FILES = $(SRC_FILES:.c=.o)

# Nom de l'exécutable principal
TARGET = programme

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable principal
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Règle pour recompiler tout
re: clean all

.PHONY: all clean re
