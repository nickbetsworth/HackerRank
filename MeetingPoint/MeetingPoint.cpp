#include <iostream>
#include <algorithm>
#include <vector>

//https://www.hackerrank.com/challenges/meeting-point

typedef long long num_type;
struct Point {
	num_type x;
	num_type y;

	Point& operator+=(const Point& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
};

struct Point_Double {
	double x;
	double y;
};

// Calculates the centroid of all given points
Point_Double calculate_centroid(const std::vector<Point>& points) {
	Point centroid = { 0, 0 };

	for (Point p : points) {
		centroid += p;
	}

	double d_centroid_x = static_cast<double>(centroid.x) / points.size();
	double d_centroid_y = static_cast<double>(centroid.y) / points.size();

	return { d_centroid_x, d_centroid_y };
}

// Finds the house nearest to the given centroid
Point calculate_nearest_house(const Point_Double& centroid, const std::vector<Point>& points) {
	Point nearest_point;
	double dist_nearest_point = std::numeric_limits<double>::max(); // Stores the distance the nearest point was
	for (Point p : points) {
		// Calculate the squared euclidean distance between point p and centroid
		double dist = pow(centroid.x - p.x, 2) + pow(centroid.y - p.y, 2);
		if (dist < dist_nearest_point) {
			nearest_point = p;
			dist_nearest_point = dist;
		}
	}

	return nearest_point;
}

num_type get_combined_travel_time(const Point& centroid, const std::vector<Point>& points) {
	num_type travel_time = 0;
	for (Point p : points) {
		// Uses Chebyshev distance, as diagonals are allowed
		travel_time += std::max(abs(centroid.x - p.x), abs(centroid.y - p.y));
	}

	return travel_time;
}

num_type get_minimal_travel_time(const std::vector<Point>& points) {
	// Calculate the centroid of all points
	Point_Double centroid = calculate_centroid(points);
	// Find the house nearest to the centroid
	Point nearest_house = calculate_nearest_house(centroid, points);
	// Find the distance from each house to the central house
	return get_combined_travel_time(nearest_house, points);
}

int main() {
	unsigned num_houses;
	std::cin >> num_houses;

	std::vector<Point> houses;
	int x, y;
	for (int i = 0; i < num_houses; i++) {
		std::cin >> x >> y;
		houses.push_back({ x, y });
	}

	std::cout << get_minimal_travel_time(houses) << std::endl;

	return 0;
}