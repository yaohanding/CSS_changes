#ifndef SIMULATION_H
#define SIMULATION_H

#include <map>
#include <set>
#include <memory>
#include <fstream>
#include "Location.h"
#include "Mosquito.h"
#include "RandomNumGenerator.h"
#include "Report.h"
#include "Recruitment.h"


class Simulation {
public:
    RandomNumGenerator rGen;
    RandomNumGenerator rGenInf;

    Simulation(std::string);
    Simulation();
    Simulation(const Simulation& orig);
    std::string readInputs();
    void readHumanFile(std::string);
    void readInitialInfectionsFile(std::string);
    void readSimControlFile(std::string);
    void readLocationFile(std::string);
    void readDiseaseRatesFile();
    void readVaccineProfilesFile();
    void readVaccinationGroupsFile();
    void setLocNeighborhood(double);
    void simEngine();
    void humanDynamics();
    void tests();
    void mosquitoDynamics();
    void generateMosquitoes();
    unsigned setInitialInfection(double, unsigned);
    void simulate();
    void updatePop();
    void selectEligibleTrialParticipants();
    bool checkAgeToVaccinate(int age_);
    virtual ~Simulation();
private:
    std::vector<std::string>getParamsLine(std::string);
    int parseInteger(std::string);
    std::string parseString(std::string);
    double parseDouble(std::string);
    void parseVector(std::string line, std::vector<int> *);

    std::map <std::string,std::unique_ptr<Location>> locations;
    std::multimap<std::string,std::unique_ptr<Mosquito>> mosquitoes;
    std::multimap<std::string,std::unique_ptr<Human>> humans;
    std::map<unsigned,double> VE_pos;
    std::map<unsigned,double> VE_neg;
    std::map<unsigned,double> halflife;
    std::map<unsigned,double> disRates;
    std::map<unsigned,double> hospRates;
    std::map<int,int> ageGroups;
    std::map<unsigned, vProfile> vaccines;

    unsigned currentDay;
    unsigned numDays;
    std::string trajectoryFile;
    std::string configLine;
    std::string locationFile;
    std::string vaccineProfilesFile;
    std::string vaccinationStrategy;
    std::string reportsFile;
    std::string diseaseRatesFile;
    std::string vaccinationGroupsFile;
    bool routineVaccination;
    bool catchupFlag;
    bool trialVaccination;
    bool randomTrial;
    int vaccineID;
    unsigned vaccineDay;
    unsigned vaccineAge;
    double vaccineCoverage;
    Report outputReport;
    Recruitment recruitmentTrial;
    std::string outputFile;
    std::string outputPopFile;
    std::string outputPrevacFile;
    std::string simName;
    unsigned rSeed;
    unsigned rSeedInf;
    std::string outputPath;
    double deathRate;
    unsigned humanInfectionDays;
    unsigned huImm;
    double mlife;
    double mbite;
    double emergeFactor;
    double biteProbablity;
    double mozInfectiousness;   
    double mozMoveProbability;
    double ForceOfImportation;
    double ForceOfImportationTrial;
    double selfReportProb;
    unsigned year;
    //    int seroposAtVax[101], seronegAtVax[101], disAtVax[101], hospAtVax[101];

    std::ofstream out;
    std::ofstream outpop;
    std::ofstream outprevac;
};

#endif  /* SIMULATION_H */
