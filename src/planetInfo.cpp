#include<iostream>
#include"planetInfo.h"

class planetInfo
{
    private:
        std::string m_planetName;
        long m_planetSize;
        long m_planetDistanceToSun;
        long m_planetRadius;
    public:
        planetInfo()
        {
        }
        void getInfo(std::string info)
        {
            std::string delimiter = ":";

            size_t pos{0};
            std::string token;
            token = info.substr(0,pos);
            info.erase(0, pos + delimiter.length());
            if(token == "Name")
                m_planetName = info;
        }
        std::string planetName()
        {
            return m_planetName;
        }

};
