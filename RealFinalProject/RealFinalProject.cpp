//Final Project
//Sanity's Conflict
//Fausto Meza CS1
#include <iostream>
#include <Windows.h>
#include "MMSystem.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
//This will wait for the user 
//to press enter to continue
//Input
//option - an input that only accepts enter to continue
//Output
//continuing to the next order
bool Waiting(string option);
string action;
int choice;
int sanitylevel = 100;
//This will tell the intro of the story
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string IntroTeller(string action);
//This will tell the phase2 of the story
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string Phase2Teller(string action);
//This will tell a description of the house
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string HouseTeller(string action);
//This will tell a description of the inside part of the house
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string InsideHouseTeller(string action);
//This will tell a description of the frame
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string FrameTeller(string action);
//This will tell a description of the kitchen
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string KitchenTeller(string action);
//This will tell a description of what's inside the fridge
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string FridgeTeller(string action);
//This will tell a description of the upstairs room
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string UpstairsTeller(string action);
//This will tell a description when you're insane
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string InsaneTeller(string action);
//This will tell a description of hiding under the bed and in the closet
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string HidingTeller(string action);
//This will tell a description of when you jump out the window
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string OutsideTeller(string action);
//This will tell a description of staying to hide instead of jumping out
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string InsideTeller(string action);
//This will tell a description of the bad ending
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string BadEndingTeller(string action);
//This will tell a description of the good ending
//Input
//aciton - the user's string to interact
//Output
//the set of strings from the file
string GoodEndingTeller(string action);
int main()
{
	IntroTeller(action);
	Waiting(action);
	Phase2Teller(action);
	Waiting(action);
	cout << "0. Look Around 1. Open the front door" << endl;
	cin >> choice;
	switch (choice) {
	case 0:
		HouseTeller(action);
		Waiting(action);
		break;
	case 1:
		break;
	}
	cout << "Opening door" << endl;
	PlaySound(TEXT("Lock1.wav"), NULL, SND_SYNC | SND_FILENAME);
	cout << "The key is jammed..." << endl;
	Waiting(action);
	PlaySound(TEXT("Lock2.wav"), NULL, SND_SYNC | SND_FILENAME);
	Waiting(action);
	PlaySound(TEXT("OpenedDoor.wav"), NULL, SND_SYNC | SND_FILENAME);
	cout << "Door is open.." << endl;
	Waiting(action);
	InsideHouseTeller(action);
	Waiting(action);
	cout << "0. Look at frame 1. Go to the next room" << endl;
	cin >> choice;
	switch (choice) {
	case 0:
		FrameTeller(action);
		Waiting(action);
		break;
	case 1:
		break;
	}
	KitchenTeller(action);
	Waiting(action);
	cout << "Sanity Level: " << sanitylevel << endl;
	Waiting(action);
	cout << "0. Turn on Stove 1. Open Fridge" << endl;
	cin >> choice;
	switch (choice) {
	case 0:
		cout << "The fire only flickered for a second and went out.." << endl;
		sanitylevel = sanitylevel - 30;
		cout << "Sanity Level is now 70 (-30)" << endl;
		Waiting(action);
		break;
	case 1:
		break;
	}
	FridgeTeller(action);
	Waiting(action);
	PlaySound(TEXT("Footsteps.wav"), NULL, SND_SYNC | SND_FILENAME);
	cout << "Someone is coming!" << endl;
	Waiting(action);
	cout << "Hide upstairs before they catch you breaking into their home" << endl;
	Waiting(action);
	PlaySound(TEXT("Stairs.wav"), NULL, SND_SYNC | SND_FILENAME);
	UpstairsTeller(action);
	Waiting(action);
	cout << "0. Go under the bed 1. Go inside the closet" << endl;
	cin >> choice;
	switch (choice) {
	case 0:
		HidingTeller(action);
		Waiting(action);
		break;
	case 1:
		HidingTeller(action);
		Waiting(action);
		break;
	}
	PlaySound(TEXT("TV.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	cout << "'Okay I think the person turned the T.V. on, he doesn't know you're here..'" << endl;
	InsaneTeller(action);
	Waiting(action);
	PlaySound(TEXT("Glass.wav"), NULL, SND_SYNC | SND_FILENAME);
	cout << "The T.V. stopped. The person heard you from downstairs. There's a window." << endl;
	Waiting(action);
	PlaySound(TEXT("FNAFWAV.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	cout << "Sanity Level: " << sanitylevel - 50 << " (-50)" << endl;
	cout << "0. Jump out the window 1. Stay hiding in the room under the bed" << endl;
	cin >> choice;
	switch (choice) {
	case 0:
		sanitylevel = sanitylevel - 20;
		cout << "Sanity Level: " << sanitylevel << " (-20)" << endl;
		Waiting(action);
		OutsideTeller(action);
		Waiting(action);
		PlaySound(TEXT("ForestRun.wav"), NULL, SND_ASYNC | SND_FILENAME);
		Waiting(action);
		cout << "Running.. Limping.." << endl;
		PlaySound(TEXT("EndMusic.wav"), NULL, SND_ASYNC | SND_FILENAME);
		GoodEndingTeller(action);
		Waiting(action);
		cout << "Game Over" << endl;
		return 0;
	case 1:
		InsideTeller(action);
		Waiting(action);
		PlaySound(TEXT("GunReload.wav"), NULL, SND_SYNC | SND_FILENAME);
		Waiting(action);
		PlaySound(TEXT("EndMusic.wav"), NULL, SND_ASYNC | SND_FILENAME);
		BadEndingTeller(action);
		Waiting(action);
		cout << "Game Over" << endl;
		return 0;
		
	}


}







bool Waiting(string action) {
	do
	{
		cout << '\n' << "Press enter to continue..." << endl;
	} while (cin.get() != '\n');

	return 0;
}
string IntroTeller(string action){
	string introlines;
	ifstream introfile("Introduction.txt");
	if (introfile.is_open()) {
		while (getline(introfile, introlines)) {
			cout << introlines << endl;
		}
		introfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return introlines;

}
string Phase2Teller(string action) {
	string phase2lines;
	ifstream phase2file("Phase2.txt");
	if (phase2file.is_open()) {
		while (getline(phase2file, phase2lines)) {
			cout << phase2lines << endl;
		}
		phase2file.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return phase2lines;

}
string HouseTeller(string action) {
	string houselines;
	ifstream housefile("House.txt");
	if (housefile.is_open()) {
		while (getline(housefile, houselines)) {
			cout << houselines << endl;
		}
		housefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return houselines;

}
string InsideHouseTeller(string action) {
	string insidehouselines;
	ifstream insidehousefile("InsideHouse.txt");
	if (insidehousefile.is_open()) {
		while (getline(insidehousefile, insidehouselines)) {
			cout << insidehouselines << endl;
		}
		insidehousefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return insidehouselines;

}
string FrameTeller(string action) {
	string framelines;
	ifstream framefile("Frame.txt");
	if (framefile.is_open()) {
		while (getline(framefile, framelines)) {
			cout << framelines << endl;
		}
		framefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return framelines;

}
string KitchenTeller(string action){
	string kitchenlines;
	ifstream kitchenfile("Kitchen.txt");
	if (kitchenfile.is_open()) {
		while (getline(kitchenfile, kitchenlines)) {
			cout << kitchenlines << endl;
		}
		kitchenfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return kitchenlines;
}
string FridgeTeller(string action) {
	string fridgelines;
	ifstream fridgefile("Fridge.txt");
	if (fridgefile.is_open()) {
		while (getline(fridgefile, fridgelines)) {
			cout << fridgelines << endl;
		}
		fridgefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return fridgelines;
}
string UpstairsTeller(string action) {
	string upstairslines;
	ifstream upstairsfile("Upstairs.txt");
	if (upstairsfile.is_open()) {
		while (getline(upstairsfile, upstairslines)) {
			cout << upstairslines << endl;
		}
		upstairsfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return upstairslines;
}
string HidingTeller(string action) {
	string hidinglines;
	ifstream hidingfile("Hiding.txt");
	if (hidingfile.is_open()) {
		while (getline(hidingfile, hidinglines)) {
			cout << hidinglines << endl;
		}
		hidingfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return hidinglines;
}
string OutsideTeller(string action) {
	string outsidelines;
	ifstream outsidefile("Outside.txt");
	if (outsidefile.is_open()) {
		while (getline(outsidefile, outsidelines)) {
			cout << outsidelines << endl;
		}
		outsidefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return outsidelines;
}
string InsideTeller(string action) {
	string insidelines;
	ifstream insidefile("StayingInside.txt");
	if ( insidefile.is_open()) {
		while (getline(insidefile, insidelines)) {
			cout << insidelines << endl;
		}
		insidefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return insidelines;
}
string InsaneTeller(string action) {
	string insanelines;
	ifstream insanefile("Text.txt");
	if (insanefile.is_open()) {
		while (getline(insanefile, insanelines)) {
			cout << insanelines << endl;
		}
		insanefile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return insanelines;
}
string BadEndingTeller(string action) {
	string badendinglines;
	ifstream badendingfile("Bad.txt");
	if (badendingfile.is_open()) {
		while (getline(badendingfile, badendinglines)) {
			cout << badendinglines << endl;
		}
		badendingfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return badendinglines;
}
string GoodEndingTeller(string action) {
	string goodendinglines;
	ifstream goodendingfile("GoodEnding.txt");
	if (goodendingfile.is_open()) {
		while (getline(goodendingfile, goodendinglines)) {
			cout << goodendinglines << endl;
		}
		goodendingfile.close();
	}
	else {
		cout << "File not found" << endl;
	}
	return goodendinglines;
}




