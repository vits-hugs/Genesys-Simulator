/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Util.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 13:02
 */


//
// VINCULADOR 
// SAIDA
// ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/genesysterminalapplication
//



#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <typeinfo>
#include <string>
#include <list>
#include <cctype>
#include <algorithm>
#include <cctype>
#include <locale>
#include <stdio.h>
// dir
#include <limits.h>
#include <unistd.h>
#include <vector>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <sys/stat.h>
#include <cstring>
//namespace GenesysKernel {
// trim from start (in place)

/*
static inline void ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
				return !std::isspace(ch);
		}));
}

// trim from end (in place)

static inline void rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
				return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)

static inline void trim(std::string &s) {
		ltrim(s);
		rtrim(s);
}
 */

class Util {
public:
	typedef unsigned long identification;
	typedef unsigned int rank;

	//@TODO: Should be insde ModelSimulation, where time goes on

	enum class TimeUnit : int {
		picosecond = 1,
		nanosecond = 2,
		microsecond = 3,
		milisecond = 4,
		second = 5,
		minute = 6,
		hour = 7,
		day = 8,
		week = 9
	};
	static std::string StrTimeUnitShort(Util::TimeUnit timeUnit);
	static std::string StrTimeUnitLong(Util::TimeUnit timeUnit);

	enum class AllocationType : int {
		ValueAdded = 1, NonValueAdded = 2, Transfer = 3, Wait = 4, Others = 5
	};
	static std::string StrAllocation(Util::AllocationType allocation);

private:
	static unsigned int _S_indentation;
	static Util::identification _S_lastId;
	static std::map<std::string, Util::identification> _S_lastIdOfType;
	static std::map<std::string, std::string> _S_TypeOf;

public: // indentation and string
	static void SetIndent(const unsigned short indent);
	static void IncIndent();
	static void DecIndent();
	static void SepKeyVal(std::string str, std::string *key, std::string *value);
	static std::string Indent();
	static std::string SetW(std::string text, unsigned short width);
	static std::string strTruncIfInt(double value);
	static std::string strTruncIfInt(std::string strValue);
	static std::string trim(std::string str);
	static std::string strReplace(std::string text, std::string searchFor, std::string replaceBy);
	static std::string strIndex(int index);
	static void trimwithin(std::string &str);
public: // show strucutres
	static std::string map2str(std::map<std::string, std::string>* mapss);
	static std::string map2str(std::map<std::string, double>* mapss);
	static std::string list2str(std::list<unsigned int>* list);
public: // identitification //@TODO: CHECK ALL, since some should be private and available to FRIEND classes in the kernel
	static Util::identification GenerateNewId();
	static Util::identification GenerateNewIdOfType(std::string objtype);
	static Util::identification GetLastIdOfType(std::string objtype);
	static void ResetIdOfType(std::string objtype);
	static void ResetAllIds();

public: // simulation support
	static double TimeUnitConvert(Util::TimeUnit timeUnit1, Util::TimeUnit timeUnit2);

public: // files
	static char dirSeparator();
	static std::string getFileName(const std::string& s);
	static void deleteFile(const std::string& filename);
	static inline std::string getPath(const std::string& s);

	/*
	static std::string getRunningPath() {
			char result[ PATH_MAX ];
			ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
			std::string fullfilename = std::string(result, (count > 0) ? count : 0);
			return getPath(fullfilename);
	}

	static std::vector<std::string> listFiles(std::string dir, std::string fileFilter = "", mode_t attribFilter = S_IFREG & S_IFDIR) {
			std::vector<std::string> files;
			DIR *dp;
			struct dirent *dirp;
			struct stat statbuffer;
			if ((dp = opendir(dir.c_str())) == NULL) {
					//cout << "Error(" << errno << ") opening " << dir << endl;
					//return errno;
			}
			int status;
			while ((dirp = readdir(dp)) != NULL) {
					status = stat(dirp->d_name, &statbuffer);
					if (status & attribFilter) { // https://pubs.opengroup.org/onlinepubs/7908799/xsh/sysstat.h.html
							if (fileFilter == "" || std::string(dirp->d_name).find(fileFilter) != std::string::npos) {
									files.push_back(std::string(dirp->d_name));
							}
					}
			}
			closedir(dp);
			return files;
	}
	 */






public: // template implementations

	/*!
	 * Return the name of the class used as T.
	 */
	template<class T> static std::string TypeOf() {
		std::string name = typeid (T).name();
		std::map<std::string, std::string>::iterator it = _S_TypeOf.find(name);
		if (it != _S_TypeOf.end()) {
			return (*it).second;
		} else {
			std::string newname(name);
			while (std::isdigit(newname[0])) {
				newname.erase(0, 1);
			}
			_S_TypeOf.insert(std::pair<std::string, std::string>(name, newname));
			return newname;
		}
	}

	/*!
	 * Every component or modeldatum has a unique ID for its class, but not unique for other classes. IDs are generated sequentially for each class.
	 */
	template<class T> static Util::identification GenerateNewIdOfType() {
		std::string objtype = Util::TypeOf<T>();
		std::map<std::string, Util::identification>::iterator it = Util::_S_lastIdOfType.find(objtype);
		if (it == Util::_S_lastIdOfType.end()) {
			// a new one. create the pair
			Util::_S_lastIdOfType.insert(std::pair<std::string, Util::identification>(objtype, 0));
			it = Util::_S_lastIdOfType.find(objtype);
		}
		Util::identification next = (*it).second;
		next++;
		(*it).second = next;
		return (*it).second;
	}

private:
	Util();
	virtual ~Util() = default;
};

//namespace\\}
#endif /* UTIL_H */

