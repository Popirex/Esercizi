#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#define SCREEN_WIDTH  900
#define SCREEN_HEIGHT  600
#define COLOR_WHITE  0xffffffff
#define COLOR_BLACK 0x00000000
#define POINT_SIZE  5
#define COORDINATE_SYSTEM_OFFSET_X  SCREEN_WIDTH / 2
#define COORDINATE_SYSTEM_OFFSET_Y  SCREEN_HEIGHT / 2
#define phi  5

typedef struct{
    double x;
    double y;
    double z;
} Point;

int draw_point(SDL_Surface* surface, int x, int y);

void apply_rotation(Point *point, double alpha, double beta, double gamma);

int draw_points_3d(SDL_Surface* surface, Point points[], int number_of_points);

void inizialize_cube(Point points[], int number_of_points);