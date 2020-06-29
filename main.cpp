//Author: Addison Stotler
//Tic-Tac-Toe
//Date Modified: 10/02/2018

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include "SDLfunctions.h"
#include "box.h"

//SDL global variables
SDL_Window* window;
SDL_Event event;
SDL_Renderer* renderer;
SDL_Texture* xTexture;
SDL_Texture* oTexture;

bool activeGame = true;

//Functions
void renderXandO(Box* boxes[][3], SDL_Texture* xTexture, SDL_Texture* oTexture);
bool checkWinOrTie(Box* boxes[][3], int turn);
void drawLines(SDL_Renderer*& renderer);
void reset(Box* boxes[][3]);

int main()
{
    //TTF_Init();
  
    char string[100];
    int gameNumber = 1;
    int player1Scoar = 0;
    int player2Scoar = 0;
  
    //Tic-Tac-Toe variables
    int turn = 1;
    int player1Wins = 0;
    int player2Wins = 0;
    
    //Array of boxes
    Box* boxes[3][3];

    //Sets each box's x and y positions
    boxes[0][0] = new Box(0, 128, 0, 128);
    boxes[0][1] = new Box(192, 320, 0, 128);
    boxes[0][2] = new Box(384, 512, 0, 128);
    boxes[1][0] = new Box(0, 128, 192, 320);
    boxes[1][1] = new Box(192, 320, 192, 320);
    boxes[1][2] = new Box(384, 512, 192, 320);
    boxes[2][0] = new Box(0, 128, 384, 512);
    boxes[2][1] = new Box(192, 320, 384, 512);
    boxes[2][2] = new Box(384, 512, 384, 512);

    setupSDL(window, renderer);

    //Sets the color to Black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //loadImage: Loads all images into textures
    xTexture = loadImage(renderer, "X.png");
    oTexture = loadImage(renderer, "O.png");

    std::cout << "Player " << turn << "'s turn."<< std::endl; 

    while(1)
    {
	//SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
	drawLines(renderer);
      
	//TODO: Draw lines between squares
		
	//Quits the loop
	if(SDL_PollEvent(&event) > 0)
	{
	    switch(event.type)
	    {
	    case SDL_QUIT:
		exit(0);

	    case SDL_MOUSEBUTTONUP:
	    if((event.motion.x >= 462) && (event.motion.y >= 670))
		  reset(boxes);

	    	    
	    case SDL_MOUSEBUTTONDOWN:
	    checkWinOrTie(boxes, turn);

	    if(activeGame == true)
	    {
		//Uses the mouse location to determine what square was clicked there are 9 cases:
		//Top left case
		if((event.motion.x <= 128) && (event.motion.y <= 128))
		{
		    //Check to see if the square is available
		    if(boxes[0][0]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[0][0]->setState(1);
			    turn = 2;
    			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[0][0]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Top middle case
		else if(((event.motion.x >= 192) && (event.motion.x <= 320)) && (event.motion.y <= 128) )
		{
		    //Check to see if the square is available
		    if(boxes[0][1]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[0][1]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[0][1]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Top right case
		else if((event.motion.x >= 384) && (event.motion.y <= 128))
		{
		     //Check to see if the square is available
		    if(boxes[0][2]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[0][2]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[0][2]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Middle left case
		else if((event.motion.x <= 128) && ((event.motion.y >= 192) && (event.motion.y <= 320)))
		{
		    //Check to see if the square is available
		    if(boxes[1][0]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[1][0]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[1][0]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Middle middle case
		else if(((event.motion.x >= 192) && (event.motion.x <= 320)) && ((event.motion.y >= 192) && (event.motion.y <= 320)))
		{
		    //Check to see if the square is available
		    if(boxes[1][1]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[1][1]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[1][1]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Middle right case
		else if((event.motion.x >= 384) && ((event.motion.y >= 192) && (event.motion.y <= 320)))
		{
		    //Check to see if the square is available
		    if(boxes[1][2]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[1][2]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[1][2]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Bottom left case
		else if((event.motion.x <= 128) && (event.motion.y >= 384))
		{
		    //Check to see if the square is available
		    if(boxes[2][0]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[2][0]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[2][0]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Bottom middle case
		else if(((event.motion.x >= 192) && (event.motion.x <= 320)) && (event.motion.y >= 384))
		{
		    //Check to see if the square is available
		    if(boxes[2][1]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[2][1]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[2][1]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

		//Bottom right case
		else if((event.motion.x >= 384) && ((event.motion.y >= 384) && (event.motion.y <= 512)))
		{
		    //Check to see if the square is available
		    if(boxes[2][2]->getState() == 0)
		    {
			//Set state to 1 and change turn to 2
			if(turn == 1)
			{
			    boxes[2][2]->setState(1);
			    turn = 2;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
      			}

			//Set state to 2 and change turn to 1
			else
			{
			    boxes[2][2]->setState(2);
			    turn = 1;
			    std::cout << "Player " << turn << "'s turn."<< std::endl; 
			}
		    }
		}

	    }
	    }
	}

	drawLines(renderer);
	renderXandO(boxes, xTexture, oTexture);
	
	//10 FPS
	SDL_Delay(10);

    }  
    
    SDL_QUIT;
    return 0;
}

//This function runns through all boxes in the boxes array and
//renders xTexture and oTexture depending on the getState()
void renderXandO(Box* boxes[][3], SDL_Texture* xTexture, SDL_Texture* oTexture)
{
    //Rectangles
    SDL_Rect src;
    SDL_Rect dest;
    
    for(int x = 0; x < 3; x++)
    {
	for(int y = 0; y < 3; y++)
	{
	    if(boxes[x][y]->getState() == 1)
	    {
		src.x = 0; src.y = 0;
		src.w = 128; src.h = 128;

		dest.x = boxes[x][y]->getPositionX1(); dest.y = boxes[x][y]->getPositionY1();
	        dest.w = 128; dest.h = 128;

		SDL_RenderCopy(renderer, xTexture, &src, &dest);

	    }
	    
	    else if(boxes[x][y]->getState() == 2)
	    {
		src.x = 0; src.y = 0;
		src.w = 128; src.h = 128;

		dest.x = boxes[x][y]->getPositionX1(); dest.y = boxes[x][y]->getPositionY1();
	        dest.w = 128; dest.h = 128;

		SDL_RenderCopy(renderer, oTexture, &src, &dest);
	    }
		
	}
    }
}

//This function checks it see if there is a winner and is called after every turn
bool checkWinOrTie(Box* boxes[][3], int turn)
{
    if(activeGame == true)
    {
    //Checks virtical straights
    if((boxes[0][0]->getState() != 0) && (boxes[1][0]->getState() == boxes[0][0]->getState()) && (boxes[2][0]->getState() == boxes[0][0]->getState()))
    {
	std::cout << "Player " << turn << " wins!!" << std::endl;
	activeGame = false;
	return true;
    }

    if((boxes[0][1]->getState() != 0) && (boxes[1][1]->getState() == boxes[0][1]->getState()) && (boxes[2][1]->getState() == boxes[0][1]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

    if((boxes[0][2]->getState() != 0) && (boxes[1][2]->getState() == boxes[0][2]->getState()) && (boxes[2][2]->getState() == boxes[0][2]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

    //checks the horizontal straights
    if((boxes[0][0]->getState() != 0) && (boxes[0][1]->getState() == boxes[0][0]->getState()) && (boxes[0][2]->getState() == boxes[0][0]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

     if((boxes[1][0]->getState() != 0) && (boxes[1][1]->getState() == boxes[1][0]->getState()) && (boxes[1][2]->getState() == boxes[1][0]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

    if((boxes[2][0]->getState() != 0) && (boxes[2][1]->getState() == boxes[2][0]->getState()) && (boxes[2][2]->getState() == boxes[2][0]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

    //checks the diagonals
     if((boxes[0][0]->getState() != 0) && (boxes[1][1]->getState() == boxes[0][0]->getState()) && (boxes[2][2]->getState() == boxes[0][0]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }

     
    if((boxes[0][2]->getState() != 0) && (boxes[1][1]->getState() == boxes[0][2]->getState()) && (boxes[2][0]->getState() == boxes[0][2]->getState()))
    {
	if(turn == 1)
	    std::cout << "Player " << turn+1 << " wins!!" << std::endl;
	else
	    std::cout << "Player " << turn-1 << " wins!!" << std::endl;
	
	activeGame = false;
	return true;
    }
    }
    
    //int x = 0;
    //int y = 0;
    //for(x = 0; x < 3; x++)
    //{
    //	for(y=0;y < 3; y++)
    //	{
    	    
    //	    if((boxes[2][2]->getState() != 0) && ((x == 2) && (y == 2)))
    //	    {
    //		std::cout << "Draw!" << std::endl;
    //		return true;
	       
    //	    }
    //	}
    //	if(boxes[x][y]->getState() == 0)
    //	    break;
    //}
    return false;
    
}

//This function draws the lines seperating the boxes
//Draws 4 lines total
void drawLines(SDL_Renderer*& renderer)
{
    //Sets color to grey
    SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);

    //Horisontal lines
    for(int y = 144; y < 177; y++)
	SDL_RenderDrawLine(renderer, 0, y, 512, y);

    for(int y = 336; y < 369; y++)
	SDL_RenderDrawLine(renderer, 0, y, 512, y);

    //Vertical lines
    for(int x = 144; x < 177; x++)
	SDL_RenderDrawLine(renderer, x, 0, x, 512);

    for(int x = 336; x < 369; x++)
	SDL_RenderDrawLine(renderer, x, 0, x, 512);

    //Sets color back to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
}

void reset(Box* boxes[][3])
{

    for(int x = 0; x < 3; x++)
    {
	for(int y = 0; y < 3; y++)
	{
	    boxes[x][y]->setState(0);
	}
    }
    activeGame = true;

}
