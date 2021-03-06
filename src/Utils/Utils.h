#ifndef MARKETONWHEELS_UTILS_H
#define MARKETONWHEELS_UTILS_H

#include <cmath>
#include <iomanip>
#include "../Position/Position.h"

#define EARTH_RADIUS 6371  //radius of Earth in km
#define SPACE 15
#define ID 5

/**
 * Util function that converts angle in degrees to radians
 * @param degree the degree to be converted
 * @return the angle converted in radians
 */
long double convertToRadians(const long double degree);

/**
 * Calculates the distance between two Positions, both representing different latitudes and longitudes in a map
 * @param position1 the first position to compare with
 * @param position2 the second position to compare with
 * @return the distance between the two positions, using haversine formula
 */
long double distanceBetweenTwoPos(Position position1, Position position2);


#endif //MARKETONWHEELS_UTILS_H
