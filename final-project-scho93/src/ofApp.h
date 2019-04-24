#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVideoGrabber vid_grabber;
		int vid_width = 1280;
		int vid_height = 720;

		int space_key_count = 0;
		int s_key_count = 0;
		int r_key_count = 0;

		bool reset = false;

		// Rubik's Cube RGB values inspired from https://www.schemecolor.com/rubik-cube-colors.php.
		const ofColor white = ofColor(255, 255, 255);
		const ofColor yellow = ofColor(255, 213, 0);
		const ofColor red = ofColor(200, 0, 0);
		const ofColor orange = ofColor(255, 85, 0);
		const ofColor green = ofColor(0, 155, 72);
		const ofColor blue = ofColor(0, 69, 173);

		const vector<ofColor> cube_colors = { white, yellow, red, orange, green, blue };

		vector<ofColor> average_pixel_color = vector<ofColor>(9);
		vector<ofColor> estimated_pixel_color = vector<ofColor>(9);

		ofImage white_side;
		ofImage yellow_side;
		ofImage red_side;
		ofImage orange_side;
		ofImage green_side;
		ofImage blue_side;

		bool white_captured = false;
		bool yellow_captured = false;
		bool red_captured = false;
		bool orange_captured = false;
		bool green_captured = false;
		bool blue_captured = false;

		int getXCoordinate(int n);
		int getYCoordinate(int n);
		ofColor getAverageColor(int n);
		ofColor ComputeAverageColor(int xBegin, int xEnd, int yBegin, int yEnd);
		double ofApp::ColorDifference(const ofColor default_color, const ofColor input_color);
		ofColor EstimateColor(const ofColor input_color);
};
