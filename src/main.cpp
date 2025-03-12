#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include "policy_evaluator/policy_evaluator.h"
#include "kspa/kspa.h" // 
#include "kspa_core/logging.h" // 


int main(int argc, char* argv[]) {
    try {
        policy_evaluator::YamlPolicyEvaluator evaluator("../test/rules.yml");
        std::map<std::string, std::string> context1 = {
            {"age", "25"},
            {"country", "USA"},
            {"is_member", "false"}
        };
        std::filesystem::path cwd = std::filesystem::current_path();
        std::filesystem::path log_dir = cwd / "log";
        std::filesystem::path log_file = log_dir / "main.log";
        if (!std::filesystem::exists(log_dir)) {
          std::filesystem::create_directories(log_dir);
    }
        std::cout << "Test Case 1: " << (evaluator.Evaluate(context1) ) << std::endl;
        kspa_core::logging::Logger main_log(log_file.string());
        main_log.log(kspa_core::logging::DEBUG, "Main func");
        return 0; // Indicate successful execution

    } catch (const std::exception& ex) {
        // Catch any unhandled standard exceptions
        std::cerr << "Unhandled exception in main: " << ex.what() << std::endl;
        return 1; // Indicate an error
    } catch (...) {
        // Catch any other types of exceptions (for robust error handling)
        std::cerr << "Unhandled unknown exception in main." << std::endl;
        return 1; // Indicate an error
    }
}
