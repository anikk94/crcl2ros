/*
* DISCLAIMER:
* This software was produced by the National Institute of Standards
* and Technology (NIST), an agency of the U.S. government, and by statute is
* not subject to copyright in the United States.  Recipients of this software
* assume all responsibility associated with its operation, modification,
* maintenance, and subsequent redistribution.
*
* See NIST Administration Manual 4.09.07 b and Appendix I.
*/
#ifndef GRIPPER_H
#define GRIPPER_H

#include <ros/ros.h>
#include <std_srvs/SetBool.h>

// application specific
#include <crclapp/Globals.h>

struct gzGripper
{

    gzGripper()
    {
    }

    int init(ros::NodeHandle *nh, std::string gzGripperTopic)
    {
        try {
            this->nh=nh;
            this->gzGripperTopic=gzGripperTopic;
            client = nh->serviceClient<std_srvs::SetBool>(gzGripperTopic);
            if (!client.exists())
                throw ros::InvalidNameException("Exception: invalid service name " + gzGripperTopic);
        }
        catch(ros::InvalidNameException &e)
        {
            throw e;
        }

        return 0;
    }

    int open()
    {
        std_srvs::SetBool srv;
        srv.request.data=0;
        if (!client.call(srv))
        {
            ROS_ERROR(Globals.format("Failed to call service %s open",gzGripperTopic.c_str()).c_str());
            return 1;
        }
        return 0;
    }
    int close()
    {
        std_srvs::SetBool srv;
        srv.request.data=1;
        if (!client.call(srv))
        {
            ROS_ERROR(Globals.format("Failed to call service %s close",gzGripperTopic.c_str()).c_str());
            return 1;
        }
        return 0;
    }
    ros::ServiceClient client;
    ros::NodeHandle *nh;
    std::string gzGripperTopic;

};



#endif // GRIPPER_H
