#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Process.h"
using namespace std;

FileManager::FileManager() {
	
}


bool FileManager::quickLoad(vector <Process> &Vec) {
	//carga la última lista de procesos almacenada 
	
	fstream archivo;
	archivo.open("data.bin",ios::binary|ios::in);
	stProcess carga;
	
	if (archivo.is_open()) {
		while (archivo) {
			archivo.read((char *) &carga, sizeof(stProcess));
			if (archivo.eof()) break;
			Process P(carga);
			Vec.push_back(P);
		}
		archivo.close();
		return true;
	}
	return false;
}


bool FileManager::quickSave(vector <Process> &Vec) {
	//guarda la lista de procesos actual
	
	fstream archivo;
	archivo.open("data.bin",ios::binary|ios::out);
	stProcess escribe;
	int pos = 0;
	
	if (archivo.is_open()) {
		while (pos < Vec.size()) {
			escribe = Vec[pos].toStruct();
			archivo.write((char *) &escribe,sizeof(stProcess));
			pos++;
		}
		archivo.close();
		return true;
	}
	return false;
}


bool FileManager::load() {
	//carga la lista completa de alumnos
	
	/*fstream archivo;
	archivo.open("binario.bin",ios::binary|ios::in);
	pair <int,Ficha> par;
	stFicha carga;
	
	if (archivo.is_open()) {
		while (archivo) {
			archivo.read((char *) &carga, sizeof(stFicha));
			if (archivo.eof()) break;
			Ficha I(carga);
			int clave = I.retDni();
			M[clave] = I;
		}
		archivo.close();
		return true;
	}*/
	return false;
}


bool FileManager::save() {
	//guarda la lista completa de alumnos
	
	/*fstream archivo;
	archivo.open("binario.bin",ios::binary|ios::out);
	
	map <int,Ficha>::iterator p = M.begin();
	stFicha Q;
	
	if (archivo.is_open()) {
		while (p != M.end()) {
			(p->second).convStruct(Q);
			archivo.write((char *) &Q,sizeof(stFicha));
			p++;
		}
		archivo.close();
		return true;
	}*/
	return false;
}

