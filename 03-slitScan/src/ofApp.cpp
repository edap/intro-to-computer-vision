#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    movie.load("jellyfishes.mov");
    movie.setLoopState(OF_LOOP_NORMAL);
    movie.play();
    img.allocate(imageWidth, imageHeight, OF_IMAGE_COLOR);
    videoPixels.allocate(videoWidth, videoHeight, OF_PIXELS_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
    movie.update();
    if (movie.isFrameNew()) {
        videoPixels = movie.getPixels();
        int slice = (mouseX < videoWidth) ? mouseX : videoWidth/2;

        for (int y=0; y<videoHeight; y++){
            auto midColumnColor = videoPixels.getColor(slice, y);
            img.setColor(drawPositionX, y, midColumnColor);
        }
        drawPositionX --;
        if (drawPositionX < 0) {
            drawPositionX = imageWidth - 1;
        }
        img.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    movie.draw(0,0);
    img.draw(videoWidth,0);

    ofPushStyle();
    ofSetColor(255,0,0);
    if(mouseX < videoWidth){
        ofDrawLine(mouseX,0,mouseX, videoHeight);
    }else{
        ofDrawLine(videoWidth/2,0,videoWidth/2, videoHeight);
    }
    ofPopStyle();

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
