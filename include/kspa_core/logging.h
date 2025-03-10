#ifndef LOGGING_H
#define LOGGING_H
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

namespace kspa_core {
namespace logging {

enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL};

class Logger {
public:
  Logger(const std::string& filename) : filename(filename);
  ~Logger(){  };
  void logMessage(const std::string& message);
private:
  std::string leveltoString(LogLevel level);
  std::ofstream logFile;
  std::string filename;
};
}
#endif // !LOGGING_H
