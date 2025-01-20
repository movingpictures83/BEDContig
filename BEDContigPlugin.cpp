#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BEDContigPlugin.h"

void BEDContigPlugin::input(std::string file) {
   readParameterFile(file);
}

void BEDContigPlugin::run() {}

void BEDContigPlugin::output(std::string file) {
       	std::string outputfile = file;

	std::string myCommand = "while read -r line; do grep \"${line}\" "+PluginManager::addPrefix(myParameters["bedfile"])+" > "+outputfile+"/\"${line}\"_output.bed; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BEDContigPlugin> BEDContigPluginProxy = PluginProxy<BEDContigPlugin>("BEDContig", PluginManager::getInstance());
