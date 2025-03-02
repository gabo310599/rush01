#include <unistd.h>
#include <stdlib.h>

#define dimensions 4

//Funcion que valida si el numero se encuentra en la fila o las columnas
int ft_validate_row_col(int **array, int row, int col, int number)
{
    int i;

    i = 0;
    while (i < dimensions)
    {
        if (array[i][col] == number)
            return (0);
        i++;
    }
    i = 0;
    while (i < dimensions)
    {
        if (array[row][i] == number)
            return (0);
        i++;
    }
    return (1);
}

//Funcion que valida el punto de vista superior
int ft_validate_clues_top(int **array, int row, int col, int **clues, int number)
{
    int visibility;
    int max;
    int i;

    if (row == dimensions - 1)
    {
        visibility = 0;
        max = 0;
        i = 0;
        while (i < dimensions)
        {
            if (array[i][col] > max)
            {
                max = array[i][col];
                visibility++;
            }
            i++;
        }
        if (clues[0][col] != visibility && clues[0][col] != 0)
            return (0);
    }
    return (1);
}

//Funcion que valida el punto de vista inferior
int ft_validate_clues_buttom(int **array, int row, int col, int **clues, int number)
{
    int visibility;
    int max;
    int i;

    if (row == 0)
    {
        visibility = 0;
        max = 0;
        i = dimensions - 1;
        while (i >= 0)
        {
            if (array[i][col] > max)
            {
                max = array[i][col];
                visibility++;
            }
            i--;
        }
        if (clues[1][col] != visibility && clues[1][col] != 0)
            return (0);
    }
    return (1);
}

//Funcion que valida el punto de vista izquierdo
int ft_validate_clues_left(int **array, int row, int col, int **clues, int number)
{
    int visibility;
    int max;
    int i;

    if (col == dimensions - 1)
    {
        visibility = 0;
        max = 0;
        i = 0;
        while (i < dimensions)
        {
            if (array[row][i] > max)
            {
                max = array[row][i];
                visibility++;
            }
            i++;
        }
        if (clues[2][col] != visibility && clues[2][col] != 0)
            return (0);
    }
    return (1);
}

//Funcion que valida el punto de vista izquierdo
int ft_validate_clues_right(int **array, int row, int col, int **clues, int number)
{
    int visibility;
    int max;
    int i;

    if (col == 0)
    {
        visibility = 0;
        max = 0;
        i = dimensions - 1;
        while (i >= 0)
        {
            if (array[row][i] > max)
            {
                max = array[row][i];
                visibility++;
            }
            i--;
        }
        if (clues[3][col] != visibility && clues[3][col] != 0)
            return (0);
    }
    return (1);
}

//Funcion que controla las validaciones
int ft_is_valid(int ***array, int row, int col, int **clues, int number)
{
    if (!ft_validate_row_col(array, row, col, number))
        return (0);
    *array[row][col] = number; //Solucion temporal
    if (!ft_validate_clues_top(array, row, col, clues, number))
    {
        *array[row][col] = 0;
        return (0); 
    }
    if (!ft_validate_clues_buttom(array, row, col, clues, number))
    {
        *array[row][col] = 0;
        return (0);
    }
    if (!ft_validate_clues_left(array, row, col, clues, number))
    {
        *array[row][col] = 0;
        return (0);
    }
    if (!ft_validate_clues_right(array, row, col, clues, number))
    {
        *array[row][col] = 0;
        return (0);
    }
    return (1);
}

//Buscar solucion (aqui manejamos la mayor parte de la logica)
int ft_find_solution(int ***array, int row, int col, int **clues)
{
    int i;

    if (row == dimensions)
        return (1);
    if (col == dimensions)
        return (ft_find_solution(array, row + 1, column, 0, clues));
    i = 0;
    while (i < dimensions)
    {
        i++;
    }
}

// Reservar memoria y asignar 0 a cada posición
int **ft_reserve_memory(int **array)
{
    int i;
    int j;

    array = (int **) malloc(dimensions * sizeof(int *));
    i = 0;
    while (i < dimensions)
    {
        (array)[i] = (int *) malloc(dimensions * sizeof(int));
        j = 0;
        while (j < dimensions)
        {
            (array)[i][j] = 0;
            j++;
        }
        i++;
    }
    return (array);
}

// Liberamos la memoria de la matriz
void ft_free_array(int **array)
{
    int i;

    i = 0;
    while (i < dimensions)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

// Imprimir la matriz
void ft_print_array(int **array)
{
    int i;
    int j;
    char digit;

    i = 0;
    while (i < dimensions)
    {
        j = 0;
        while (j < dimensions)
        {
            digit = array[i][j] + '0';
            write(1, &digit, 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

//Main
int main()
{
    int **array;

    array = ft_reserve_memory(array);
    ft_print_array(array);
    ft_free_array(array);

    return (0);
}
