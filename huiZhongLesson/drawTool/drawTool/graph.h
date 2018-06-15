#include <windows.h>
#include <string>
using namespace std;

class graph{

private:
	int g_nwidth;
	int g_nheight;
	POINT g_poLocation;
	string g_sName;
	int g_nstate;











	/*
		get and set	
	*/
public:
	int getNWidth(){
		return g_nwidth;
	}
	int getNHeight(){
		return g_nheight;
	}
	POINT getPoLocation(){
		return g_poLocation;
	}
	string getSName(){
		return g_sName;
	}
	int getNState(){
		return g_nstate;
	}
	void setNWidth(int width){
		this->g_nwidth = width;
	}
	void setNHeight(int height){
		this->g_nheight = height;
	}
	void setPoLocation(POINT location){
		this->g_poLocation = location;
	}
	void setSName(string name){
		this->g_sName = name;
	}
	void setNState(int state){
		this->g_nstate = state;
	}
};