#include "policy_evaluator/policy_evaluator.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream> //for debugging, can remove later.

namespace policy_evaluator {

YamlPolicyEvaluator::YamlPolicyEvaluator(const std::string& yaml_file_path)
    : yaml_file_path_(yaml_file_path) {
  LoadPolicy(); // Load policy on object creation
}

bool YamlPolicyEvaluator::LoadPolicy() {
  std::ifstream file(yaml_file_path_);
  try {
      if (!file.is_open()) {
      // Handle file opening error.
        std::cout << "Error: Could not open file: " << yaml_file_path_ << std::endl;
        return false; // Or throw an exception  
      }
    }
    catch (const std::exception& e) {
      std::cout << e.what();
    }
     
    // --- Manual YAML Parsing (Simplified Example) ---
    //  This is where the bulk of your work will be if you're not using a library.
    //  You'll need to read the file line by line, parse the structure, and
    //  handle various YAML features (indentation, keys, values, lists, etc.).

    policy_.rules.clear(); // Clear any existing rules

    std::string line;
    bool inRulesSection = false;

    while (std::getline(file, line)) {
      std::cout<< line << std::endl;
        // Very basic parsing -- this needs to be MUCH more robust!
        if (line.find("rules:") != std::string::npos) {
            inRulesSection = true;
            continue; // Skip the "rules:" line itself
        }

        if (inRulesSection) {
            // Extremely simplified rule parsing (assuming "  - condition: ...")
            size_t conditionPos = line.find("condition:");
            if (conditionPos != std::string::npos) {
                std::string condition = line.substr(conditionPos + 10); // 10 = length of "condition:" + space

                // Trim whitespace (important!)
                condition.erase(0, condition.find_first_not_of(" \t"));
                condition.erase(condition.find_last_not_of(" \t") + 1);

                Policy::Rule newRule;
                newRule.condition = condition;
                policy_.AddRule(newRule);
            }
        }
    }

    file.close();
    return true;
}
bool YamlPolicyEvaluator::Evaluate(const std::map<std::string, std::string>& context) const {
     // Very basic evaluation logic (highly simplified example):
    // Iterate through the rules and check if *any* rule's condition is met.
    std::cout << "Test Evaluate()";
    for (const auto& rule : policy_.rules) {
        std::cout << rule;
        if (EvaluateRule(rule, context)) {
            std::cout << "Rule Evaluated!" << std::endl;
            return true; // Or whatever logic you want for handling multiple matching rules
        }
    }
    return false; // No rules matched
}

const Policy& YamlPolicyEvaluator::GetPolicy() const {
    return policy_;
}

bool YamlPolicyEvaluator::EvaluateRule(const Policy::Rule& rule, const std::map<std::string, std::string>& context) const
{
    // VERY basic example:  Simple string comparisons for conditions like "key=value"
    std::string condition = rule.condition;

    // Find the '=' sign.  This is super brittle and needs to be replaced
    // with a proper expression parser for real-world use!
    size_t equalsPos = condition.find('=');
    if (equalsPos == std::string::npos) {
        return false;  // Or throw an exception for invalid condition format
    }

    std::string key = condition.substr(0, equalsPos);
    std::string expectedValue = condition.substr(equalsPos + 1);

     // Trim whitespace (important!)
    key.erase(0, key.find_first_not_of(" \t"));
    key.erase(key.find_last_not_of(" \t") + 1);
    expectedValue.erase(0, expectedValue.find_first_not_of(" \t"));
    expectedValue.erase(expectedValue.find_last_not_of(" \t") + 1);

    // Check if the key exists in the context and if the value matches.
    auto it = context.find(key);
    if (it != context.end() && it->second == expectedValue) {
        return true;
    }

    return false;
}


std::ostream& operator<<(std::ostream& os, const Policy::Rule& rule){
  os << "Condition: " << rule.condition; 
  return os;
}

} // namespace policy evaluator 
