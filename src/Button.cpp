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
    this->x = x;
    this->y = y;
    w = 95;
    h = 30;
    this->type = type;
    active = false;
    xoffset = 12;
    numCycles = 4;
    rateValue = 1;
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

void Button::draw(){
    ofNoFill();
    if(active){
        ofSetColor(220);
    }else{
        ofSetColor(80);
    }
    ofRectRounded(x,y,w,h,3);
    ofDrawBitmapString(name,x+xoffset,y+18);
}

bool Button::isInBounds(int x, int y){
    if(x > this->x && x < this->x+w && y > this->y && y < this->y + h){
        return true;
    }
    return false;
}

int Button::getNumCycles(){
    return numCycles;
}

double Button::getSpeedValue(){
    return speedValue;
}

double Button::getRateValue(){
    return rateValue;
}

void Button::activate(){
    active = true;
}

void Button::deactivate(){
    active = false;
}

bool Button::isActivated(){
    return active;
}