#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    if(useCamera){
        cam.setup(640, 480);
    }else{
        movie.load("jellyfishes.mov");
        movie.setLoopState(OF_LOOP_NORMAL);
        movie.play();
    }

    gui.setup();
    gui.add(minArea.set("Min area", 10, 1, 100));
    gui.add(maxArea.set("Max area", 200, 1, 500));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(holes.set("Holes", false));
    gui.add(cannyThreshold1.set("cannyThreshold1", 128, 0, ofGetWidth()));
    gui.add(cannyThreshold2.set("cannyThreshold2", 128, 0, ofGetHeight()));
    gui.add(drawMeshes.set("draw Meshes", false));
    gui.add(drawPaths.set("draw Paths", false));
}

void ofApp::update() {
    if (useCamera) {
        cam.update();
        if (cam.isFrameNew()) {
            // homework. Check the blur filter and see how it can helps you
            convertColor(cam, gray, CV_RGB2GRAY);
            Canny(gray, edge, cannyThreshold1, cannyThreshold2, 3);
            Sobel(gray, sobel);
            gray.update();
            sobel.update();
            edge.update();

            contourFinder.setMinAreaRadius(minArea);
            contourFinder.setMaxAreaRadius(maxArea);
            contourFinder.setThreshold(threshold);
            if(mode =="video"){
               contourFinder.findContours(cam);
            }else if(mode =="edge"){
                contourFinder.findContours(edge);
            }else if(mode =="sobel"){
                contourFinder.findContours(sobel);
            }else{
                contourFinder.findContours(cam);
            }

            contourFinder.setFindHoles(holes);
        }
    }else{
        movie.update();
        if (movie.isFrameNew()) {
            convertColor(movie, gray, CV_RGB2GRAY);
            Canny(gray, edge, cannyThreshold1, cannyThreshold2, 3);
            Sobel(gray, sobel);
            gray.update();
            sobel.update();
            edge.update();

            contourFinder.setMinAreaRadius(minArea);
            contourFinder.setMaxAreaRadius(maxArea);
            contourFinder.setThreshold(threshold);
            if(mode =="video"){
               contourFinder.findContours(movie);
            }else if(mode =="edge"){
                contourFinder.findContours(edge);
            }else if(mode =="sobel"){
                contourFinder.findContours(sobel);
            }else{
                contourFinder.findContours(movie);
            }

            contourFinder.setFindHoles(holes);
        }
    }
    updatePaths();
}

void ofApp::draw() {


    if(useCamera){
      cam.draw(640, 0);
    }else{
      movie.draw(640,0, 640, 480);
    }

    ofPushStyle();
    ofSetColor(ofFloatColor::blueViolet);
    contourFinder.draw();
    ofPopStyle();
    edge.draw(0, 480);
    sobel.draw(640, 480);
    gui.draw();

    // draw the paths
    drawPathsAndMeshes();
}

void ofApp::updatePaths(){
    paths.clear();
    meshes.clear();

    if (drawMeshes || drawPaths) {
        for(auto poly:contourFinder.getPolylines()){
            ofPath path;
            for(auto v:poly.getVertices()){
              path.lineTo(v.x, v.y);
            }
            path.close();
            path.setFilled(true);
            path.setFillColor(ofFloatColor::red);
            path.setStrokeColor(ofFloatColor::white);
            path.setStrokeWidth(3.0);
            paths.push_back(path);

            ofVboMesh mesh;
            mesh = path.getTessellation();
            meshes.push_back(mesh);
        }
    }
}

void ofApp::drawPathsAndMeshes(){
    if(drawPaths){
        for(auto p:paths){
            p.draw();
        }
    }

    if(drawMeshes){
        ofPushStyle();
        ofSetColor(0, 255, 0);
        for(auto m:meshes){
            m.drawWireframe();
        }
        ofPopStyle();
    }
}

void ofApp::keyPressed(int key){
    if(key == 'e'){
        mode = "edge";
    }
    if(key == 's'){
        mode = "sobel";
    }
    if(key== 'v'){
        mode = "video";
    }
}
