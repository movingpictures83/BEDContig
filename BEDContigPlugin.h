#ifndef BEDContigPLUGIN_H
#define BEDContigPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class BEDContigPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "BEDContig";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
