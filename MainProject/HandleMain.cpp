#include "HandleMain.h"

std::ofstream createFile(std::string strUsernameFile) {
	std::string filePath = USERS_INFO_FOLDER + strUsernameFile + ".txt";
	std::ofstream fileTemp(filePath);
	return fileTemp;
}
std::ifstream openFile(std::string strUsernameFile) {
	std::string filePath = USERS_INFO_FOLDER + strUsernameFile + ".txt";
	std::ifstream fileTemp;
	fileTemp.open(filePath);
	return fileTemp;
}
void deleteFile(std::string strUsernameFile) {
	std::string filePath = "del " + USERS_INFO_FOLDER + strUsernameFile + ".txt";
	system(filePath.c_str());
}

void deleteAccount(std::string strSourceFile, std::string strUsername) {
	CUser userTemp;
	//Step 1:
	std::string employeeFileRenamed = strSourceFile;
	rename(strSourceFile.c_str(), employeeFileRenamed.insert(employeeFileRenamed.size() - 4, "Temp").c_str());
	//Step 2:
	std::ofstream fileOut(strSourceFile);
	std::ifstream fileIn;
	fileIn.open(employeeFileRenamed.c_str());
	//Step 3:
	while (!fileIn.eof()) {
		userTemp.readAccount(fileIn);
		if (userTemp.getUsername() != strUsername && userTemp.getUsername() != "")
			userTemp.writeAccount(fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	system(employeeFileRenamed.insert(0, "del ").c_str());
}

void showAccountInfo(std::string strUsername) {
	CUser userTemp;
	std::ifstream fileIn = openFile(strUsername);
	userTemp.readInfo(fileIn);
	userTemp.output();
	fileIn.close();
}

bool hasUsername(std::string strSourceFile, std::string strUsername) {
	std::ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser userTemp;
		userTemp.readAccount(fileIn);
		if (strUsername == userTemp.getUsername()) {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
bool hasAccount(std::string strSourceFile, std::string strUsername, std::string strPassword) {
	std::ifstream fileIn;
	fileIn.open(strSourceFile.c_str());
	while (!fileIn.eof()) {
		CUser userTemp;
		userTemp.readAccount(fileIn);
		if (strUsername == userTemp.getUsername() && strPassword == userTemp.getPassword() && userTemp.getUsername() != "" && userTemp.getPassword() != "") {
			fileIn.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
