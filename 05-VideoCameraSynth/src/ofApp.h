#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofVideoGrabber 	grabber;
	ofVideoPlayer 	video;
	ofImage image;

    ofPixels pixels;

	void mix();
};
