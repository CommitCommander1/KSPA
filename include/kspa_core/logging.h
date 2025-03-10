#ifndef LOGGING_H
#define LOGGING_H
#include <string>
#include <sstream>
#include <iostream>

namespace kspa_core {
namespace logging {

enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL};

class Logger {
public:
  Logger(const string& filename);
  ~Logger(){ logFile.close(); }
  void logMessage(const std::string& message);
private:
  string leveltoString(LogLevel level);
}
}
#endif // !LOGGING_H
