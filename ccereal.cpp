//Implementaion File for Cereal class.
#include "CCereal.h"//For Cereal class.
#include <iostream>//For iostream functions.
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>

#pragma warning(disable : 4996)

using namespace std;

ifstream fileIn("cereal.csv");
ofstream fileOut("cereal.txt", ios::app);

//Constructor definition
CCereal::CCereal()
{
	string line;
	fileIn.ignore(500, '\n');

	time_t now = time(0);
	tm* localtm = localtime(&now);
	fileOut << "\n\n" << endl;
	fileOut << "\n---------------------------Below record retrieved:  " << asctime(localtm) << "\n\n";

	fileOut << "|               Cereal Name               ";
	fileOut << "|MFR";
	fileOut << "|Type";
	fileOut << "|Calories";
	fileOut << "|Protein";
	fileOut << "|Fat";
	fileOut << "|Sodium";
	fileOut << "|Fiber";
	fileOut << "|Carbo";
	fileOut << "|Sugars";
	fileOut << "|Potass";
	fileOut << "|Vitamins";
	fileOut << "|Shelf";
	fileOut << "|Weight";
	fileOut << "|Cups";
	fileOut << "|Rating |\n";
	fileOut << "---------------------------------------------------------------------------------------------------------------------------------------------\n";

	while (getline(fileIn, line, '\n'))
		{
			char szTok[500];
			char* pTok = NULL;
			char* pStr = szTok;
			strcpy(szTok, line.c_str());
			pTok = strtok_s(pStr, ",\n", &pStr);

			string delimiter = ",";
			size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			string token;
			vector<string> res;

			while ((pos_end = line.find(delimiter, pos_start)) != string::npos)
			{
				token = line.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}

			res.push_back(line.substr(pos_start));

			string strName = res[0];
			char chMfr = res[1][0];
			char chType = res[2][0];
			int nCalories = atoi(res[3].c_str());
			int nProtein = atoi(res[4].c_str());
			int nFat = atoi(res[5].c_str());
			int nSodium = atoi(res[6].c_str());
			int nFiber = atoi(res[7].c_str());
			int nCarbo = atoi(res[8].c_str());
			int nSugars = atoi(res[9].c_str());
			int nPotass = atoi(res[10].c_str());
			int nVitamins = atoi(res[11].c_str());
			int nShelf = atoi(res[12].c_str());
			float fWeight = atof(res[13].c_str());
			float fCups = atof(res[14].c_str());
			float fRating = atof(res[15].c_str());

			char* pName = new char[strName.size()];
			strcpy(pName, strName.c_str());

			setName(pName);
			setMfr(chMfr);
			setType(chType);
			setCalories(nCalories);
			setProtein(nProtein);
			setFat(nFat);
			setSodium(nSodium);
			setFiber(nFiber);
			setCarbo(nCarbo);
			setSugars(nSugars);
			setPotass(nPotass);
			setVitamins(nVitamins);
			setShelf(nShelf);
			setWeight(fWeight);
			setCups(fCups);
			setRating(fRating);

			Output();

			while (pTok)
			{
				pTok = strtok_s(pStr, ",\n", &pStr);
			}
		}
		fileOut << "\n\n---------------------------END OF RECORD RETRIEVED ON " << asctime(localtm) << "\n";
		cout << "End of File!\n";
		fileIn.close();
		fileOut.close();
		exit(EXIT_SUCCESS);
}//End constructor

void CCereal::setName(char* pName)
{
	strcpy(m_szBuff, pName);
}

void CCereal::setMfr(char c)
{
	m_chMfr = c;
}

void CCereal::setType(char c)
{
	m_chType = c;
}

void CCereal::setCalories(int n)
{
	m_nCalories = n;
}

void CCereal::setProtein(int n)
{
	m_nProtein = n;
}

void CCereal::setFat(int n)
{
	m_nFat = n;
}

void CCereal::setSodium(int n)
{
	m_nSodium = n;
}

void CCereal::setFiber(int n)
{
	m_nFiber = n;
}

void CCereal::setCarbo(int n)
{
	m_nCarbo = n;
}

void CCereal::setSugars(int n)
{
	m_nSugars = n;
}

void CCereal::setPotass(int n)
{
	m_nPotass = n;
}

void CCereal::setVitamins(int n)
{
	m_nVitamins = n;
}

void CCereal::setShelf(int n)
{
	m_nShelf = n;
}

void CCereal::setWeight(float f)
{
	m_fWeight = f;
}

void CCereal::setCups(float f)
{
	m_fCups = f;
}

void CCereal::setRating(float f)
{
	m_fRating = f;
}

//*********************************************
//OUTPUT FUNCTION DEFINITION                  *
//*********************************************
void CCereal::Output() const
{
	const int fieldSz = 40;//The largest print field which is 2 spaces larger than the largest name. Using this number for formatting.
	string nameLen = CCereal::getName();
	int size = nameLen.size();//Determining the size of the Cereal name for formatting.
	int prtSpc = (fieldSz - size) / 2;//To print spaces before and after the name.

	cout <<  "| ";
	for (int i = 0; i < prtSpc; i++)
	{
		cout << " ";
	}
	cout << CCereal::getName();
	for (int i = 0; i < prtSpc; i++)
	{
		cout << " ";
	}
	if (size % 2 != 0)
	{
		cout << " ";
	}
	cout << "|" << setw(3) << CCereal::getMfr();
	cout <<  "|" << setw(4) << CCereal::getType();
    cout << "|" << setw(8) << CCereal::getCalories();
    cout << "|" << setw(7) << CCereal::getProtein();
    cout << "|"  << setw(3) << CCereal::getFat();
    cout << "|" << setw(6) << CCereal::getSodium();
    cout << "|" << setw(5) << CCereal::getFiber();
    cout << "|" << setw(5) << CCereal::getCarbo();
    cout << "|" << setw(6) << CCereal::getSugars();
    cout << "|" << setw(6) << CCereal::getPotass();
    cout << "|" << setw(8) << CCereal::getVitamins();
    cout << "|" << setw(5) << CCereal::getShelf();
    cout << "|" << setw(6) << CCereal::getWeight();
    cout << "|" << setw(4) << CCereal::getCups();
    cout << "|" << setw(7) << CCereal::getRating() << " |\n";
	cout << "=============================================================================================================================================\n";

	fileOut << "| ";
	for (int i = 0; i < prtSpc; i++)
	{
		fileOut << " ";
	}
	fileOut << nameLen;
	for (int i = 0; i < prtSpc; i++)
	{
		fileOut << " ";
	}
	if (size % 2 != 0)
	{
		fileOut << " ";
	}
	fileOut << "|" << setw(3) << CCereal::getMfr();
	fileOut << "|" << setw(4) << CCereal::getType();
	fileOut << "|" << setw(8) << CCereal::getCalories();
	fileOut << "|" << setw(7) << CCereal::getProtein();
	fileOut << "|" << setw(3) << CCereal::getFat();
	fileOut << "|" << setw(6) << CCereal::getSodium();
	fileOut << "|" << setw(5) << CCereal::getFiber();
	fileOut << "|" << setw(5) << CCereal::getCarbo();
	fileOut << "|" << setw(6) << CCereal::getSugars();
	fileOut << "|" << setw(6) << CCereal::getPotass();
	fileOut << "|" << setw(8) << CCereal::getVitamins();
	fileOut << "|" << setw(5) << CCereal::getShelf();
	fileOut << "|" << setw(6) << CCereal::getWeight();
	fileOut << "|" << setw(4) << CCereal::getCups();
	fileOut << "|" << setw(7) << CCereal::getRating() << " |\n";
	fileOut << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
}