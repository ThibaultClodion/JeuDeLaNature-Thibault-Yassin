#pragma once

// Dimensions de la cellule (en pixels)
constexpr int CELL_SIZE = 40;

// Nombre de cellules par ligne/colonne
constexpr int NB_CELL_ROW = 19;
constexpr int NB_CELL_COLUMN = 19;

// Dimensions de la fen�tre
constexpr int WINDOW_WIDTH_PADING = 400;  // Espace pour l'UI
constexpr int WINDOW_WIDTH = CELL_SIZE * NB_CELL_COLUMN + WINDOW_WIDTH_PADING;
constexpr int WINDOW_HEIGHT = CELL_SIZE * NB_CELL_ROW;

// Param�tres de g�n�ration
constexpr int MIN_NON_NATURE = 5;  // Nombre minimum de cellules non-nature
constexpr int RANDOM_EXTENSION_SIZE = 1;  // Taille de l'extension al�atoire autour du centre
constexpr int NB_ROUNDS = 25;