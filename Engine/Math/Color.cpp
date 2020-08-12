#include "pch.h"
#include "Color.h"

const NC::Color NC::Color::white{ 1, 1, 1 };
const NC::Color NC::Color::red{ 1, 0, 0 };
const NC::Color NC::Color::green{ 0, 1, 0 };
const NC::Color NC::Color::blue{ 0, 0, 1 };
const NC::Color NC::Color::yellow{ 1, 1, 0 };

namespace NC
{
std::istream& NC::operator>>(std::istream& stream, Color& c)
{
	std::string line;
	std::getline(stream, line);

	if (line.find("{") != std::string::npos)
	{
		std::string cr = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		c.r = std::stof(cr);

		line = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);

		std::string cg = line.substr(0, line.find(","));
		c.g = std::stof(cg);

		std::string cb = line.substr(line.find(",") + 1, line.find("}") - 1);
		c.b = std::stof(cb);
	}

	return stream;
}


}

