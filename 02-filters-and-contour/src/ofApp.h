#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void drawPathsAndMeshes();
    void updatePaths();
    void keyPressed(int e);
	
    ofVideoGrabber cam;
    ofVideoPlayer movie;
	ofxCv::ContourFinder contourFinder;
    
    ofxPanel gui;
    ofParameter<float> minArea, maxArea, threshold, cannyThreshold1, cannyThreshold2;
    ofParameter<bool> holes;
    ofParameter<bool> drawMeshes;
    ofParameter<bool> drawPaths;
    std::string mode = "video";
    bool useCamera = false;

    vector<ofPath> paths;
    vector<ofVboMesh> meshes;


    //filtering
    ofImage gray, edge, sobel;
};
