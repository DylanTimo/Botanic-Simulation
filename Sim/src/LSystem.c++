#include "LSystem.h"

LSystem::LSystem(const std::string& axiom, const std::unordered_map<char, std::string>& rules)
    : axiom(axiom), rules(rules) {}

void LSystem::setAxiom(const std::string& newAxiom) {
    axiom = newAxiom;
}

void LSystem::addRule(char symbol, const std::string& rule) {
    rules[symbol] = rule;
}

void LSystem::clearRules() {
    rules.clear();
}

std::string LSystem::generate(int iterations) const {
    std::string current = axiom;

    for (int i = 0; i < iterations; ++i) {
        std::string next = "";
        for (char c : current) {
            // If a replacement rule exists for this character, apply it; otherwise keep it
            auto it = rules.find(c);
            if (it != rules.end()) {
                next += it->second;
            } else {
                next += c;
            }
        }
        current = next;
    }

    return current;
}