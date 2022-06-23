#ifndef _DEGREE_H_
#define _DEGREE_H_
#pragma once
#include <string>

using std::string;

/* Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE. */
enum DegreeProgram { undeclared, SECURITY, NETWORK, SOFTWARE };

/* Used for returning string instead of enum int */
static const std::string  degreeProgramNames[] = { "undeclared", "SECURITY", "NETWORK", "SOFTWARE" };
const string programNames(int degreeNameIndex);

#endif