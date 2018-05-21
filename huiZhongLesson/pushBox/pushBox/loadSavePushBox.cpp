#include "loadSavePushBox.h"

void fileToMap(){
	static pushBoxMap* pushMap=new pushBoxMap();
	ifstream ifs("./maps/testMap.txt");
	int stage=0;
	ifs >> stage;
	pushMap->setIstage(stage);
	static int** boxMap = new int*[14];
	int** cboxMap = boxMap;
	for (int i = 0; i < 13; i++)//13ÐÐ
	{
		
		int* line = *cboxMap;
		string st;
		ifs >> st;
		for (string::iterator ist = st.begin(); ist != st.end(); ist++){
			//*line=(int)*ist;±¨´í
			cout << (int)*ist << endl;
			line++;
		}
		cboxMap++;
	}
	pushMap->setImap(boxMap);
	ifs.close();
	//return pushMap;
}