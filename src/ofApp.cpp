#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetupScreen();
    ofSetVerticalSync(true);
    
    numButtons = 4;
    buttons = new Button[numButtons];
    buttons[0] = *new Button(40, 40, "human");
    buttons[1] = *new Button(150, 40, "monster");
    buttons[2] = *new Button(260, 40, "robot");
    buttons[3] = *new Button(370, 40, "alien");
    buttons[0].activate();
    
    speech.load(ofToDataPath("41252__303creative__the-air-steward.wav"));
    stretch = new maxiPitchStretch<grainPlayerWin>(&speech);
    
    sampleRate 			= 44100; /* Sampling Rate */
    initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
    myInput = new float[initialBufferSize];
    hannedWindow = hanning(initialBufferSize);
    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    ofSetColor(255);
    for(int i = 0 ; i <initialBufferSize-1; i++){
        ofLine(i,ofGetHeight()/2 + 30*myInput[i]*hannedWindow[i], i+1, ofGetHeight()/2 + 30*myInput[i+1]*hannedWindow[i]);
    }
    for(int i = 0; i < numButtons; i++){
        buttons[i].draw();
    }
}

void ofApp::audioRequested(float * output, int bufferSize, int nChannels){
    for(int i = 0; i < bufferSize; i++){
        for(int j = 0; j < numButtons; j++){
            if(buttons[j].isActivated()){
                myInput[i] = stretch->play(buttons[j].getSpeedValue(), buttons[j].getRateValue(), 0.1, buttons[j].getNumCycles(), 0);
                break;
            }
        }
        mymix.stereo(myInput[i], outputs, 0.5);
        output[i*nChannels] = outputs[0];
        output[i*nChannels+1] = outputs[1];
    }

}
//--------------------------------------------------------------
void ofApp::audioReceived (float * input, int bufferSize, int nChannels){

}

float* ofApp::hanning(int bufferSize){
    float* hanning = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        hanning[i] = 0.5 - 0.5*cos(2*PI*i/(bufferSize-1));
    }
    return hanning;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0 ; i < numButtons; i++){
        if(buttons[i].isInBounds(x, y)){
            buttons[i].activate();
            for(int j = 0 ; j < numButtons; j++){
                if(i!=j){
                    buttons[j].deactivate();
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
