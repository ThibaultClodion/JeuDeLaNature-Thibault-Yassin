#pragma once

// Dimensions de la cellule (en pixels)
constexpr int CELL_SIZE = 40;

// Nombre de cellules par ligne/colonne
constexpr int NB_CELL_ROW = 19;
constexpr int NB_CELL_COLUMN = 19;

// Dimensions de la fenêtre
constexpr int WINDOW_WIDTH = CELL_SIZE * NB_CELL_COLUMN;
constexpr int WINDOW_HEIGHT = CELL_SIZE * NB_CELL_ROW;