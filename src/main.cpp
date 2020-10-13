#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include"planetInfo.h"

std::vector<std::string> planetsToString(std::string file);

class Planet
{
        std::string m_planetName;
        double m_planetSize;
        double m_planetDistanceToSun;
        double m_planetRadius;
    public:
        void getInfo(std::string info)
        {
            std::string delimiter = ":";

            size_t pos{info.find(delimiter)};
            std::string token;
            token = info.substr(0,pos);
            info.erase(0, pos + delimiter.length());
            if(token == "Name")
                m_planetName = info;
            else if(token == "Size")
                m_planetSize = std::stod(info);
            else if(token == "Distance")
                m_planetDistanceToSun = std::stod(info);
            else if(token == "Radius")
                m_planetRadius = std::stod(info);
        }

        std::string getName(){return m_planetName;}
        double getSize(){return m_planetSize;}
        double getDistanceToSun(){return m_planetDistanceToSun;}
        double getRadius(){return m_planetRadius;}
};

std::vector<Planet> rawInfoToPlanet(std::vector<std::string> planets)
{
    std::vector<Planet> tmpPlanet;
    for(int i = 0; i < (int)planets.size(); i++)
    {
        Planet tmp;
        tmpPlanet.push_back(tmp);
//        std::cout << planets[i] << std::endl;
        planets[i].erase(0,1);
        std::string delimiter = ";";
        size_t pos{0};
        std::string token;
        while((pos = planets[i].find(delimiter)) != std::string::npos)
        {
            token = planets[i].substr(0, pos);
 //           std::cout << token << '\n';
            tmpPlanet[i].getInfo(token);
            planets[i].erase(0,pos+delimiter.length());
        }
    }
    return tmpPlanet;
}


int main()
{
    std::vector<std::string> planets{planetsToString("planets.txt")};
    std::vector<Planet> test{rawInfoToPlanet(planets)};
    for(int i =0; i < (int)test.size(); i++)
    {
        std::cout << test[i].getName() << '\n';
        std::cout << test[i].getSize() << '\n';
        std::cout << test[i].getDistanceToSun() << '\n';
        std::cout << test[i].getRadius() <<'\n';
    }
    /*
    std::vector<Planet> tmpPlanet;
    for(int i = 0;i<planets.size(); i++)
    {
        Planet tmp;
        tmpPlanet.push_back(tmp);
    }
    //Planet 0: Earth parse

    Planet earth;

    std::cout << planets[0] << std::endl;
    planets[0].erase(0,1);
    std::string delimiter = ";";
    size_t pos{0};
    std::string token;
    while((pos = planets[0].find(delimiter)) != std::string::npos)
    {
        token = planets[0].substr(0, pos);
        std::cout << token << '\n';
        earth.getInfo(token);
        planets[0].erase(0,pos+delimiter.length());
    }
    std::cout << earth.getName() << std::endl;
    std::cout << earth.getSize() << std::endl;
    //Planet 1: Mars parse
    std::cout << "\n\n\n";
    std::cout << planets[1];
    */
}
std::vector<std::string> planetsToString(std::string file)
{
    std::ifstream inf{file};
    if(!inf)
    {
        std::cerr << "No file";
        std::vector<std::string> a;
        return a;
    }
    int x{0};
    std::vector<std::string> planets;
    planets.push_back("");
    while(inf)
    {
        std::string strInput;
        std::getline(inf, strInput);
        planets[x]+= strInput;

        if(strInput == "}")
        {
            x++;
            planets.push_back("");
        }
    }
    return planets;
}
