#pragma once

#include "pathplanner/lib/PathPlannerTrajectory.h"
#include <units/velocity.h>
#include <units/acceleration.h>
#include <wpi/raw_istream.h>
#include <string>
#include <vector>

namespace pathplanner{
    class PathPlanner {
        public:
            static double resolution;

            static pathplanner::PathPlannerTrajectory loadPath(std::string name, units::meters_per_second_t maxVel, units::meters_per_second_squared_t maxAccel, bool reversed);

            static pathplanner::PathPlannerTrajectory loadPathFromString(std::string value, units::meters_per_second_t maxVel, units::meters_per_second_squared_t maxAccel, bool reversed);

            static pathplanner::PathPlannerTrajectory loadPath(std::string name, units::meters_per_second_t maxVel, units::meters_per_second_squared_t maxAccel){
                return PathPlanner::loadPath(name, maxVel, maxAccel, false);
            }

            static pathplanner::PathPlannerTrajectory loadPathFromString(std::string value, units::meters_per_second_t maxVel, units::meters_per_second_squared_t maxAccel){
                return PathPlanner::loadPathFromString(value, maxVel, maxAccel, false);
            }

        private:
            static pathplanner::PathPlannerTrajectory loadPathFromIstream(wpi::raw_istream &istream, units::meters_per_second_t maxVel, units::meters_per_second_squared_t maxAccel, bool reversed);

            static pathplanner::PathPlannerTrajectory joinPaths(std::vector<pathplanner::PathPlannerTrajectory> paths);
    };
}