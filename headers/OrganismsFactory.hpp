#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Organism.hpp"

class OrganismsFactory {
   private:
    map<string, Organism* (*)(int, int, World&)> supportedOrganisms;
    template <typename T>
    static Organism* createInstance(int x, int y, World& worldRef) {
        return new T(x, y, worldRef);
    }

   public:
    vector<string> availableOrganisms;

    template <typename T>
    void registerOrganism(string organism_name) {
        supportedOrganisms[organism_name] = &createInstance<T>;
        availableOrganisms.push_back(organism_name);
    }

    Organism* create(string organism_name, int x, int y, World& worldRef) {
        auto organismType = supportedOrganisms.find(organism_name);

        if (organismType == supportedOrganisms.end()) {
            return nullptr;
        }

        return organismType->second(x, y, worldRef);
    }
};