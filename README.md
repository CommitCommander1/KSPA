# KSPA - Kubernetes Security Posture Assessor
1

A powerful tool for assessing the security posture of Kubernetes clusters based on declarative policies, with support for CIS benchmarks.

## Overview

KSPA is a high-performance security assessment tool built primarily in C++ with strategic Rust components for performance-critical operations. It enables DevOps teams and security professionals to evaluate Kubernetes cluster configurations against defined security policies and industry best practices.

## Features

- 🔍 Comprehensive security posture assessment
- 📋 CIS benchmark compliance checking
- 🚀 High-performance policy evaluation engine
- 📝 Declarative YAML-based policy definitions
- 📊 Detailed Markdown report generation
- 🔄 Resource relationship analysis
- 💾 Efficient resource caching

## Installation

```bash
# Installation instructions will be added once the project reaches MVP
```

## Quick Start

```bash
# Basic usage
kspa --policy-file /path/to/policy.yaml --kubeconfig /path/to/kubeconfig

# With specific context
kspa --policy-file /path/to/policy.yaml --context my-cluster-context

# Generate detailed report
kspa --policy-file /path/to/policy.yaml --output-format markdown --output report.md
```

## Policy Definition

Policies are defined in YAML format. Example:

```yaml
apiVersion: kspa/v1
kind: Policy
metadata:
  name: pod-security-policy
spec:
  resourceType: Pod
  rules:
    - field: spec.containers[*].securityContext.privileged
      operator: equals
      value: false
```

## Supported Resources

Initial release supports:
- Pods
- Namespaces
- Deployments
- Services
- RBAC configurations

## Architecture

KSPA consists of several core components:
- Policy Parser (C++)
- Kubernetes Resource Discovery (C++)
- Policy Evaluator (C++ with selective Rust components)
- Report Generator (C++)
- CLI Interface (C++)

## Building from Source

```bash
# Build instructions will be added during development
```

## Contributing

We welcome contributions! Please see our [Contributing Guidelines](CONTRIBUTING.md) for details.

### Development Prerequisites

- C++ compiler (C++17 or later)
- Rust compiler (for performance-critical components)
- Kubernetes cluster for testing
- CMake
- yaml-cpp library
- Kubernetes C++ client library

## Roadmap

- [x] Project planning and architecture design
- [ ] MVP with basic policy evaluation
- [ ] CIS benchmark mapping integration
- [ ] Extended resource type support
- [ ] Automated remediation capabilities
- [ ] CI/CD pipeline integration
- [ ] Web UI development

## Future Enhancements

- Automated remediation features
- CI/CD pipeline integration
- Web-based user interface
- Plugin system for custom checks
- Extended CIS benchmark coverage

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Kubernetes community
- CIS Benchmark contributors
- Open source security tools that inspired this project

## Contact

For bugs, features, or questions, please [open an issue](../../issues).

1
