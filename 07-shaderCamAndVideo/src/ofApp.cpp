#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video setup
    ofDisableArbTex();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 8);
    fbo.begin();
    ofBackground(0);
    //ofClear(0,0,0,1);
    fbo.end();

    movie.load("jellyfishes.mov");
    movie.play();
    cam.setup(1024, 720);
    shader.load("shader/vertex.glsl", "shader/fragment.glsl", "");
    plane.set(ofGetWidth(), ofGetHeight(), 2,2);
    plane.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    movie.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform1f("uTime", ofGetElapsedTimef());
    shader.setUniformTexture("tex0", cam.getTexture(), 0);
    shader.setUniformTexture("tex1", movie.getTexture(), 1);
    shader.setUniformTexture("tex2", fbo.getTexture(), 2);
    float resolution[] = { float(ofGetWidth()), float(ofGetHeight()) };
    shader.setUniform2fv("resolution",resolution);

    plane.draw();
    shader.end();

    //fbo.draw(0,0);

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
    fbo.begin();
    int saturation = 255;
    int brightness = 255;
    int alpha = 200;
    float sinOfTime = sin(ofGetElapsedTimef() * 0.5);
    float hue = ofMap(sinOfTime, -1, 1, 0, 255);
    ofColor c = ofColor::fromHsb(hue, saturation, brightness);
    c.a = alpha;
    ofPushStyle();
    ofSetColor(c);
    ofDrawCircle(x, y, sin(ofGetElapsedTimef()* 3.0) * 40);
    ofPopStyle();
    fbo.end();
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
