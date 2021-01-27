// -*- C++ -*-
/*!
 * @file  MapServerTesterTest.cpp
 * @brief MapServerTester RT-Component
 * @date $Date$
 *
 * $Id$
 */

#include "MapServerTesterTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* mapservertester_spec[] =
  {
    "implementation_id", "MapServerTesterTest",
    "type_name",         "MapServerTesterTest",
    "description",       "MapServerTester RT-Component",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Navigation",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
MapServerTesterTest::MapServerTesterTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sv_namePort("sv_name")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
MapServerTesterTest::~MapServerTesterTest()
{
}



RTC::ReturnCode_t MapServerTesterTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers

  // Set OutPort buffer

  // Set service provider to Ports
  m_sv_namePort.registerProvider("NAVIGATION_OccupancyGridMapServer", "NAVIGATION::OccupancyGridMapServer", m_NAVIGATION_OccupancyGridMapServer);

  // Set service consumers to Ports

  // Set CORBA Service Ports
  addPort(m_sv_namePort);

  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MapServerTesterTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t MapServerTesterTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MapServerTesterTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTesterTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void MapServerTesterTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(mapservertester_spec);
    manager->registerFactory(profile,
                             RTC::Create<MapServerTesterTest>,
                             RTC::Delete<MapServerTesterTest>);
  }

};


