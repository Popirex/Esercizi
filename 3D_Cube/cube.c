#include "cube.h"

int draw_point(SDL_Surface* surface, int x, int y)
{
   SDL_Rect rect = (SDL_Rect) {x, y, POINT_SIZE, POINT_SIZE};
   SDL_FillRect(surface, &rect, COLOR_WHITE); 
}

void apply_rotation(Point *point, double alpha, double beta, double gamma)
{
    double rotation_matrix[3][3]= {{cos(alpha) * cos(beta), cos(alpha)*sin(beta)*sin(gamma)- sin(alpha) * cos(gamma), cos(alpha) * sin(beta)*cos(gamma) + sin(alpha) * sin(gamma)},  {sin(alpha)*cos(beta), sin(alpha)*sin(beta)*sin(gamma)+cos(alpha)*cos(gamma), sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma) }, { -sin(beta), cos(beta)*sin(gamma) , cos(beta) * cos(gamma) }};

    double point_vector[3] = {point->x, point->y, point->z};
    double result_point[3];

    for(int i = 0; i < 3; i++){
        double dot_product = 0;
        for(int j = 0; j < 3; j++){
            dot_product += rotation_matrix[i][j] * point_vector[j];
        }
        result_point[i] = dot_product;
    }
    point->x = result_point[0];
    point->y = result_point[1];
    point->z = result_point[2];
}

int draw_points_3d(SDL_Surface* surface, Point points[], int number_of_points)
{
    for(int i = 0; i < number_of_points; i++){


        int x_2d = points[i].x + COORDINATE_SYSTEM_OFFSET_X;
        int y_2d = points[i].y + COORDINATE_SYSTEM_OFFSET_Y;
        draw_point(surface, x_2d, y_2d);

    }
}

void inizialize_cube(Point points[], int number_of_points)
{
    //un cubo ha 12 lati
    int points_per_side = number_of_points / 12;
    int SIDE_LENGHT = 200;
    int step_size = SIDE_LENGHT / points_per_side;

    //lato1
    for(int i = 0 ; i < points_per_side;i++){
        points[i] = (Point){-SIDE_LENGHT/2 + i*step_size, -SIDE_LENGHT/2, +SIDE_LENGHT/2};
    }
    //lato 2
    for(int i = 0 ; i <  points_per_side;i++){
        points[i+points_per_side] = (Point){-SIDE_LENGHT/2 + i*step_size, SIDE_LENGHT/2, +SIDE_LENGHT/2};
    }

    //lato 3
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 2*points_per_side] = (Point){-SIDE_LENGHT/2, -SIDE_LENGHT/2 + i*step_size, +SIDE_LENGHT/2};
    }

    //lato 4
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 3*points_per_side] = (Point){SIDE_LENGHT/2, -SIDE_LENGHT/2 + i*step_size, +SIDE_LENGHT/2};
    }



    //lato 5
    for(int i = 0 ; i < points_per_side;i++){
        points[i+4*points_per_side] = (Point){-SIDE_LENGHT/2 + i*step_size, -SIDE_LENGHT/2, -SIDE_LENGHT/2};
    }

    //lato 6
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 5*points_per_side] = (Point){-SIDE_LENGHT/2 + i*step_size, SIDE_LENGHT/2, -SIDE_LENGHT/2};
    }

    //lato 7
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 6*points_per_side] = (Point){-SIDE_LENGHT/2, -SIDE_LENGHT/2 + i*step_size, -SIDE_LENGHT/2};
    }

    //lato 8
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 7*points_per_side] = (Point){SIDE_LENGHT/2, -SIDE_LENGHT/2 + i*step_size, -SIDE_LENGHT/2};
    }


    //lato 9
    for(int i = 0 ; i < points_per_side;i++){
        points[i+8*points_per_side] = (Point){-SIDE_LENGHT/2, -SIDE_LENGHT/2, -SIDE_LENGHT/2+i*step_size};
    }
    //lato 10
    for(int i = 0 ; i <points_per_side;i++){
        points[i+9*points_per_side] = (Point){SIDE_LENGHT/2, -SIDE_LENGHT/2, -SIDE_LENGHT/2+i*step_size};
    }

    //lato 11
    for(int i = 0 ; i < points_per_side;i++){
        points[i+ 10*points_per_side] = (Point){SIDE_LENGHT/2, SIDE_LENGHT/2, -SIDE_LENGHT/2+i*step_size};
    }

    //lato 12
    for(int i = 0 ; i < points_per_side;i++){
        points[i+11*points_per_side] = (Point){-SIDE_LENGHT/2, SIDE_LENGHT/2, -SIDE_LENGHT/2+i*step_size};
    }





}
