#include "ProvinceBuildings.h"
#include "ParserHelpers.h"

EU4::ProvinceBuildings::ProvinceBuildings(std::istream& theStream)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
}

void EU4::ProvinceBuildings::registerKeys()
{
	registerRegex("[a-zA-Z0-9_]+", [this](const std::string& building, std::istream& theStream) {
		commonItems::ignoreItem(building, theStream);
		buildings.insert(building);
	});
	registerRegex(commonItems::catchallRegex, commonItems::ignoreItem);
}
