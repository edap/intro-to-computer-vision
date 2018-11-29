#pragma once
#include "ofMain.h"

const int N_RANDOM_COLORS = 30;

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofVideoPlayer video;	//Declare video player object
	ofImage image;		//Declare image object
	int randomColors[N_RANDOM_COLORS];		//Declare table for color replacing
};
