//
//  Button.h
//  monsterizer
//
//  Created by Nevo Segal on 29/12/2014.
//
//

#ifndef __monsterizer__Button__
#define __monsterizer__Button__

#include <stdio.h>
#include "ofMain.h"
#include "maxiGrains.h"

typedef hannWinFunctor grainPlayerWin;
class Button{
public:
    Button();
    Button(int x,int y, string type);
    
    void draw();
    bool isInBounds(int x, int y);
    void activate();
    void deactivate();
    bool isActivated();
    double process(double input);
    
    int x,y,w,h;
    bool active;
    string type;
    ofImage img;
    string name;
    int xoffset;
    double rateValue, speedValue;
    maxiPitchStretch<grainPlayerWin> *stretch;
    ofxMaxiSample speech;
};

#endif /* defined(__monsterizer__Button__) */
