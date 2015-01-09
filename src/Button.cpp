//
//  Button.cpp
//  monsterizer
//
//  Created by Nevo Segal on 29/12/2014.
//
//

#include "Button.h"

Button::Button(){
    
}

Button::Button(int x, int y, string type){
    
    //initial stuff
    this->x = x;
    this->y = y;
    w = 95;
    h = 30;
    this->type = type;
    active = false;
    xoffset = 12;
    numCycles = 4;
    rateValue = 1;
    
    //set some variables according to the type.
    if(type == "robot"){
        name = "Robotize!";
        speedValue = 1.6;
        numCycles = 8;
    }
    else if (type == "monster"){
        name = "Monsterize!";
        xoffset = 5;
        speedValue = 0.55;
    }
    else if (type == "alien"){
        name = "Alienize!";
        speedValue = 2;
        rateValue = 3;
    }
    else {
        name = "Humanize!";
        speedValue = 1;
    }
}

//drawing the buttons
void Button::draw(){
    ofNoFill();
    
    //changing the color of button is active
    if(active){
        ofSetColor(220);
    }
    else{
        ofSetColor(80);
    }
    ofRectRounded(x,y,w,h,3);
    ofDrawBitmapString(name,x+xoffset,y+18);
}

//checking if the button is hovered.
bool Button::isInBounds(int x, int y){
    if(x > this->x && x < this->x+w && y > this->y && y < this->y + h){
        return true;
    }
    return false;
}

//getters
int Button::getNumCycles(){
    return numCycles;
}

double Button::getSpeedValue(){
    return speedValue;
}

double Button::getRateValue(){
    return rateValue;
}

//activate the button
void Button::activate(){
    active = true;
}

//deactivate the button
void Button::deactivate(){
    active = false;
}

//check if the button is activated
bool Button::isActivated(){
    return active;
}