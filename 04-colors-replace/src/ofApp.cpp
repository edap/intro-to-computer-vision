#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    video.load( "jellyfishes.mov" );
	video.play();

	for ( int i=0; i<N_RANDOM_COLORS; i++ ) {
		randomColors[i] = ofRandom( 0, 255 );
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();

	if ( video.isFrameNew() ) {
        ofPixels pixels = video.getPixels();

		for (int y=0; y<pixels.getHeight(); y++) {
			for (int x=0; x<pixels.getWidth(); x++) {
				ofColor col = pixels.getColor( x, y );

				//Change color components using the random colors
                col.r = randomColors[ col.r/N_RANDOM_COLORS];
                col.g = randomColors[ col.g/N_RANDOM_COLORS ];
                col.b = randomColors[ col.b/N_RANDOM_COLORS ];

                // Invent your own algorithm
//                int index = (x+y) % N_RANDOM_COLORS;
//                col.r = randomColors[ col.r/randomColors[index] ];
//                col.g = randomColors[ col.g/randomColors[index] ];
//                col.b = randomColors[ col.b/randomColors[index] ];

				pixels.setColor( x, y, col );
			}
		}
		image.setFromPixels( pixels );
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	image.draw(0,0);	
}

