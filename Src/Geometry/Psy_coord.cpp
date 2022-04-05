#include "Psy_coord.H"
#include "CoordDefine.H"
void Psy_coord(const double lo_x,
               const double lo_y,
               const double Psy_L,
               const double Psy_H,
               const int N_x,
               const int N_y,
               const int num_ghost_cell,
               double *XYCOORD)
{

    const double dx = Psy_L / N_x;
    const double dy = Psy_L / N_x;
    double Li = lo_x;
    double Hi = lo_y;
    Li = -dx * num_ghost_cell + lo_x + dx / 2;
    Hi = -dy * num_ghost_cell + lo_y + dy / 2;
#pragma acc parallel loop
    for (int i = 0; i < N_x + 2 * num_ghost_cell; i++)
    {
#pragma acc loop
        for (int j = 0; j < N_y + 2 * num_ghost_cell; j++)
        {
            XYCOORD[Index_Coord(i, j, 0)] = Li + i * dx;
            XYCOORD[Index_Coord(i, j, 1)] = Hi + j * dx;
        }
    }
}

