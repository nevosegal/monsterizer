#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetupScreen();
    ofSetVerticalSync(true);
    
    sampleRate 			= 44100; /* Sampling Rate */
    initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
    myInput = new float[initialBufferSize];
    speech.load(ofToDataPath("41252__303creative__the-air-steward.wav"));
    stretch = new maxiPitchStretch<grainPlayerWin>(&speech);
    hannedWindow = hanning(initialBufferSize);
    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    for(int i = 0 ; i <initialBufferSize-1; i++){
        ofLine(i,ofGetHeight()/2 + 20*myInput[i]*hannedWindow[i], i+1, ofGetHeight()/2 + 20*myInput[i+1]*hannedWindow[i]);
    }
}

void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    float sample;
    for(int i = 0; i < bufferSize; i++){
        myInput[i] = stretch->play(0.5, 0.8, 0.1, 4, 0);
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
