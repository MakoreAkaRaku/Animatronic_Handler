#pragma once
#include "../includes/EyesHandler.h"

bool EyesHandler::isAvailable = false;
//Initializing static servos.
Servo EyesHandler::usedServo[]={ Servo(), Servo(), Servo()}; 

bool EyesHandler::IsAvailable()
{
    return isAvailable;
}

bool EyesHandler::Attach(uint8_t pinIds[NUM_OF_SERVOS_USED])
{
    isAvailable = true;
    for (uint8_t i = 0; i < NUM_OF_SERVOS_USED; i++)
    {
        //if attaching servos applied on the board exceeds the max ammount return false.
        if( usedServo[i].attach(pinIds[i]) == MAX_SERVOS)
        {
            printf("EyesHandler: Maximum amount of servos already in use!");
            isAvailable = false;
            break;
        }
    }
    //everything is correctly attached
    return isAvailable;
}

void EyesHandler::MoveEyes(EyeMovement movements[])
{
    uint8_t numOfMoves = sizeof(movements)/sizeof(EyeMovement);
    
    if (numOfMoves > NUM_OF_SERVOS_USED)
    {
        //Evading non controlled behaviour for extended parallel movements.
        return;
    }
    for (uint8_t i = 0; i < numOfMoves; i++)
    {
        ///TODO: Check if there's incongruencies like distinctions of NONE and VERTICAL OR HORIZONTAL.
    }
     
}