#ifndef __UTIL_H__
#define __UTIL_H__

#include <iostream>
#include <vector>
#include <random>
#include <time.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Random {
public:
	Random() : m_engine(static_cast<unsigned int>(time(NULL))) {}

	int getRandomi(int min, int max) {
		std::uniform_int_distribution<> distr(min, max);
		return distr(m_engine);
	}
private:
	std::mt19937 m_engine;
};

class Array2D {
public:
	Array2D(unsigned int columns, unsigned int rows, int value) : m_columns(columns), m_rows(rows) {
		m_data.resize(rows, std::vector<int>(columns, value));
	}

	const unsigned int& getColumns() const {
		return m_columns;
	}

	const unsigned int& getRows() const {
		return m_rows;
	}

	std::vector<int>& operator[](int row) {
		return m_data[row];
	}

	const std::vector<int>& operator[](int row) const {
		return m_data[row];
	}
private:
	unsigned int m_columns, m_rows;

	std::vector<std::vector<int>> m_data;
};

static bool vec3AreEqualIntegers(const glm::vec3& v1, const glm::vec3& v2) {
	if (static_cast<int>(v1.x) == static_cast<int>(v2.x) &&
		// Player height
		static_cast<int>(v1.y) == static_cast<int>(v2.y) &&
		static_cast<int>(v1.z) == static_cast<int>(v2.z)) {
		return true;
	}

	return false;
}

static void printVec3(const glm::vec3& v) {
	std::cout << static_cast<int>(v.x) << ", " 
			  << static_cast<int>(v.y) << ", " 
			  << static_cast<int>(v.z) << std::endl;
}

#endif