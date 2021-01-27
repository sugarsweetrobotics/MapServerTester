// -*- C++ -*-
/*!
 * @file  MapServerTester.cpp
 * @brief MapServerTester RT-Component
 * @date $Date$
 *
 * $Id$
 */

#include "MapServerTester.h"
#include <opencv2/opencv.hpp>
// Module specification
// <rtc-template block="module_spec">
static const char* mapservertester_spec[] =
  {
    "implementation_id", "MapServerTester",
    "type_name",         "MapServerTester",
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
MapServerTester::MapServerTester(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sv_namePort("sv_name")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
MapServerTester::~MapServerTester()
{
}



RTC::ReturnCode_t MapServerTester::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers

  // Set OutPort buffer

  // Set service provider to Ports

  // Set service consumers to Ports
  m_sv_namePort.registerConsumer("NAVIGATION_OccupancyGridMapServer", "NAVIGATION::OccupancyGridMapServer", m_NAVIGATION_OccupancyGridMapServer);

  // Set CORBA Service Ports
  addPort(m_sv_namePort);

  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MapServerTester::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t MapServerTester::onExecute(RTC::UniqueId ec_id)
{

  std::cout << "[MapServerTester] Request Map?(y/n)" << std::endl;
  std::string buf;
  std::cin >> buf;
  if (buf.length() > 0 && buf[0] == 'y') {
    std::cout << "[MapServerTester] loading map..." << std::endl;    
    NAVIGATION::OccupancyGridMapRequestParam param;
    NAVIGATION::OccupancyGridMap_var map;
    auto ret = m_NAVIGATION_OccupancyGridMapServer->requestLocalMap(param, map);
    if (ret != NAVIGATION::MAP_RETVAL_OK) {
      std::cout << "[MapServerTester] failed to get map" << std::endl;
      return RTC::RTC_OK;
    }
    std::cout << "[MapServerTester] load ok." << std::endl;
    int col = map->config.sizeOfMap.w / map->config.sizeOfGrid.w;
    int row = map->config.sizeOfMap.l / map->config.sizeOfGrid.l;
    int typ = CV_8UC1; // grayscale
    cv::Mat img(row, col, typ);
    std::cout << "img(" << row << " x " << col << ")" << std::endl;
    for(int r = 0;r < row;r++) {
      for(int c = 0;c < col;c++) {
	img.at<uchar>(r, c, 0) = map->cells[r*col+c];
      }
    }
    cv::imwrite("output.png", img);
  } else {
    std::cout << "Invalid Input" << std::endl;

  }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t MapServerTester::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t MapServerTester::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void MapServerTesterInit(RTC::Manager* manager)
  {
    coil::Properties profile(mapservertester_spec);
    manager->registerFactory(profile,
                             RTC::Create<MapServerTester>,
                             RTC::Delete<MapServerTester>);
  }

};


