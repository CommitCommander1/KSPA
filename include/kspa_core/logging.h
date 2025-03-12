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
  Logger(const std::string& filename)
  {
    std::cout << filename;
    try {
      logFile.open(filename, std::ios::app);
    }
    catch (const std::exception& ex) {
      std::cout << ex.what();
    }

    if (!logFile.is_open()){
      std::cerr << "Error Opening logger file" << std::endl;
    }
  }
  ~Logger(){ logFile.close();}
  void logMessage(const std::string& message );
  void log(LogLevel level, const std::string& message);
private:
  std::string leveltoString(LogLevel level)
  {
    switch (level) {
      case DEBUG:
        return "DEBUG";
      case INFO:
        return "INFO";
      case WARNING:
        return "WARNING";
      case ERROR:
        return "ERROR";
      case CRITICAL:
        return "CRITICAL";
      default:
        return "UNKOWN";
        break;
    }
  }
  std::ofstream logFile;
    };
  }
}
#endif // !LOGGING_H
