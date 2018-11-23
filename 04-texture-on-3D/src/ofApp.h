#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    ofVideoGrabber vidGrabber;

    int camWidth = 320;
    int camHeight = 240;
    int nPlanes = 40;
    int planeWidth = camWidth/nPlanes;

    vector<ofPlanePrimitive> planes;

    ofEasyCam cam;
    ofxPanel gui;
    bool drawGui = true;
    ofFbo fbo;
    ofParameter<float> freq;
    ofParameter<float> amp;
};
