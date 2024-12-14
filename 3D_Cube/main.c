#include "cube.h"

int main(){
    //parametri iniziali
    SDL_Rect black_screen_rect = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    int number_of_points = 1200;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("3D Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

//definizione strutture
    Point points[number_of_points];

//funzioni

    inizialize_cube(points, number_of_points);

    draw_points_3d(surface, points, number_of_points);

    SDL_Event event;
    int simulation_runnig = 1;
    double alpha = 0.005;
    double beta = 0.02;
    double gamma = 0.03;

    while(simulation_runnig){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                simulation_runnig = 0;
            }
        }


        SDL_FillRect(surface, &black_screen_rect, COLOR_BLACK);

        for(int i = 0; i < number_of_points; i++){
        apply_rotation(&points[i], alpha, beta, gamma);
        }
        draw_points_3d(surface, points, number_of_points);
        SDL_UpdateWindowSurface(window);
        SDL_Delay(20);
    }
}