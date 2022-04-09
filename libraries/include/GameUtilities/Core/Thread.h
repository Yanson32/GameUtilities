#ifndef GAMEUTILITIES_THREAD_H
#define GAMEUTILIITES_THREAD_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/9/2022
* @description This file contains functions for thread safe programming
*************************************************************************************/
#include "core_export.h"
#include <iostream>
#include <mutex>

namespace GU
{
  namespace Core
  {
    /*********************************************************************************//**
    *	@brief: This function accesses std::iostream in a thread safe way. As long as you
    *         never access std::iostream without this function.
    * @param: data is the payload to be sent to std::iostream
    *************************************************************************************/
    template <class T>
    void ts_iostream(std::ostream &out, const T &data)
    {
      static std::mutex tempMutex;
      static std::lock_guard<std::mutex> lock(tempMutex);
      out << data << std::endl;
    }
  }
}
#endif
