#include "kspa_core/logging.h"
#include <iostream>

namespace kspa_core {
namespace logging {

void logMessage(const std::string& message) {
  std::cout<< "[KSPA Core Log]: " << message << std::endl;
}
}
}
