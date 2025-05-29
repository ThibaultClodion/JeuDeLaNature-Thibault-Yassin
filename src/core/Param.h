#pragma once

#ifndef PARAM_HPP
#define PARAM_HPP

// Dimensions de la cellule (en pixels)
constexpr int CELL_SIZE = 40;

// Nombre de cellules par ligne/colonne
constexpr int NB_CELL_ROW = 20;
constexpr int NB_CELL_COLUMN = 20;

// Dimensions de la fenêtre
constexpr int WINDOW_WIDTH = CELL_SIZE * NB_CELL_COLUMN;
constexpr int WINDOW_HEIGHT = CELL_SIZE * NB_CELL_ROW;

#endif