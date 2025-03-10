#!/bin/bash

EXECUTABLE="./cub3d"
MAPS_DIR="maps/bad"

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

# Vérifier si l'exécutable existe
if [ ! -x "$EXECUTABLE" ]; then
    echo -e "${RED}Erreur : l'exécutable $EXECUTABLE est introuvable ou non exécutable.${NC}"
    exit 1
fi

# Vérifier si le dossier des maps existe
if [ ! -d "$MAPS_DIR" ]; then
    echo -e "${RED}Erreur : le dossier $MAPS_DIR est introuvable.${NC}"
    exit 1
fi

for map in "$MAPS_DIR"/*.cub; do
    echo -e "${BLUE}Test de la map : $map${NC}"
    
    # Lancer le programme en arrière-plan et mesurer le temps d'exécution
    START_TIME=$(date +%s%N)
    OUTPUT=$($EXECUTABLE "$map" 2>&1)
    END_TIME=$(date +%s%N)
    ELAPSED_TIME=$(( (END_TIME - START_TIME) / 1000000 ))  # Convertir en millisecondes
    
    # Vérifier si le programme a pris plus d'une seconde
    if [ "$ELAPSED_TIME" -gt 1000 ]; then
        echo -e "${RED}KO : Le programme a tourné plus d'une seconde ($((ELAPSED_TIME / 1000)).$((ELAPSED_TIME % 1000))s).${NC}"
        ((FAILED++))
    elif echo "$OUTPUT" | grep -qi "error"; then
        echo -e "${GREEN}OK : Erreur détectée.${NC}"
        echo -e "${YELLOW}Message d'erreur :${NC}"
        echo "$OUTPUT"
        ((PASSED++))
    else
        echo -e "${RED}KO : Le programme n'a pas retourné d'erreur.${NC}"
        ((FAILED++))
    fi
    
    # Vérification des fuites de mémoire avec Valgrind
    VALGRIND_OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $EXECUTABLE "$map" 2>&1)
    HEAP_USAGE=$(echo "$VALGRIND_OUTPUT" | grep "total heap usage")

    echo -e "${YELLOW}Heap usage :${NC}"
    echo "$HEAP_USAGE"

    if echo "$HEAP_USAGE" | grep -q "allocs, .*frees"; then
        ALLOCS=$(echo "$HEAP_USAGE" | awk '{print $4}')
        FREES=$(echo "$HEAP_USAGE" | awk '{print $6}')
        if [ "$ALLOCS" -eq "$FREES" ]; then
            echo -e "${GREEN}OK : Pas de fuite de mémoire détectée.${NC}"
        else
            echo -e "${RED}KO : Fuite de mémoire détectée !${NC}"
            ((FAILED++))
        fi
    else
        echo -e "${RED}KO : Impossible de récupérer les stats Valgrind.${NC}"
        ((FAILED++))
    fi

    
    echo "-----------------------------"
done

# Afficher le résumé des tests
echo -e "${BLUE}Résumé des tests :${NC}"
echo -e "${GREEN}Tests réussis : $PASSED${NC}"
echo -e "${RED}Tests échoués : $FAILED${NC}"