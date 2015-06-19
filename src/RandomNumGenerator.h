/* 
 * File:   RandomNumGenerator.h
 * Author: amit
 *
 * Created on August 28, 2014, 4:17 AM
 */

#ifndef RANDOMNUMGENERATOR_H
#define	RANDOMNUMGENERATOR_H

#include <random>

class RandomNumGenerator {
public:
    unsigned getMozLifeSpan();
    unsigned getHumanTrajectory();
    unsigned getHumanImmunity();
    unsigned getRandomNum(unsigned);
    unsigned intialInfDaysLeft();
    double getEventProbability();
    unsigned getMozLatencyDays();
    unsigned getHuLatencyDays();
    unsigned getMozRestDays();
    unsigned getMozNextLoc(unsigned);
    void setSeed(unsigned);
    std::string toString() const;
    RandomNumGenerator(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
    RandomNumGenerator();
    RandomNumGenerator(const RandomNumGenerator& orig);
    virtual ~RandomNumGenerator();
private:
    unsigned seed;
    std::mt19937 gen;
    unsigned huLatencyLo;
    unsigned huLatencyHi;
    unsigned huImmunity;
    unsigned mozLifeLo;
    unsigned mozLifeHi;
    unsigned mozLatencyLo;
    unsigned mozLatencyHi;
    unsigned mozRestLo;
    unsigned mozRestHi;
};

#endif	/* RANDOMNUMGENERATOR_H */

