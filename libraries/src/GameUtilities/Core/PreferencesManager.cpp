#include "GameUtilities/Core/PreferencesManager.h"
#include "GameUtilities/Core/Thread.h"
#include "GameUtilities/Core/RAIIStream.h"
#include <fstream>
#include <thread>
#include <cassert>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>

namespace GU
{
  namespace Core
  {
    class PreferencesManager::Impl
    {
        public:
            Impl(const GU::Core::String &path);
      //#ifdef MULTITHREAD
    	std::mutex m_fileLock;
      //#endif
    	GU::Core::String m_path;
    };


    PreferencesManager::Impl::Impl(const GU::Core::String &path):
    m_path(path)
    {

    }


    /*********************************************************************************//**
    *	@brief: Constructor
    * @param: path is the full path to the preferences file
    *************************************************************************************/
    PreferencesManager::PreferencesManager(const GU::Core::String &path):
    pimpl(new PreferencesManager::Impl(path))
    {

    }


    /*********************************************************************************//**
    *	@brief: This function writes an int value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const int &data)
    {
        assert(pimpl != nullptr);
        std::ofstream fileStream;
        GU::Core::RAIIStream<std::ofstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);
        fileStream << name << ":" << data << std::endl;
    }


    /*********************************************************************************//**
    *	@brief: This function writes a float value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const float &data)
    {
        assert(pimpl != nullptr);
        std::ofstream fileStream;
        GU::Core::RAIIStream<std::ofstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);
        fileStream << name << ":" << data << std::endl;
    }


    /*********************************************************************************//**
    *	@brief: This function writes a GU::Core::String value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const GU::Core::String &data)
    {
        assert(pimpl != nullptr);
        std::ofstream fileStream;
        GU::Core::RAIIStream<std::ofstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);
        fileStream << name << ":" << data << std::endl;
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an int value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    int PreferencesManager::read(const GU::Core::String &name, const int &defaultValue)
    {
      assert(pimpl != nullptr);
      std::ifstream fileStream;
      GU::Core::RAIIStream<std::ifstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);
      std::string line;
      while(std::getline(fileStream, line))
      {
        std::stringstream ss(line);
        std::string id;
        getline(fileStream, line, ':');
        if(id == name.toStdString())
        {
          int data;
          ss >> data;
          return data;
        }
      }
      return defaultValue;
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an float value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    float PreferencesManager::read(const GU::Core::String &name, const float &defaultValue)
    {
      assert(pimpl != nullptr);
      std::ifstream fileStream;
      GU::Core::RAIIStream<std::ifstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);
      std::string line;
      while(std::getline(fileStream, line))
      {
        std::stringstream ss(line);
        std::string id;
        getline(fileStream, line, ':');
        if(id == name.toStdString())
        {
          float data;
          ss >> data;
          return data;
        }

      }
      return defaultValue;
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an GU::Core::String value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    GU::Core::String PreferencesManager::read(const GU::Core::String &name, const GU::Core::String &defaultValue)
    {
      assert(pimpl != nullptr);
      std::ifstream fileStream;
      GU::Core::RAIIStream<std::ifstream> s(fileStream, pimpl->m_path, pimpl->m_fileLock);

      std::string line;
      while(std::getline(fileStream, line))
      {
        std::stringstream ss(line);
        std::string id;
        getline(fileStream, line, ':');
        if(id == name.toStdString())
        {
          std::string data;
          ss >> data;
          return data;
        }

      }
      return defaultValue;
    }


    /*********************************************************************************//**
    *	@brief: Destructor
    *************************************************************************************/
    PreferencesManager::~PreferencesManager()
    {
        assert(pimpl != nullptr);
        if(pimpl != nullptr)
    	    delete pimpl;
    }
  }
}
