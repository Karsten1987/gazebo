/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2008, Willow Garage, Inc.
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
*   * Neither the name of the Willow Garage nor the names of its
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
*********************************************************************/

/* Author: Nate Koenig, John Hsu */

#ifndef URDF_PARSER_HH
#define URDF_PARSER_HH

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>
#include <libxml/parser.h>

#include "sdf/interface/sensor.hh"
#include "sdf/interface/link.hh"
#include "sdf/interface/model.hh"
#include "sdf/interface/world.hh"
#include "sdf/interface/joint.hh"
#include "sdf/interface/plugin.hh"
#include "sdf/interface/pose.hh"

namespace sdf
{
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Sensor> &_sensor);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<SensorType> &_sensor_type);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Contact> &_contact);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Camera> &_sensor);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Ray> &_sensor);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Material> &_material);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Inertial> &_inertial);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Collision> &_collision);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Sphere> &_sphere);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Box> &_box);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Cylinder> &_cylinder);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Mesh> &_mesh);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Link> &_link);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Visual> &_visual);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<JointDynamics> &_jointDynamics);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<JointLimits> &_jointLimits);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Joint> &_joint);

  bool initXml(xmlNodePtr _config, boost::shared_ptr<Joint> &_joint);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Geometry> &_geom);
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Plugin> &_plugin);

  /// \brief Load Model given a filename
  bool initFile(const std::string &_filename, boost::shared_ptr<Model> &_model);

 /// \brief Load Model from a XML-string
  bool initString(const std::string &_xmlstring, boost::shared_ptr<Model> &_model);

  /// \brief Load Model from TiXMLDocument
  bool initDoc(xmlDocPtr _xml, boost::shared_ptr<Model> &_model);

  /// \brief Load Model from TiXMLElement
  bool initXml(xmlNodePtr _xml, boost::shared_ptr<Model> &_model);


  /// \brief Load world given a filename
  bool initFile(const std::string &_filename, 
                boost::shared_ptr<World> &_world);

  /// \brief Load world from a XML-string
  bool initString(const std::string &_xmlstring, 
                  boost::shared_ptr<World> &_world);

   /// \brief Load World from TiXMLDocument
  bool initDoc(xmlDocPtr _xml, boost::shared_ptr<World> &_world);

   /// \brief Load Model from TiXMLElement
  bool initXml(xmlNodePtr _xml, boost::shared_ptr<World> &_world);

  /// scene
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Scene> &_scene);
  
  /// physics
  bool initXml(xmlNodePtr _config, boost::shared_ptr<Physics> &_physics);

  /// OpenDynamicsEngine
  bool initXml(xmlNodePtr _config, boost::shared_ptr<OpenDynamicsEngine> &_open_dynamics_engine);

  /// Pose
  bool InitXml(xmlNodePtr _xml, Pose &_pose);


  bool getBoolFromStr(std::string _key, bool &_value, 
                      bool _default, bool _required);
 
  bool getDoubleFromStr(const std::string &_key, double &_value,
                        double _default, bool _required);
 
  bool getIntFromStr(const std::string &_key, int &_value);
    
  bool getUIntFromStr(const std::string &_str, unsigned int &_value);

  bool getPlugins(xmlNodePtr pluginXml, std::map<std::string, 
                  boost::shared_ptr<Plugin> > &plugins);
}

#endif
