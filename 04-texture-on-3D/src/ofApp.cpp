#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // play with the zoom value of the camera
    cam.setDistance(200);

    fbo.allocate(planeWidth, camHeight);
    fbo.begin();
    ofClear(255,255,255);
    fbo.end();

    // what if you change these values?
    int xPos = -camWidth/2;
    int zPos = 0;
    for (int i = 0; i<nPlanes; i++) {
        zPos = ofRandom(-100,100);
        ofPlanePrimitive p;
        p.set(planeWidth, camHeight, 2, 2);
        // try to play around a bit positioning the rectangles
        //p.setPosition(xPos + (i*planeWidth) + 2, 0, zPos + (i * -100));
        p.setPosition(xPos + (i*planeWidth), 0, zPos);
        planes.push_back(p);
    }

    // Camera grabbing
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();

    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    ofSetVerticalSync(true);

    gui.setup("gui");
    gui.add(freq.set("freq", 0.5, 0., 10.));
    gui.add(amp.set("amp", 0.8, 0., 10.));
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0, 0, 0);
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);

    cam.begin();
    ofEnableDepthTest();

    int startX = 0;
    for (auto &p:planes) {
        fbo.begin();
        ofClear(255,255,255);
        // get a texture from the camera
        auto videoTexture = vidGrabber.getTexture();
        // draw a subsection. startX is incrementing while iterating through
        // the loop
        videoTexture.drawSubsection(0, 0, camWidth, camHeight, startX, 0);
        fbo.end();

        // now get the fbo out of the texture.
        auto tex = fbo.getTexture();
        tex.bind();
        p.mapTexCoords(0,0,planeWidth, camHeight);

        // what happens if you change these parameters?
        // could you imagine using other values for the angle
        //float angle = ofSignedNoise((ofGetElapsedTimef() + startX) * freq) * amp;
        float angle = sin((ofGetElapsedTimef() + startX) * freq) * amp;
        p.rotateDeg(angle, glm::vec3(0,1,0));
        p.draw();
        tex.unbind();

        // increment startX
        startX += planeWidth;
    }

    ofDisableDepthTest();
    cam.end();

    if(drawGui){
        gui.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g'){
        drawGui = !drawGui;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}
