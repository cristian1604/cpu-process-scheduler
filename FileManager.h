#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include "Process.h"
using namespace std;

class FileManager {
public:
	FileManager();
	bool quickLoad(vector <Process> &Vec);
	bool quickSave(vector <Process> &Vec);
	bool load();
	bool save();
private:
};

#endif

