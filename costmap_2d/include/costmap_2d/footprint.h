/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, 2013, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Eitan Marder-Eppstein
 *         David V. Lu!!
 *********************************************************************/
#ifndef _FOOTPRINT_HELPER_H
#define _FOOTPRINT_HELPER_H

#include <ros/ros.h>
#include <geometry_msgs/Polygon.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point32.h>

namespace costmap_2d
{

void calculateMinAndMaxDistances(const geometry_msgs::Polygon& footprint, double& min_dist, double& max_dist);
geometry_msgs::Point              toPoint      (geometry_msgs::Point32 pt);
geometry_msgs::Point32            toPoint32    (geometry_msgs::Point   pt);
geometry_msgs::Polygon            toPolygon    (std::vector<geometry_msgs::Point> pts);
std::vector<geometry_msgs::Point> toPointVector(geometry_msgs::Polygon polygon);

/** @brief Footprint publisher.
 *
 * When instantiated, this class reads the "footprint" parameter and
 * publishes it as a Polygon message. */
class RobotFootprintManager
{
public:
  RobotFootprintManager(ros::NodeHandle node, std::string param_name = "footprint");

private:
  void loadFromString(std::string footprint_string);
  std::string loadFromArray(XmlRpc::XmlRpcValue footprint_value);

  ros::Publisher publisher;
  geometry_msgs::Polygon footprint;
};

} // end namespace costmap_2d

#endif
