#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "Button.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioRequested 	(float * input, int bufferSize, int nChannels); /* output method */
    void audioReceived 	(float * input, int bufferSize, int nChannels); /* input method */
    float* hanning(int bufferSize);
    
    int		initialBufferSize; /* buffer size */
    int		sampleRate;
    float* myInput;
    double outputs[2];
    ofxMaxiMix mymix;

    float* hannedWindow;
    Button* buttons;
    int numButtons;
    maxiPitchStretch<grainPlayerWin> *stretch;
    ofxMaxiSample speech;
};
