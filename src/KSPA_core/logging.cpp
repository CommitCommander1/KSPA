#include "kspa_core/logging.h"
#include <iostream>
#include <ctime>

namespace kspa_core {
namespace logging {

void Logger::logMessage(const std::string& message) {
  std::cout<< "[KSPA Core Log]: " << message << std::endl;
}
void Logger::log(LogLevel level, const std::string& message) {
  // Get current time stamp
  time_t timestamp;
  time(&timestamp);
  std::cout << ctime(&timestamp);
  // Create Log entry
  std::ostringstream log_entry;
  log_entry << Logger::leveltoString(level) << ": " << ctime(&timestamp) << &timestamp << std::endl;
  std::cout << log_entry.str();
  // output to console
  // output to log file
    if (logFile.is_open()) {
      logFile << log_entry.str();
      logFile.flush();
  }
}
}     
}
