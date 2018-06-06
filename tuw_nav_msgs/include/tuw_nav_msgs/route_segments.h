/***************************************************************************
 *   Software License Agreement (BSD License)                              *
 *   Copyright (C) 2016 by Markus Bader <markus.bader@tuwien.ac.at>        *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *   modification, are permitted provided that the following conditions    *
 *   are met:                                                              *
 *                                                                         *
 *   1. Redistributions of source code must retain the above copyright     *
 *      notice, this list of conditions and the following disclaimer.      *
 *   2. Redistributions in binary form must reproduce the above copyright  *
 *      notice, this list of conditions and the following disclaimer in    *
 *      the documentation and/or other materials provided with the         *
 *      distribution.                                                      *
 *   3. Neither the name of the copyright holder nor the names of its      *
 *      contributors may be used to endorse or promote products derived    *
 *      from this software without specific prior written permission.      *
 *                                                                         *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
 *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
 *   COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *
 *   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
 *   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY *
 *   WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           *
 *   POSSIBILITY OF SUCH DAMAGE.                                           *
 ***************************************************************************/


#ifndef TUW_NAV_MSGS_ROUTE_SEGMENTS_H
#define TUW_NAV_MSGS_ROUTE_SEGMENTS_H


//ROS
#include <tuw_nav_msgs/msg/route_segments.hpp>
#include <nav_msgs/msg/path.hpp>

namespace tuw {
namespace ros_msgs{
  
  class RouteSegments : public tuw_nav_msgs::msg::RouteSegments{
  public:
    RouteSegments();
    RouteSegments(size_t n);
    void set_ids(const std::vector<unsigned int> &id);
    void set_type(const std::vector<unsigned int> &type);
    void set_orientation(const std::vector<unsigned int> &orientation);
    void set_motion_type(const std::vector<unsigned int> &motion_type);
    void set_start(const std::vector<double> &x, const std::vector<double> &y, const std::vector<double> &theta);
    void set_end(const std::vector<double> &x, const std::vector<double> &y, const std::vector<double> &theta);
    void set_center(const std::vector<double> &x, const std::vector<double> &y, const std::vector<double> &theta);
    void set_level(const std::vector<int> &level);
    void convert(nav_msgs::msg::Path &path, double sample_distance) const;
  };
}
}

#endif // TUW_NAV_MSGS_ROUTE_SEGMENTS_H
