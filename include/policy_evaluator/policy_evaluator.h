#ifndef POLICY_EVALUATOR_H
#define POLICY_EVALUATOR_H

#include <string>
#include <vector>
#include <map>

namespace policy_evaluator {

class Policy {
public:
  // Example: A collection of rules.  The exact structure will depend
  // on your policy language.
  struct Rule {
    std::string condition; // e.g., "age > 18"
    // ... other rule attributes ...
  }; 
  friend std::ostream& operator<<(std::ostream& os, const Rule& rule);

  std::vector<Rule> rules;
  // ... other policy attributes ...
  // Example: Add a rule.
  void AddRule(const Rule& rule) { rules.push_back(rule); }
};

class YamlPolicyEvaluator {
public:
  YamlPolicyEvaluator(const std::string& yaml_file_path);
  ~YamlPolicyEvaluator() = default;
  // Evaluate a given context against the loaded policy.
  bool Evaluate(const std::map<std::string, std::string>& context) const;
  // Load or reload the policy from the YAML file.
  bool EvaluateRule(const Policy::Rule& rule, const std::map<std::string, std::string>& context) const;
  bool LoadPolicy();
  // Get the loaded policy (useful for inspection/debugging).
  const Policy& GetPolicy() const;

private:
  std::string yaml_file_path_;
  Policy policy_;  // The parsed policy
  // Helper functions for parsing YAML and building the Policy object.
  // bool ParseYaml(const YAML::Node& node);
  // bool BuildPolicy(const YAML::Node& node);
  // Example helper function for evaluating a single rule.  You'll
  // likely need more of these, depending on the complexity of your
  // policy language.
  // bool EvaluateRule(const YAML::Node& rule, const std::map<std::string, std::string>& context) const;
  // ... other helper functions as needed ...

};

// Structure to represent a policy (you'll likely want to expand this)
} // namespace policy_evaluator


#endif // POLICY_EVALUATOR_H

