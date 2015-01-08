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
    w = 65;
    h = 30;
    this->type = type;
    active = false;
    xoffset = 12;
    speech.load(ofToDataPath("41252__303creative__the-air-steward.wav"));
    stretch = new maxiPitchStretch<grainPlayerWin>(&speech);
    
    if(type == "robot"){
        name = "Robot";
    }
    else if (type == "monster"){
        name = "Monster";
        xoffset = 5;
    }
    else if (type == "alien"){
        name = "Alien";
    }
    else {
        name = "Human";
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

double Button::process(double input){
    
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