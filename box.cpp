//Author: Addison Stotler
//box.cpp
//Date Modified: 10/02/2018

#include "box.h"

//Box constructor
Box::Box(int positionX1_, int positionX2_, int positionY1_, int positionY2_)
    :positionX1(positionX1_), positionX2(positionX2_),
     positionY1(positionY1_), positionY2(positionY2_),
     state(0)
{}

//Getters
int Box::getState()
{
    return state;
}

int Box::getPositionX1()
{
    return positionX1;
}

int Box::getPositionX2()
{
    return positionX2;
}

int Box::getPositionY1()
{
    return positionY1;
}

int Box::getPositionY2()
{
    return positionY2;
}


//Setters
void Box::setState(int newState)
{
    state = newState;
}
