#pragma once

#include <string>
#include <unordered_map>

class LSystem {
public:
    LSystem() = default;
    LSystem(const std::string& axiom, const std::unordered_map<char, std::string>& rules);

    // Setters for dynamic runtime modifications
    void setAxiom(const std::string& newAxiom);
    void addRule(char symbol, const std::string& rule);
    void clearRules();

    // Generates the expanded L-System string after a given number of iterations
    std::string generate(int iterations) const;

private:
    std::string axiom;
    std::unordered_map<char, std::string> rules;
};