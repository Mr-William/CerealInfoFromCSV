//Specification file for CCereal Class

#ifndef CCEREAL_H
#define CCEREAL_H

#include <fstream>

//CCereal Class declaration
class CCereal
{
    private:
		char m_szBuff[40];
        char m_chMfr;
        char m_chType;
        int m_nCalories;
        int m_nProtein;
        int m_nFat;
        int m_nSodium;
        int m_nFiber;
        int m_nCarbo;
        int m_nSugars;
        int m_nPotass;
        int m_nVitamins;
        int m_nShelf;
        float  m_fWeight;
        float m_fCups;
        float m_fRating;

    public:
        
        CCereal();//Constructor
		void setName(char* pStr);
        void setMfr(char c);
        void setType(char c);
        void setCalories(int n);
        void setProtein(int n);
        void setFat(int n);
        void setSodium(int n);
        void setFiber(int n);
        void setCarbo(int n);
        void setSugars(int n);
        void setPotass(int n);
        void setVitamins(int n);
        void setShelf(int n);
        void setWeight(float f);
        void setCups(float f);
        void setRating(float f);
        void Output() const;

        const char* getName() const
        { return m_szBuff; }
       
        char getMfr() const
        { return m_chMfr; }
       
        char getType()const
        { return m_chType; }
       
        int getCalories() const
        { return m_nCalories; }
       
        int getProtein() const
        { return m_nProtein; }
       
        int getFat() const
        { return m_nFat; }
       
        int getSodium() const
        { return m_nSodium; }
       
        int getFiber() const
        { return m_nSodium; }
       
        int getCarbo() const
        { return m_nCarbo; }
       
        int getSugars() const
        { return m_nSugars; }
       
        int getPotass() const
        { return m_nPotass; }
       
        int getVitamins() const
        { return m_nVitamins; }
       
        int getShelf() const
        { return m_nShelf; }
       
        float getWeight() const
        { return m_fWeight; }
       
        float getCups() const
         { return m_fCups; }
        
        float getRating() const
         { return m_fRating; }
};

#endif