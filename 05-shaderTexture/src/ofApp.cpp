#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    cam.setup(1280, 720);
    shader.load("shaders/vert.glsl", "shaders/frag.glsl");

    plane.set(ofGetWidth(), ofGetHeight(), 2, 2, OF_PRIMITIVE_TRIANGLES);
    plane.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.getTexture().bind();
    shader.begin();
    // pass a uniform with mouse pos.
    shader.setUniformTexture("tex0", cam.getTexture(), 0);
    shader.setUniform2f("uMousePos", mouseX, mouseY);
    shader.setUniform2f("uResolution", ofGetWidth(), ofGetHeight());
    plane.draw();
    shader.end();
    cam.getTexture().unbind();
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
