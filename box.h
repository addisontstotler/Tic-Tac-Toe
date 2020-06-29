//Author: Addison Stotler
//box.h
//Date Modified: 10/02/2018

#ifndef BOX
#define BOX

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_image.h"

class Box
{
  public:
    //Constructor
    Box(int poitionX1_, int positionX2_, int positionY1_, int positionY2_);

    //Getters
    int getState();
    int getPositionX1();
    int getPositionX2();
    int getPositionY1();
    int getPositionY2();
    
    //Setters
    void setState(int newState);
    
  private:
    int state;
    int positionX1;
    int positionX2;
    int positionY1;
    int positionY2;
};

#endif
