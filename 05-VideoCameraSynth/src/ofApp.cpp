#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.setVerbose(true);
	grabber.setDeviceID(0);

	grabber.initGrabber(640,480);
	grabber.listDevices();		

    video.load( "jellyfishes.mov" );
	video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if ( grabber.isFrameNew() ) {
		mix();
	}
	video.update();
}


void ofApp::draw(){
	image.draw( 0, 0 );
    grabber.draw( image.getWidth() + 10, 0, 320, 240 );
}

//--------------------------------------------------------------
void ofApp::mix(){
    pixels = grabber.getPixels();

	//Get pixel arrays for grabber and video
    ofPixels &pixelsGrab = grabber.getPixels();
    ofPixels &pixelsVideo = video.getPixels();

	//Get width and height for formulas shortening
	int w = pixelsGrab.getWidth();
	int h = pixelsGrab.getHeight();

	//We proceed only if video and grabbing frames
	//have equal sizes
	if ( !(w == pixelsVideo.getWidth()
		&& h == pixelsVideo.getHeight()) ) {
			return;
	}

	//Scan pixels
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			ofColor colorGrab = pixelsGrab.getColor( x, y );

			//Shift x-coordinate by red component
            int x1 = x + (colorGrab.r - 127);

			//Truncate x1 to bounds
			x1 = ofClamp( x1, 0, w-1 );

			//Get color of pixel (x1, y) from video
			ofColor color = pixelsVideo.getColor( x1, y );

			//Set color to output pixel (x, y)
			pixels.setColor( x, y, color );
		}
	}
	//Update image pixels
	image.setFromPixels( pixels );
}

