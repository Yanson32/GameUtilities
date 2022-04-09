#ifndef GAMEUTILITIES_RAIISTREAM_H
#define GAMEUTILITIES_RAIISTREAM_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/9/2022
* @description This class is used to open a file in a thread safe way. Using
*              RAII to  make sure the file is closed before the end of the current
*              scope.
*************************************************************************************/
#include <thread>
#include "GameUtilities/Core/String.h"
#include <sstream>

namespace GU
{
  namespace Core
  {
    template <class T>
    class RAIIStream
    {
      public:
        /*********************************************************************************//**
        *	@brief: Constructor
        * @param: stream is the file stream to be used.
        * @param: path is the path to the file.
        * @param: mute is the mutex used to lock the file.
        *************************************************************************************/
        RAIIStream(T &stream, const GU::Core::String &path, std::mutex &mute);


        /*********************************************************************************//**
        *	@brief: Destructor
        *************************************************************************************/
        virtual ~RAIIStream();
      private:
        T &m_stream;
        std::mutex &m_mute;
    };


    /*********************************************************************************//**
    *	@brief: Constructor
    * @param: stream is the file stream to be used.
    * @param: path is the path to the file.
    * @param: mute is the mutex used to lock the file.
    *************************************************************************************/
    template <class T>
    RAIIStream<T>::RAIIStream(T &stream, const GU::Core::String &path, std::mutex &mute):
    m_stream(stream),
    m_mute(mute)
    {
      m_mute.lock();
      m_stream.open(path.toStdString());
      if(!m_stream)
      {
        std::stringstream ss;
        ss << "The stream could not be opened ";
        ss << path.toStdString();
        ts_iostream(std::cerr, ss.str());
      }
    }


    /*********************************************************************************//**
    *	@brief: Destructor
    *************************************************************************************/
    template <class T>
    RAIIStream<T>::~RAIIStream()
    {
      m_stream.close();
      m_mute.unlock();
    }

  }
}
#endif
