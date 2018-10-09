#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <io.h>
#include <Windows.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <direct.h>
using namespace cv;
using namespace std;
extern int readDir(char *dirName, vector<string> &filesName);
int test37(int argc, char * argv[])
{
	string inputPath1 = "G:/F/交通标记检测/data/VOCtest_06-Nov-2007/VOCdevkit/VOC2007/JPEGImages";
	string inputPath2 = "G:/F/交通标记检测/data/VOCtest_06-Nov-2007/VOCdevkit/VOC2007/Annotations";
	string outputPath = "G:/F/交通标记检测/data/voc2007-test.txt";
	fstream fintrain;
	fintrain.open(outputPath, ios::out);
	if (!fintrain.is_open())
	{
		printf("fintrain,open fail!\n");
		system("pause");
	}
	vector<string> file;
	readDir((char*)inputPath1.c_str(), file);
	for (int i = 0; i < file.size(); i++)
	{
		string pathImg = file[i];
		Mat img = imread(pathImg.c_str());
		if (img.data == NULL)
		{
			printf("img.data==NULL\n");
			system("pause");
			continue;
		}
		int pos = pathImg.find_first_of('.');
		int pos2 = pathImg.find_last_of('/');
		string name1 = pathImg.substr(pos2 + 1, pos - pos2 - 1);
		string fullxml = inputPath2 + "/" + name1 + ".xml";
		fintrain << pathImg << " " << fullxml << endl;

		cout << pathImg << " " << fullxml << endl;
	}

	fintrain.close();
	return 0;
}