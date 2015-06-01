/**
 * This file was automatically created with "create_c++_header.sh".
 * Do not edit manually.
 */
#pragma once
#include "../../colormap.h"

namespace colormap
{
namespace MATLAB
{

class Spring : public Colormap
{
private:
	class Wrapper : public WrapperBase
	{
	public:
		#include "../../../../shaders/MATLAB_spring.frag"
	};

public:
	Color getColor(float x) const override
	{
		Wrapper w;
		vec4 c = w.colormap(x);
		Color result;
		result.r = std::max(0.0f, std::min(1.0f, c.r));
		result.g = std::max(0.0f, std::min(1.0f, c.g));
		result.b = std::max(0.0f, std::min(1.0f, c.b));
		result.a = std::max(0.0f, std::min(1.0f, c.a));
		return result;
	}

	std::string getTitle() const override
	{
		return std::string("spring");
	}

	std::string getCategory() const override
	{
		return std::string("MATLAB");
	}

	std::string getSource() const override
	{
		return std::string(
			"vec4 colormap(float x) {\n"
			"    return vec4(1.0, clamp(x, 0.0, 1.0), clamp(1.0 - x, 0.0, 1.0), 1.0);\n"
			"}\n"
		);
	}
};

} // namespace MATLAB
} // namespace colormap