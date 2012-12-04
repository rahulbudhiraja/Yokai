#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // The Scenes
    
        int sceneNumber;
    
        void loadScene();
    
        void scene1();
        void scene2();
        void scene3();
        void scene4();
        void scene5();
        void scene6();
        void scene7();
        void scene8();
        void scene9();
        void scene10();

        ofVec2f universalScale;
    
        // Loading the square image ...
    
        ofImage sqImg;
    
        ofTexture circleTexture;
    
        vector <ofPoint> NormCirclePts;
        vector <ofPoint> NormCircleCoords;
    
        void loadandConvertTexture();
        void drawCircle();

        // River Thickness ..

        float river_thickness;

        bool startAnimation;


/// Useless ..
        vector<ofVec2f> previousStates;
        void drawPreviousStates(int i);

        float xCoords[1000],yCoords[1000];


        ///// 3D model loading ...

};
