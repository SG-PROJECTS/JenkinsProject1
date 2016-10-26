#ifndef INCLUDED_VECTOR_H
#define INCLUDED_VECTOR_H

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	Vector3 operator+(const Vector3& rhs) const
	{
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vector3 operator*(float s) const
	{
		return Vector3(x * s, y * s, z * s);
	}
};

float DistanceSquare(Vector3& a, Vector3& b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z);
}

void RemoveDuplicates(std::vector<Vector3>& nodes, float delta)
{
	float deltaSqr = delta * delta;
	for (int i = nodes.size() - 1; i > 0; --i)
	{
		for (int j = (i - 1); j >= 0; --j)
		{
			if (DistanceSquare(nodes[i], nodes[j]) < deltaSqr)
			{				
				nodes.erase(nodes.begin() + i);
				break;
			}
		}
	}
}

#endif // #ifndef INCLUDED_VECTOR_H