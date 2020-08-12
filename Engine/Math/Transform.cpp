#include "pch.h"
#include "Transform.h"

namespace NC
{
	std::istream& NC::operator>>(std::istream& stream, Transform& transform)
	{
		stream >> transform.position;

		std::string line;
		std::getline(stream, line);
		transform.scale = stof(line);

		std::getline(stream, line);
		transform.angle = stof(line);
	
		return stream;
	}

	void Transform::Update()
	{
		Matrix33 mxScale;
		mxScale.Scale(scale);
		Matrix33 mxRotate;
		mxRotate.rotate(angle);
		Matrix33 mxTranslate;
		mxTranslate.Translate(position);

		Matrix33 mx;
		matrix = mxScale * mxRotate * mxTranslate;
	}

	void Transform::Update(const Matrix33& mx)
	{
		Update();
		matrix = matrix * mx;
	}

}

